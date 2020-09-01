#ifndef PARENT_SET_H
#define PARENT_SET_H

#include <Rcpp.h>

Rcpp::DataFrame parent_i(Rcpp::IntegerMatrix matrix, int h, int tw, int proc,
                         /*double s=0,*/ int n, int ss,
                         Rcpp::IntegerVector kind_vec,
                         Rcpp::IntegerVector bit_pos_vec);
Rcpp::DataFrame parent(Rcpp::NumericMatrix, int, int, int);

#endif // PARENT_SET_H
