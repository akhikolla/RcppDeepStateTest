// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// generateCompositions
List generateCompositions(int n);
RcppExport SEXP _multicool_generateCompositions(SEXP nSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    rcpp_result_gen = Rcpp::wrap(generateCompositions(n));
    return rcpp_result_gen;
END_RCPP
}
// Stirling2C
long Stirling2C(int n, int k);
RcppExport SEXP _multicool_Stirling2C(SEXP nSEXP, SEXP kSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    Rcpp::traits::input_parameter< int >::type k(kSEXP);
    rcpp_result_gen = Rcpp::wrap(Stirling2C(n, k));
    return rcpp_result_gen;
END_RCPP
}
// BellC
long BellC(int n);
RcppExport SEXP _multicool_BellC(SEXP nSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    rcpp_result_gen = Rcpp::wrap(BellC(n));
    return rcpp_result_gen;
END_RCPP
}
// multinomCoeff
NumericVector multinomCoeff(NumericVector x, bool useDouble);
RcppExport SEXP _multicool_multinomCoeff(SEXP xSEXP, SEXP useDoubleSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type x(xSEXP);
    Rcpp::traits::input_parameter< bool >::type useDouble(useDoubleSEXP);
    rcpp_result_gen = Rcpp::wrap(multinomCoeff(x, useDouble));
    return rcpp_result_gen;
END_RCPP
}

RcppExport SEXP _rcpp_module_boot_Multicool();

static const R_CallMethodDef CallEntries[] = {
    {"_multicool_generateCompositions", (DL_FUNC) &_multicool_generateCompositions, 1},
    {"_multicool_Stirling2C", (DL_FUNC) &_multicool_Stirling2C, 2},
    {"_multicool_BellC", (DL_FUNC) &_multicool_BellC, 1},
    {"_multicool_multinomCoeff", (DL_FUNC) &_multicool_multinomCoeff, 2},
    {"_rcpp_module_boot_Multicool", (DL_FUNC) &_rcpp_module_boot_Multicool, 0},
    {NULL, NULL, 0}
};

RcppExport void R_init_multicool(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
