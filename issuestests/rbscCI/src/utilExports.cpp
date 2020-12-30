#include <Rcpp.h>
using namespace Rcpp;

#include "util.h"

// [[Rcpp::export(".bicoln_raw")]]
double bicoln_raw_export(const unsigned int N, const unsigned int k) {
  
  return(bicoln_raw(N,k));
  
}

// [[Rcpp::export(".bicoln_mem")]]
double bicoln_mem(const unsigned int N, const unsigned int k) {
  
  return(bicoln(N,k));
  
}
