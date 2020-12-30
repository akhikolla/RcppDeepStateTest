// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// myPearson
double myPearson(NumericVector x, NumericVector y);
RcppExport SEXP _segmenTier_myPearson(SEXP xSEXP, SEXP ySEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type x(xSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type y(ySEXP);
    rcpp_result_gen = Rcpp::wrap(myPearson(x, y));
    return rcpp_result_gen;
END_RCPP
}
// clusterCor_c
NumericMatrix clusterCor_c(NumericMatrix data, NumericMatrix clusters);
RcppExport SEXP _segmenTier_clusterCor_c(SEXP dataSEXP, SEXP clustersSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericMatrix >::type data(dataSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type clusters(clustersSEXP);
    rcpp_result_gen = Rcpp::wrap(clusterCor_c(data, clusters));
    return rcpp_result_gen;
END_RCPP
}
// icor
double icor(int k, int j, int c, NumericVector seq, int M, NumericMatrix csim);
RcppExport SEXP _segmenTier_icor(SEXP kSEXP, SEXP jSEXP, SEXP cSEXP, SEXP seqSEXP, SEXP MSEXP, SEXP csimSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type k(kSEXP);
    Rcpp::traits::input_parameter< int >::type j(jSEXP);
    Rcpp::traits::input_parameter< int >::type c(cSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type seq(seqSEXP);
    Rcpp::traits::input_parameter< int >::type M(MSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type csim(csimSEXP);
    rcpp_result_gen = Rcpp::wrap(icor(k, j, c, seq, M, csim));
    return rcpp_result_gen;
END_RCPP
}
// ccor
double ccor(int k, int j, int c, NumericVector seq, int M, NumericMatrix csim);
RcppExport SEXP _segmenTier_ccor(SEXP kSEXP, SEXP jSEXP, SEXP cSEXP, SEXP seqSEXP, SEXP MSEXP, SEXP csimSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type k(kSEXP);
    Rcpp::traits::input_parameter< int >::type j(jSEXP);
    Rcpp::traits::input_parameter< int >::type c(cSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type seq(seqSEXP);
    Rcpp::traits::input_parameter< int >::type M(MSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type csim(csimSEXP);
    rcpp_result_gen = Rcpp::wrap(ccor(k, j, c, seq, M, csim));
    return rcpp_result_gen;
END_RCPP
}
// calculateScore
List calculateScore(NumericVector seq, NumericVector C, std::string score, NumericMatrix csim, int M, int Mn, String multi);
RcppExport SEXP _segmenTier_calculateScore(SEXP seqSEXP, SEXP CSEXP, SEXP scoreSEXP, SEXP csimSEXP, SEXP MSEXP, SEXP MnSEXP, SEXP multiSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type seq(seqSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type C(CSEXP);
    Rcpp::traits::input_parameter< std::string >::type score(scoreSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type csim(csimSEXP);
    Rcpp::traits::input_parameter< int >::type M(MSEXP);
    Rcpp::traits::input_parameter< int >::type Mn(MnSEXP);
    Rcpp::traits::input_parameter< String >::type multi(multiSEXP);
    rcpp_result_gen = Rcpp::wrap(calculateScore(seq, C, score, csim, M, Mn, multi));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_segmenTier_myPearson", (DL_FUNC) &_segmenTier_myPearson, 2},
    {"_segmenTier_clusterCor_c", (DL_FUNC) &_segmenTier_clusterCor_c, 2},
    {"_segmenTier_icor", (DL_FUNC) &_segmenTier_icor, 6},
    {"_segmenTier_ccor", (DL_FUNC) &_segmenTier_ccor, 6},
    {"_segmenTier_calculateScore", (DL_FUNC) &_segmenTier_calculateScore, 7},
    {NULL, NULL, 0}
};

RcppExport void R_init_segmenTier(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
