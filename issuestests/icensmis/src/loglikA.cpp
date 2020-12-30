#include <Rcpp.h>
using namespace Rcpp;

// parameterization type A
// parm[j] is change in cumulative incidence in time period j
// parm[j] = log(S[j]) - log(S[j+1]), where S[0] = 1
// This paramerization is inspired by representing survival function as exp(-cumulative hazard)

// [[Rcpp::export]]
double loglikA0(NumericVector parm, NumericMatrix Dm) {
  int nsub = Dm.nrow(), J = Dm.ncol() - 1;
  double temp, templik, result = 0;
  for (int i = 0; i < nsub; i++) {
    templik = Dm(i, 0);
    temp = 0;
    for (int j = 0; j < J; j++) {
      temp += parm[j];
      templik += Dm(i, j+1)*exp(-temp);
    }
    result += log(templik);
  }
  return -result;
}

// [[Rcpp::export]]
NumericVector gradlikA0(NumericVector parm, NumericMatrix Dm) {
  int nsub = Dm.nrow(), J = Dm.ncol() - 1, i, j;
  NumericVector Dparm(J), result(J);
  double temp, templik, likj;
  for (i = 0; i < nsub; i++) {
    templik = Dm(i, 0);
    temp = 0;
    Dparm.fill(0);
    for (j = 0; j < J; j++) {
      temp += parm[j];
      likj = Dm(i, j+1)*exp(-temp);
      templik += likj;
      for (int j1 = 0; j1 <= j; j1++) Dparm[j1] += likj;
    }
    for (j = 0; j < J; j++) result[j] += Dparm[j]/templik;   
  }
  return result;
}

// [[Rcpp::export]]
double loglikA(NumericVector parm, NumericMatrix Dm, NumericMatrix Xmat) {
  int nbeta = Xmat.ncol(), nsub = Dm.nrow(), J = Dm.ncol() - 1, i, j, k;
  NumericVector lamb(J), beta(nbeta);
  double b, temp, templik, result = 0;
  for (i = 0; i < J; i++) lamb[i] = parm[i];
  for (i = 0; i < nbeta; i++) beta[i] = parm[J + i];
  for (i = 0; i < nsub; i++) {
    templik = Dm(i, 0);
    b = 0;
    for (k = 0; k < nbeta; k++) b += beta[k]*Xmat(i, k);
    b = exp(b);
    temp = 0;
    for (j = 0; j < J; j++) {
      temp += lamb[j]*b;
      templik += Dm(i, j+1)*exp(-temp);
    }
    result += log(templik);
  }
  return -result;
}

// [[Rcpp::export]]
NumericVector gradlikA(NumericVector parm, NumericMatrix Dm, NumericMatrix Xmat) {
  int nbeta = Xmat.ncol(), nsub = Dm.nrow(), J = Dm.ncol() - 1, i, j, k;
  NumericVector lamb(J), beta(nbeta), Dlamb(J), Dbeta(nbeta);
  NumericVector result(J + nbeta);
  double b, temp, templik, likj;
  for (i = 0; i < J; i++) lamb[i] = parm[i];
  for (i = 0; i < nbeta; i++) beta[i] = parm[J + i];
  for ( i = 0; i < nsub; i++) {
    templik = Dm(i, 0);
    b = 0;
    for (k = 0; k < nbeta; k++) b += beta[k]*Xmat(i, k);
    b = exp(b);
    temp = 0;
    Dlamb.fill(0);
    Dbeta.fill(0);
    for (j = 0; j < J; j++) {
      temp += lamb[j]*b;
      likj = Dm(i, j+1)*exp(-temp);
      templik += likj;
      for (int j1 = 0; j1 <= j; j1++) Dlamb[j1] += likj*b;
      for (k = 0; k < nbeta; k++) Dbeta[k] += likj*temp*Xmat(i, k);
    }
    for (j = 0; j < J; j++) result[j] += Dlamb[j]/templik;
    for (j = 0; j < nbeta; j++) result[J + j] += Dbeta[j]/templik;    
  }
  return result;
}

// [[Rcpp::export]]
double loglikTA(NumericVector parm, NumericMatrix Dm, NumericMatrix TXmat) {
  int nbeta = TXmat.ncol(), nsub = Dm.nrow(), J = Dm.ncol() - 1, i, j, k;
  NumericVector lamb(J), beta(nbeta), surv(J);
  double delta, temp, templik, result = 0;
  for (i = 0; i < J; i++) lamb[i] = parm[i];
  for (i = 0; i < nbeta; i++) beta[i] = parm[J + i];
  for (i = 0; i < nsub; i++) {
      surv.fill(0);
      temp = 0;
      for (j = 0; j < J; j++) {
        delta = 0;
        for (k = 0; k < nbeta; k++) delta += beta[k]*TXmat(i*(J+1) + j, k);
        temp += lamb[j]*exp(delta);
        surv[j] = temp;
      }
      templik = Dm(i, 0);
      for (k = 0; k < J; k++) templik += Dm(i, k+1)*exp(-surv[k]);
      result += log(templik);    
  }
  return -result;
}

// [[Rcpp::export]]
NumericVector gradlikTA(NumericVector parm, NumericMatrix Dm, NumericMatrix TXmat) {
  int nbeta = TXmat.ncol(), nsub = Dm.nrow(), J = Dm.ncol() - 1, i, j, k;
  NumericVector lamb(J), beta(nbeta), Dlamb(J), Dbeta(nbeta);
  NumericVector result(parm.size());
  NumericVector b(J), tempbeta(nbeta);
  double temp, templik, likj;
  for (i = 0; i < J; i++) lamb[i] = parm[i];
  for (i = 0; i < nbeta; i++) beta[i] = parm[J + i];
  for (i = 0; i < nsub; i++) {
    b.fill(0);
    Dlamb.fill(0);
    Dbeta.fill(0);
    tempbeta.fill(0);
    temp = 0;
    templik = Dm(i, 0);
    for (j = 0; j < J; j++) {
      for (k = 0; k < nbeta; k++) b[j] += beta[k]*TXmat(i*(J+1) + j, k);
      b[j] = exp(b[j]);
      temp += lamb[j]*b[j];
      likj = Dm(i, j+1)*exp(-temp);
      templik += likj;
      for (int j1 = 0; j1 <= j; j1++) Dlamb[j1] += likj*b[j1];
      for (k = 0; k < nbeta; k++) {
        tempbeta[k] += lamb[j]*b[j]*TXmat(i*(J+1) + j, k);
        Dbeta[k] += likj*tempbeta[k];
      }
    }
    for (j = 0; j < J; j++) result[j] += Dlamb[j]/templik;
    for (j = 0; j < nbeta; j++) result[J + j] += Dbeta[j]/templik;
  }
  return result;  
}
