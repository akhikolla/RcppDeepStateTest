#include <Rcpp.h>
using namespace Rcpp;

#include "bsc.h"
#include "cp.h"

// [[Rcpp::export(".bscCI")]]
NumericVector bscCI(int n_tot, int n_suc, double conf) {

  // obtain init value of CI from cp
  ClopperPearson cp( n_tot, 1 - conf );

  // refine CI by bsc
  BlythStillCasella bsc( cp.limits() );
  Interval lim = bsc.limits( n_suc );

  // return value
  NumericVector ci(2);
  ci[0] = lim.lower;
  ci[1] = lim.upper;
  return(ci);
}
