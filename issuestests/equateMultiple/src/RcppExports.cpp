// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

// objectivefzRcpp
double objectivefzRcpp(NumericVector par, int T, NumericVector ab, NumericVector wt, NumericMatrix aj1T, NumericMatrix bj1T, NumericMatrix cj1T, int nummet, int itmp, double D, int base);
RcppExport SEXP _equateMultiple_objectivefzRcpp(SEXP parSEXP, SEXP TSEXP, SEXP abSEXP, SEXP wtSEXP, SEXP aj1TSEXP, SEXP bj1TSEXP, SEXP cj1TSEXP, SEXP nummetSEXP, SEXP itmpSEXP, SEXP DSEXP, SEXP baseSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type par(parSEXP);
    Rcpp::traits::input_parameter< int >::type T(TSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type ab(abSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type wt(wtSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type aj1T(aj1TSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type bj1T(bj1TSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type cj1T(cj1TSEXP);
    Rcpp::traits::input_parameter< int >::type nummet(nummetSEXP);
    Rcpp::traits::input_parameter< int >::type itmp(itmpSEXP);
    Rcpp::traits::input_parameter< double >::type D(DSEXP);
    Rcpp::traits::input_parameter< int >::type base(baseSEXP);
    rcpp_result_gen = Rcpp::wrap(objectivefzRcpp(par, T, ab, wt, aj1T, bj1T, cj1T, nummet, itmp, D, base));
    return rcpp_result_gen;
END_RCPP
}
// hessRcpp
NumericMatrix hessRcpp(NumericVector par, int T, NumericVector ab, NumericVector wt, NumericMatrix aj1T, NumericMatrix bj1T, NumericMatrix cj1T, int nummet, int itmp, double D, int base);
RcppExport SEXP _equateMultiple_hessRcpp(SEXP parSEXP, SEXP TSEXP, SEXP abSEXP, SEXP wtSEXP, SEXP aj1TSEXP, SEXP bj1TSEXP, SEXP cj1TSEXP, SEXP nummetSEXP, SEXP itmpSEXP, SEXP DSEXP, SEXP baseSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type par(parSEXP);
    Rcpp::traits::input_parameter< int >::type T(TSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type ab(abSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type wt(wtSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type aj1T(aj1TSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type bj1T(bj1TSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type cj1T(cj1TSEXP);
    Rcpp::traits::input_parameter< int >::type nummet(nummetSEXP);
    Rcpp::traits::input_parameter< int >::type itmp(itmpSEXP);
    Rcpp::traits::input_parameter< double >::type D(DSEXP);
    Rcpp::traits::input_parameter< int >::type base(baseSEXP);
    rcpp_result_gen = Rcpp::wrap(hessRcpp(par, T, ab, wt, aj1T, bj1T, cj1T, nummet, itmp, D, base));
    return rcpp_result_gen;
END_RCPP
}
// gradRcpp
NumericVector gradRcpp(NumericVector par, int T, NumericVector ab, NumericVector wt, NumericMatrix aj1T, NumericMatrix bj1T, NumericMatrix cj1T, int nummet, int itmp, double D, int base);
RcppExport SEXP _equateMultiple_gradRcpp(SEXP parSEXP, SEXP TSEXP, SEXP abSEXP, SEXP wtSEXP, SEXP aj1TSEXP, SEXP bj1TSEXP, SEXP cj1TSEXP, SEXP nummetSEXP, SEXP itmpSEXP, SEXP DSEXP, SEXP baseSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type par(parSEXP);
    Rcpp::traits::input_parameter< int >::type T(TSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type ab(abSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type wt(wtSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type aj1T(aj1TSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type bj1T(bj1TSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type cj1T(cj1TSEXP);
    Rcpp::traits::input_parameter< int >::type nummet(nummetSEXP);
    Rcpp::traits::input_parameter< int >::type itmp(itmpSEXP);
    Rcpp::traits::input_parameter< double >::type D(DSEXP);
    Rcpp::traits::input_parameter< int >::type base(baseSEXP);
    rcpp_result_gen = Rcpp::wrap(gradRcpp(par, T, ab, wt, aj1T, bj1T, cj1T, nummet, itmp, D, base));
    return rcpp_result_gen;
END_RCPP
}
// partialABgammaRcpp
List partialABgammaRcpp(NumericVector par, int T, NumericVector ab, NumericVector wt, NumericMatrix aj1T, NumericMatrix bj1T, NumericMatrix cj1T, int nummet, int itmp, double D, int base, int nb, IntegerVector posnomi);
RcppExport SEXP _equateMultiple_partialABgammaRcpp(SEXP parSEXP, SEXP TSEXP, SEXP abSEXP, SEXP wtSEXP, SEXP aj1TSEXP, SEXP bj1TSEXP, SEXP cj1TSEXP, SEXP nummetSEXP, SEXP itmpSEXP, SEXP DSEXP, SEXP baseSEXP, SEXP nbSEXP, SEXP posnomiSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type par(parSEXP);
    Rcpp::traits::input_parameter< int >::type T(TSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type ab(abSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type wt(wtSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type aj1T(aj1TSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type bj1T(bj1TSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type cj1T(cj1TSEXP);
    Rcpp::traits::input_parameter< int >::type nummet(nummetSEXP);
    Rcpp::traits::input_parameter< int >::type itmp(itmpSEXP);
    Rcpp::traits::input_parameter< double >::type D(DSEXP);
    Rcpp::traits::input_parameter< int >::type base(baseSEXP);
    Rcpp::traits::input_parameter< int >::type nb(nbSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type posnomi(posnomiSEXP);
    rcpp_result_gen = Rcpp::wrap(partialABgammaRcpp(par, T, ab, wt, aj1T, bj1T, cj1T, nummet, itmp, D, base, nb, posnomi));
    return rcpp_result_gen;
END_RCPP
}
// VarExtRcpp
arma::mat VarExtRcpp(List x);
RcppExport SEXP _equateMultiple_VarExtRcpp(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< List >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(VarExtRcpp(x));
    return rcpp_result_gen;
END_RCPP
}
// ipfRcpp
List ipfRcpp(NumericMatrix aj1T, int base, double eps);
RcppExport SEXP _equateMultiple_ipfRcpp(SEXP aj1TSEXP, SEXP baseSEXP, SEXP epsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericMatrix >::type aj1T(aj1TSEXP);
    Rcpp::traits::input_parameter< int >::type base(baseSEXP);
    Rcpp::traits::input_parameter< double >::type eps(epsSEXP);
    rcpp_result_gen = Rcpp::wrap(ipfRcpp(aj1T, base, eps));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_equateMultiple_objectivefzRcpp", (DL_FUNC) &_equateMultiple_objectivefzRcpp, 11},
    {"_equateMultiple_hessRcpp", (DL_FUNC) &_equateMultiple_hessRcpp, 11},
    {"_equateMultiple_gradRcpp", (DL_FUNC) &_equateMultiple_gradRcpp, 11},
    {"_equateMultiple_partialABgammaRcpp", (DL_FUNC) &_equateMultiple_partialABgammaRcpp, 13},
    {"_equateMultiple_VarExtRcpp", (DL_FUNC) &_equateMultiple_VarExtRcpp, 1},
    {"_equateMultiple_ipfRcpp", (DL_FUNC) &_equateMultiple_ipfRcpp, 3},
    {NULL, NULL, 0}
};

RcppExport void R_init_equateMultiple(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
