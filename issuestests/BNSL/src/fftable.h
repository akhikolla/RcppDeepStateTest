#ifndef FFTABLE_H
#define FFTABLE_H

#include <Rcpp.h>

Rcpp::IntegerMatrix normalize_table(Rcpp::NumericMatrix& matrix,
                                    Rcpp::IntegerVector& kind_vec,
                                    Rcpp::IntegerVector& bit_pos_vec);
Rcpp::IntegerMatrix fftable_i(Rcpp::IntegerMatrix matrix, int w, int h,
                              uint64_t children, Rcpp::IntegerVector bit_pos_vec);
Rcpp::IntegerMatrix fftable(Rcpp::NumericMatrix, int);

#endif // FFTABLE_H
