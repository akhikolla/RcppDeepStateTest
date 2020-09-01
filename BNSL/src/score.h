#ifndef SCORE_H
#define SCORE_H

#include <Rcpp.h>

double Bayes_score(Rcpp::IntegerMatrix, int, int, double, int, int);
double quotient_Jeffreys_score(Rcpp::IntegerMatrix, int, double, int);
double Jeffreys_score(Rcpp::IntegerMatrix, int);
double MDL_score(Rcpp::IntegerMatrix, int, double, int);
double BDeu_score(Rcpp::IntegerMatrix, int, int);
double bound(Rcpp::IntegerMatrix, int, int, int, int);
double Jeffreys_bound(Rcpp::IntegerMatrix, int);
double quotient_Jeffreys_bound(Rcpp::IntegerMatrix, int, int, int);
double MDL_bound(Rcpp::IntegerMatrix, int, int, int);
double BDeu_bound(Rcpp::IntegerMatrix, int);

#endif // SCORE_H
