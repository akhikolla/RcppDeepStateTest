#include <Rcpp.h>

using namespace Rcpp;

NumericVector Cgammatr(int n, double A, double B, NumericVector range);

NumericVector CgenerateU_root(NumericVector prodTau, int N, double SIGMAS, NumericMatrix Z);
