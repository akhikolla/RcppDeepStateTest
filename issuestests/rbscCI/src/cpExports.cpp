#include <Rcpp.h>
using namespace Rcpp;

#include "cp.h"

// [[Rcpp::export(".cpCI")]]
NumericVector cpCI(int n_tot, int n_suc, double conf) {
  
  ClopperPearson cp( n_tot, 1 - conf );
  Interval lim = cp.limits().limits[ n_suc ];
  
  // return value
  NumericVector ci(2);
  ci[0] = lim.lower;
  ci[1] = lim.upper;
  return(ci);
}
