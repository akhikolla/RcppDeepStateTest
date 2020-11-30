#include <Rcpp.h>
using namespace Rcpp;

// parameterization type C
// parm[0] is log(-log(S[0])) corresponding to first visit time
// parm[j] is log(-log(S[j])) - log(-log(S[j-1])) corresponding to change
//   in log(-log(S)) in that time period
// This is inspired by representing survival function as exp(-exp(lambda + beta*Z))

// [[Rcpp::export]]
double loglikC0(NumericVector parm, NumericMatrix Dm) {
  int nsub = Dm.nrow(), J = Dm.ncol() - 1, i, j;
  double result = 0, temp, templik;
  for (i = 0; i < nsub; i++) {
    templik = Dm(i, 0);
    temp = 0;
    for (j = 0; j < J; j++) {
      temp += parm[j];  
    	templik += Dm(i, j+1)*exp(-exp(temp));
  	}
  	result += log(templik);
  }
  return -result;   
}

// [[Rcpp::export]]
NumericVector gradlikC0(NumericVector parm, NumericMatrix Dm) {
  int nsub = Dm.nrow(), J = Dm.ncol() - 1, i, j;
  NumericVector result(J), Deriv(J);
  double temp, templik, likj;
  for (i = 0; i < nsub; i++) {
    templik = Dm(i, 0);
    temp = 0;
    Deriv.fill(0);
  	for (j = 0; j < J; j++) {
  	  temp += parm[j];
      likj = Dm(i, j+1)*exp(-exp(temp));
      templik += likj;
      for (int k = 0; k <= j; k++) Deriv[k] += likj*exp(temp);
  	}
    for (j = 0; j < J; j++) result[j] += Deriv[j]/templik;
  }
  return result;
}

// [[Rcpp::export]]
double loglikC(NumericVector parm, NumericMatrix Dm, NumericMatrix Xmat) {
  int nsub = Dm.nrow(), J = Dm.ncol() - 1, nbeta = Xmat.ncol(), i, j, k;
  double result = 0, temp, templik, b;
  NumericVector lamb(J), beta(nbeta);
  for (i = 0; i < J; i++) lamb[i] = parm[i];
  for (i = 0; i < nbeta; i++) beta[i] = parm[J + i];  
  for (i = 0; i < nsub; i++) {
    templik = Dm(i, 0);
    b = 0;
    for (k = 0; k < nbeta; k++) b += Xmat(i, k)*beta[k];
    temp = b;
    for (j = 0; j < J; j++) {
      temp += parm[j];  
      templik += Dm(i, j+1)*exp(-exp(temp));
  	}
  	result += log(templik);
  }
  return -result;   
}

// [[Rcpp::export]]
NumericVector gradlikC(NumericVector parm, NumericMatrix Dm, NumericMatrix Xmat) {
  int nsub = Dm.nrow(), J = Dm.ncol() - 1, nbeta = Xmat.ncol(), i, j, k;
  double temp, templik, b, likj;
  NumericVector lamb(J), beta(nbeta), Dlamb(J), Dbeta(nbeta), result(J + nbeta);
  for (i = 0; i < J; i++) lamb[i] = parm[i];
  for (i = 0; i < nbeta; i++) beta[i] = parm[J + i]; 
  for (i = 0; i < nsub; i++) {
    templik = Dm(i, 0);
    b = 0;
    for (k = 0; k < nbeta; k++) b += Xmat(i, k)*beta[k];
    temp = b;
    Dlamb.fill(0);
    Dbeta.fill(0);
    for (j = 0; j < J; j++) {
  	  temp += parm[j];
      likj = Dm(i, j+1)*exp(-exp(temp));
      templik += likj;
      for (k = 0; k <= j; k++) Dlamb[k] += likj*exp(temp);
      for (k = 0; k < nbeta; k++) Dbeta[k] += likj*exp(temp)*Xmat(i, k);
  	}
    for (j = 0; j < J; j++) result[j] += Dlamb[j]/templik;
    for (j = 0; j < nbeta; j++) result[J + j] += Dbeta[j]/templik;
  }
  return result;
}
