// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// pz_parse_lat
NumericVector pz_parse_lat(CharacterVector x);
RcppExport SEXP _parzer_pz_parse_lat(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< CharacterVector >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(pz_parse_lat(x));
    return rcpp_result_gen;
END_RCPP
}
// pz_parse_lon
NumericVector pz_parse_lon(CharacterVector x);
RcppExport SEXP _parzer_pz_parse_lon(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< CharacterVector >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(pz_parse_lon(x));
    return rcpp_result_gen;
END_RCPP
}
// pz_hemisphere
CharacterVector pz_hemisphere(CharacterVector lon, CharacterVector lat);
RcppExport SEXP _parzer_pz_hemisphere(SEXP lonSEXP, SEXP latSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< CharacterVector >::type lon(lonSEXP);
    Rcpp::traits::input_parameter< CharacterVector >::type lat(latSEXP);
    rcpp_result_gen = Rcpp::wrap(pz_hemisphere(lon, lat));
    return rcpp_result_gen;
END_RCPP
}
// split_decimal_degree
List split_decimal_degree(float x, std::string fmt);
RcppExport SEXP _parzer_split_decimal_degree(SEXP xSEXP, SEXP fmtSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< float >::type x(xSEXP);
    Rcpp::traits::input_parameter< std::string >::type fmt(fmtSEXP);
    rcpp_result_gen = Rcpp::wrap(split_decimal_degree(x, fmt));
    return rcpp_result_gen;
END_RCPP
}
// pz_parse_parts_lat
DataFrame pz_parse_parts_lat(CharacterVector x);
RcppExport SEXP _parzer_pz_parse_parts_lat(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< CharacterVector >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(pz_parse_parts_lat(x));
    return rcpp_result_gen;
END_RCPP
}
// pz_parse_parts_lon
DataFrame pz_parse_parts_lon(CharacterVector x);
RcppExport SEXP _parzer_pz_parse_parts_lon(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< CharacterVector >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(pz_parse_parts_lon(x));
    return rcpp_result_gen;
END_RCPP
}
// pz_split_llstr_string
std::vector<std::string> pz_split_llstr_string(std::string x);
RcppExport SEXP _parzer_pz_split_llstr_string(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(pz_split_llstr_string(x));
    return rcpp_result_gen;
END_RCPP
}
// pz_split_llstr
Rcpp::DataFrame pz_split_llstr(Rcpp::StringVector x);
RcppExport SEXP _parzer_pz_split_llstr(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::StringVector >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(pz_split_llstr(x));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_parzer_pz_parse_lat", (DL_FUNC) &_parzer_pz_parse_lat, 1},
    {"_parzer_pz_parse_lon", (DL_FUNC) &_parzer_pz_parse_lon, 1},
    {"_parzer_pz_hemisphere", (DL_FUNC) &_parzer_pz_hemisphere, 2},
    {"_parzer_split_decimal_degree", (DL_FUNC) &_parzer_split_decimal_degree, 2},
    {"_parzer_pz_parse_parts_lat", (DL_FUNC) &_parzer_pz_parse_parts_lat, 1},
    {"_parzer_pz_parse_parts_lon", (DL_FUNC) &_parzer_pz_parse_parts_lon, 1},
    {"_parzer_pz_split_llstr_string", (DL_FUNC) &_parzer_pz_split_llstr_string, 1},
    {"_parzer_pz_split_llstr", (DL_FUNC) &_parzer_pz_split_llstr, 1},
    {NULL, NULL, 0}
};

RcppExport void R_init_parzer(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
