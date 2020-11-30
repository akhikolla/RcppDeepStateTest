#ifndef GC_H
#define GC_H

#include <Rcpp.h>

double gc(int, double);
double gc_all(Rcpp::IntegerVector, double);

#endif // GC_H
