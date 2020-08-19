#include <Rcpp.h>
using namespace Rcpp;

//' Calculate likelihood curve of frequency estimates for a dual-alpha or
//' dual-beta TCR clone
//'
//' @param est Clonal frequency estimate
//' @param err Mean drop error rate
//' @param numb_cells A vector of the distinct sample sizes, i.e. the number of
//'    cells per well
//' @param numb_wells A vector with the number of wells with the distinct
//'    sample sizes
//' @param numb_sample A vector with the number of wells of the sample size of
//'    the same position of \code{numb_cells} that contains both alpha and the
//'    beta chain of the clone (for dual-alpha clones) or both beta and the
//'    alpha chain of the clone (for dual-beta clones)
//'
//' @return A numeric with the negative log likelihood
// [[Rcpp::export]]
double likelihood_dual(double est, double err, NumericVector numb_wells, NumericVector numb_cells, NumericVector numb_sample)
{
  double obj = 0;            // value of the likelihood objective function
  int n = numb_wells.size(); // number of wells with the clones in each column

  for (int i = 0; i < n; i++) {
    double appear = numb_wells[i];      // number of wells in column w/ clone
    double sample_size = numb_cells[i]; // sample size per well in column
    double p_none = 0;                  // prob of not seeing clone in well

    for (int j = 0; j < sample_size; j++) {
      int k = j + 1;
      p_none += (3 * pow(err, k) - 3 * pow(err, 2*k) + pow(err, 3*k)) *
        R::choose(sample_size, k) * pow(est, k) *
        pow((1 - est), (sample_size - k));
    }
    p_none += pow((1 - est), sample_size);
    p_none = -appear * log(1 - p_none) - (numb_sample[i] - appear) * log(p_none);

    obj = obj + p_none;
  } // end for - i
  return obj;
}
