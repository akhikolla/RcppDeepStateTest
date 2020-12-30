#include <Rcpp.h>

using namespace Rcpp;

NumericVector Cexptr(int n, double lambda, NumericVector range);

NumericVector CgenerateTau_root(NumericVector U, NumericVector t, double a, int end);
