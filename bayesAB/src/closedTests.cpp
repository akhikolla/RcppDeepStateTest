#include <Rcpp.h>
using namespace Rcpp;

double lbeta(double a, double b) {
  return lgamma(a) + lgamma(b) - lgamma(a + b);
}

// [[Rcpp::export]]
double PoissonClosed_(double alpha_1, double beta_1, double alpha_2, double beta_2) {
  double total = 0;
  for(int i = 0; i < alpha_1; i++) {
    double lt = i * log(beta_1) +
                alpha_2 * log(beta_2) -
                (i + alpha_2) * log(beta_1 + beta_2) -
                log(i + alpha_2) - 
                lbeta(i + 1, alpha_2);
    total += exp(lt);
  }
  return total;
}

// [[Rcpp::export]]
double BernoulliClosed_(double alpha_1, double beta_1, double alpha_2, double beta_2) {
  double total = 0;
  for(int i = 0; i < alpha_2; i++) {
    double lt = lbeta(alpha_1 + i, beta_1 + beta_2) -
                log(beta_2 + i) -
                lbeta(1 + i, beta_2) -
                lbeta(alpha_1, beta_1);
    total += exp(lt);
  }
  return 1 - total;
}
