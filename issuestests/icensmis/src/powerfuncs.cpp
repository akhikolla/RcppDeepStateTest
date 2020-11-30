#include <Rcpp.h>
using namespace Rcpp;

int pow(int base, int exp) {
  int result = 1;
  while (exp > 0) {
    result = result * base;
    exp -= 1;
  }
  return result;
}

double sprob(int result, bool occur, double phi1, double phi0) {
  if (result == 0) {
    if (occur) {
      return 1 - phi1;
    } else {
      return phi0;
    }
  } else if (result == 1) {
    if (occur) {
      return phi1;
    } else {
      return 1 - phi0;
    }
  } else {
    return 1;
  }
}

IntegerVector convert1(int n, IntegerVector modv) {
  int J = modv.size(), i;
  IntegerVector result(J);
  for (i = 0; i < J; i++) {
    result[i] = n / modv[i];
    n = n % modv[i];
  }
  return result;
}

IntegerVector convert2(int n, int J) {
  int i;
  IntegerVector result(J);
  if (n < J) {
    result[n] = 1; 
    for (i = n + 1; i < J; i++) {
      result[i] = 2;
    }
  }
  return result;
}

IntegerVector convert3(int n, int J) {
  int i, p = int(log2(double(n+1)));
  int k = (n+1) % pow(2, p);
  IntegerVector result(J), modv(p);
  for (i = 0; i < p; i++) {
      modv[i] = pow(2, p - 1 - i);
   }
  for (i = 0; i < p; i++) {
    result[i] = 2*(k / modv[i]);
    k = k % modv[i];
  }
  if (p < J) {
    result[p] = 1;
    for (i = p + 1; i < J; i++) {
      result[i] = 2;
    }
  }  
  return result;
}

double missprob(IntegerVector result, NumericVector pmiss) {
  int J = result.size(), i=0;
  double prob = 1;
  for (i = 0; i<J; i++) {
    if (result[i] == 2) {
      prob *= pmiss[i];
    } else {
      prob *= 1 - pmiss[i];
    }
  }
  return prob;
}

double missprobntfp(IntegerVector result, NumericVector pmiss) {
  int J = result.size(), i=0;
  double prob = 1;
  for (i = 0; i<J; i++) {
    if (result[i] == 2) {
      prob *= pmiss[i];
    } else {
      prob *= 1 - pmiss[i];
    }
    if (result[i] == 1) break;
  }
  return prob;
}

IntegerVector copyvec(IntegerVector x, int end) {
  IntegerVector y(end + 1);
  for (int i = 0; i <= end; i++) y[i] = x[i];
  return y;
}

NumericVector copyvec(NumericVector x, int end) {
  NumericVector y(end + 1);
  for (int i = 0; i <= end; i++) y[i] = x[i];
  return y;
}

double missprobcensor(IntegerVector result, NumericVector pmiss, NumericVector censor) {
  int J = result.size(), i = J - 1;
  double prob = 0, p;
  IntegerVector subresult;
  NumericVector subpmiss;
  prob += (1 - sum(censor)) * missprob(result, pmiss);
  while (result[i] == 2) {
    p = censor[i];
    i -= 1;
    subresult = copyvec(result, i);
    subpmiss = copyvec(pmiss, i);
    prob += p * missprob(subresult, subpmiss);
  }
  return prob;
}

double missprobntfpcensor(IntegerVector result, NumericVector pmiss, NumericVector censor) {
  int J = result.size(), i = J - 1;
  double prob = 0, p;
  IntegerVector subresult;
  NumericVector subpmiss;
  prob += (1 - sum(censor)) * missprobntfp(result, pmiss);
  while (result[i] == 2) {
    p = censor[i];
    i -= 1;
    subresult = copyvec(result, i);
    subpmiss = copyvec(pmiss, i);
    prob += p * missprobntfp(subresult, subpmiss);
  }
  return prob;
}

NumericVector convlik(IntegerVector result, double phi1, double phi0) {
  int J = result.size();
  int i, k;
  NumericVector temp(J+1);
  for (i = 0; i < J+1; i++) {
     temp[i] = 1;
     for (k = 0; k <i; k++) {
       temp[i] *= sprob(result[k], 0, phi1, phi0);
     }
     for (k = i; k < J; k++) {
       temp[i] *= sprob(result[k], 1, phi1, phi0);
     }
  } 
  return temp;
}

// [[Rcpp::export]]
NumericMatrix powerdmat1(double phi1, double phi0, int J, double negpred) {
   int i, j, nsub = pow(2, J);
   IntegerVector modv(J), result(J);
   NumericMatrix Cm(nsub, J+1), Dm(nsub, J+1);   
   for (i = 0; i < J; i++) {
     modv[i] = pow(2, J - 1 - i);
   }
   for (i = 0; i < nsub; i++) {
     result = convert1(i, modv);
     Cm(i, _) = convlik(result, phi1, phi0);
   }        
   for (i = 0; i < nsub; i++) {
     Dm(i, 0) = Cm(i, 0);
     for (j = 1; j < J+1; j++) {
     Dm(i, j) = negpred*(Cm(i, j) - Cm(i, j-1));
     }
   }
   return Dm;
}

// [[Rcpp::export]]
List powerdmat2(double phi1, double phi0, int J, double negpred, NumericVector pmiss, NumericVector censor) {
   int i, j, nsub = pow(3, J);
   IntegerVector modv(J), result(J);
   NumericMatrix Cm(nsub, J+1), Dm(nsub, J+1); 
   NumericVector prob(nsub);  
   for (i = 0; i < J; i++) {
     modv[i] = pow(3, J - 1 - i);
   }
   for (i = 0; i < nsub; i++) {
     result = convert1(i, modv);
     prob[i] = missprobcensor(result, pmiss, censor);
     Cm(i, _) = convlik(result, phi1, phi0);
   }        
   for (i = 0; i < nsub; i++) {
     Dm(i, 0) = Cm(i, 0);
     for (j = 1; j < J+1; j++) {
     Dm(i, j) = negpred*(Cm(i, j) - Cm(i, j-1));
     }
   }
   return List::create(Dm, prob);
}

// [[Rcpp::export]]
NumericMatrix powerdmat3(double phi1, double phi0, int J, double negpred) {
   int i, j, nsub = J+1;
   IntegerVector result(J);
   NumericMatrix Cm(nsub, J+1), Dm(nsub, J+1);  
   for (i = 0; i < nsub; i++) {
     result = convert2(i, J);
     Cm(i, _) = convlik(result, phi1, phi0);
   }        
   for (i = 0; i < nsub; i++) {
     Dm(i, 0) = Cm(i, 0);
     for (j = 1; j < J+1; j++) {
     Dm(i, j) = negpred*(Cm(i, j) - Cm(i, j-1));
     }
   }
   return Dm;
}

// [[Rcpp::export]]
List powerdmat4(double phi1, double phi0, int J, double negpred, NumericVector pmiss, NumericVector censor) {
   int i, j, nsub = pow(2, J+1) - 1;
   IntegerVector result(J);
   NumericMatrix Cm(nsub, J+1), Dm(nsub, J+1); 
   NumericVector prob(nsub); 
   for (i = 0; i < nsub; i++) {
     result = convert3(i, J);
     prob[i] = missprobntfpcensor(result, pmiss, censor);
     Cm(i, _) = convlik(result, phi1, phi0);
   }        
   for (i = 0; i < nsub; i++) {
     Dm(i, 0) = Cm(i, 0);
     for (j = 1; j < J+1; j++) {
     Dm(i, j) = negpred*(Cm(i, j) - Cm(i, j-1));
     }
   }
   return List::create(Dm, prob);
}
