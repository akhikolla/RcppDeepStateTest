// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// cpp_coords_point_translate_wkt
CharacterVector cpp_coords_point_translate_wkt(NumericVector x, NumericVector y, NumericVector z, NumericVector m, int precision, bool trim);
RcppExport SEXP _wkutils_cpp_coords_point_translate_wkt(SEXP xSEXP, SEXP ySEXP, SEXP zSEXP, SEXP mSEXP, SEXP precisionSEXP, SEXP trimSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type x(xSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type y(ySEXP);
    Rcpp::traits::input_parameter< NumericVector >::type z(zSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type m(mSEXP);
    Rcpp::traits::input_parameter< int >::type precision(precisionSEXP);
    Rcpp::traits::input_parameter< bool >::type trim(trimSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_coords_point_translate_wkt(x, y, z, m, precision, trim));
    return rcpp_result_gen;
END_RCPP
}
// cpp_coords_point_translate_wkb
List cpp_coords_point_translate_wkb(NumericVector x, NumericVector y, NumericVector z, NumericVector m, int endian, int bufferSize);
RcppExport SEXP _wkutils_cpp_coords_point_translate_wkb(SEXP xSEXP, SEXP ySEXP, SEXP zSEXP, SEXP mSEXP, SEXP endianSEXP, SEXP bufferSizeSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type x(xSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type y(ySEXP);
    Rcpp::traits::input_parameter< NumericVector >::type z(zSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type m(mSEXP);
    Rcpp::traits::input_parameter< int >::type endian(endianSEXP);
    Rcpp::traits::input_parameter< int >::type bufferSize(bufferSizeSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_coords_point_translate_wkb(x, y, z, m, endian, bufferSize));
    return rcpp_result_gen;
END_RCPP
}
// cpp_coords_point_translate_wksxp
List cpp_coords_point_translate_wksxp(NumericVector x, NumericVector y, NumericVector z, NumericVector m);
RcppExport SEXP _wkutils_cpp_coords_point_translate_wksxp(SEXP xSEXP, SEXP ySEXP, SEXP zSEXP, SEXP mSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type x(xSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type y(ySEXP);
    Rcpp::traits::input_parameter< NumericVector >::type z(zSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type m(mSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_coords_point_translate_wksxp(x, y, z, m));
    return rcpp_result_gen;
END_RCPP
}
// cpp_coords_linestring_translate_wkt
CharacterVector cpp_coords_linestring_translate_wkt(NumericVector x, NumericVector y, NumericVector z, NumericVector m, IntegerVector featureId, int precision, bool trim);
RcppExport SEXP _wkutils_cpp_coords_linestring_translate_wkt(SEXP xSEXP, SEXP ySEXP, SEXP zSEXP, SEXP mSEXP, SEXP featureIdSEXP, SEXP precisionSEXP, SEXP trimSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type x(xSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type y(ySEXP);
    Rcpp::traits::input_parameter< NumericVector >::type z(zSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type m(mSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type featureId(featureIdSEXP);
    Rcpp::traits::input_parameter< int >::type precision(precisionSEXP);
    Rcpp::traits::input_parameter< bool >::type trim(trimSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_coords_linestring_translate_wkt(x, y, z, m, featureId, precision, trim));
    return rcpp_result_gen;
END_RCPP
}
// cpp_coords_linestring_translate_wkb
List cpp_coords_linestring_translate_wkb(NumericVector x, NumericVector y, NumericVector z, NumericVector m, IntegerVector featureId, int endian, int bufferSize);
RcppExport SEXP _wkutils_cpp_coords_linestring_translate_wkb(SEXP xSEXP, SEXP ySEXP, SEXP zSEXP, SEXP mSEXP, SEXP featureIdSEXP, SEXP endianSEXP, SEXP bufferSizeSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type x(xSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type y(ySEXP);
    Rcpp::traits::input_parameter< NumericVector >::type z(zSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type m(mSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type featureId(featureIdSEXP);
    Rcpp::traits::input_parameter< int >::type endian(endianSEXP);
    Rcpp::traits::input_parameter< int >::type bufferSize(bufferSizeSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_coords_linestring_translate_wkb(x, y, z, m, featureId, endian, bufferSize));
    return rcpp_result_gen;
END_RCPP
}
// cpp_coords_linestring_translate_wksxp
List cpp_coords_linestring_translate_wksxp(NumericVector x, NumericVector y, NumericVector z, NumericVector m, IntegerVector featureId);
RcppExport SEXP _wkutils_cpp_coords_linestring_translate_wksxp(SEXP xSEXP, SEXP ySEXP, SEXP zSEXP, SEXP mSEXP, SEXP featureIdSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type x(xSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type y(ySEXP);
    Rcpp::traits::input_parameter< NumericVector >::type z(zSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type m(mSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type featureId(featureIdSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_coords_linestring_translate_wksxp(x, y, z, m, featureId));
    return rcpp_result_gen;
END_RCPP
}
// cpp_coords_polygon_translate_wkt
CharacterVector cpp_coords_polygon_translate_wkt(NumericVector x, NumericVector y, NumericVector z, NumericVector m, IntegerVector featureId, IntegerVector ringId, int precision, bool trim);
RcppExport SEXP _wkutils_cpp_coords_polygon_translate_wkt(SEXP xSEXP, SEXP ySEXP, SEXP zSEXP, SEXP mSEXP, SEXP featureIdSEXP, SEXP ringIdSEXP, SEXP precisionSEXP, SEXP trimSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type x(xSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type y(ySEXP);
    Rcpp::traits::input_parameter< NumericVector >::type z(zSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type m(mSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type featureId(featureIdSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type ringId(ringIdSEXP);
    Rcpp::traits::input_parameter< int >::type precision(precisionSEXP);
    Rcpp::traits::input_parameter< bool >::type trim(trimSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_coords_polygon_translate_wkt(x, y, z, m, featureId, ringId, precision, trim));
    return rcpp_result_gen;
END_RCPP
}
// cpp_coords_polygon_translate_wkb
List cpp_coords_polygon_translate_wkb(NumericVector x, NumericVector y, NumericVector z, NumericVector m, IntegerVector featureId, IntegerVector ringId, int endian, int bufferSize);
RcppExport SEXP _wkutils_cpp_coords_polygon_translate_wkb(SEXP xSEXP, SEXP ySEXP, SEXP zSEXP, SEXP mSEXP, SEXP featureIdSEXP, SEXP ringIdSEXP, SEXP endianSEXP, SEXP bufferSizeSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type x(xSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type y(ySEXP);
    Rcpp::traits::input_parameter< NumericVector >::type z(zSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type m(mSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type featureId(featureIdSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type ringId(ringIdSEXP);
    Rcpp::traits::input_parameter< int >::type endian(endianSEXP);
    Rcpp::traits::input_parameter< int >::type bufferSize(bufferSizeSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_coords_polygon_translate_wkb(x, y, z, m, featureId, ringId, endian, bufferSize));
    return rcpp_result_gen;
END_RCPP
}
// cpp_coords_polygon_translate_wksxp
List cpp_coords_polygon_translate_wksxp(NumericVector x, NumericVector y, NumericVector z, NumericVector m, IntegerVector featureId, IntegerVector ringId);
RcppExport SEXP _wkutils_cpp_coords_polygon_translate_wksxp(SEXP xSEXP, SEXP ySEXP, SEXP zSEXP, SEXP mSEXP, SEXP featureIdSEXP, SEXP ringIdSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type x(xSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type y(ySEXP);
    Rcpp::traits::input_parameter< NumericVector >::type z(zSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type m(mSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type featureId(featureIdSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type ringId(ringIdSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_coords_polygon_translate_wksxp(x, y, z, m, featureId, ringId));
    return rcpp_result_gen;
END_RCPP
}
// cpp_coords_wkb
List cpp_coords_wkb(List wkb, bool sepNA);
RcppExport SEXP _wkutils_cpp_coords_wkb(SEXP wkbSEXP, SEXP sepNASEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< List >::type wkb(wkbSEXP);
    Rcpp::traits::input_parameter< bool >::type sepNA(sepNASEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_coords_wkb(wkb, sepNA));
    return rcpp_result_gen;
END_RCPP
}
// cpp_coords_wkt
List cpp_coords_wkt(CharacterVector wkt, bool sepNA);
RcppExport SEXP _wkutils_cpp_coords_wkt(SEXP wktSEXP, SEXP sepNASEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< CharacterVector >::type wkt(wktSEXP);
    Rcpp::traits::input_parameter< bool >::type sepNA(sepNASEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_coords_wkt(wkt, sepNA));
    return rcpp_result_gen;
END_RCPP
}
// cpp_coords_wksxp
List cpp_coords_wksxp(List wksxp, bool sepNA);
RcppExport SEXP _wkutils_cpp_coords_wksxp(SEXP wksxpSEXP, SEXP sepNASEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< List >::type wksxp(wksxpSEXP);
    Rcpp::traits::input_parameter< bool >::type sepNA(sepNASEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_coords_wksxp(wksxp, sepNA));
    return rcpp_result_gen;
END_RCPP
}
// cpp_debug_wkb
void cpp_debug_wkb(List wkb);
RcppExport SEXP _wkutils_cpp_debug_wkb(SEXP wkbSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< List >::type wkb(wkbSEXP);
    cpp_debug_wkb(wkb);
    return R_NilValue;
END_RCPP
}
// cpp_debug_wkt
void cpp_debug_wkt(CharacterVector input);
RcppExport SEXP _wkutils_cpp_debug_wkt(SEXP inputSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< CharacterVector >::type input(inputSEXP);
    cpp_debug_wkt(input);
    return R_NilValue;
END_RCPP
}
// cpp_debug_wkt_streamer
void cpp_debug_wkt_streamer(CharacterVector input);
RcppExport SEXP _wkutils_cpp_debug_wkt_streamer(SEXP inputSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< CharacterVector >::type input(inputSEXP);
    cpp_debug_wkt_streamer(input);
    return R_NilValue;
END_RCPP
}
// cpp_debug_wksxp
void cpp_debug_wksxp(List input);
RcppExport SEXP _wkutils_cpp_debug_wksxp(SEXP inputSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< List >::type input(inputSEXP);
    cpp_debug_wksxp(input);
    return R_NilValue;
END_RCPP
}
// cpp_wkt_set_srid
CharacterVector cpp_wkt_set_srid(CharacterVector wkt, IntegerVector srid, int precision, bool trim);
RcppExport SEXP _wkutils_cpp_wkt_set_srid(SEXP wktSEXP, SEXP sridSEXP, SEXP precisionSEXP, SEXP trimSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< CharacterVector >::type wkt(wktSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type srid(sridSEXP);
    Rcpp::traits::input_parameter< int >::type precision(precisionSEXP);
    Rcpp::traits::input_parameter< bool >::type trim(trimSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_wkt_set_srid(wkt, srid, precision, trim));
    return rcpp_result_gen;
END_RCPP
}
// cpp_wkb_set_srid
List cpp_wkb_set_srid(List wkb, IntegerVector srid, int endian);
RcppExport SEXP _wkutils_cpp_wkb_set_srid(SEXP wkbSEXP, SEXP sridSEXP, SEXP endianSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< List >::type wkb(wkbSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type srid(sridSEXP);
    Rcpp::traits::input_parameter< int >::type endian(endianSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_wkb_set_srid(wkb, srid, endian));
    return rcpp_result_gen;
END_RCPP
}
// cpp_wksxp_set_srid
List cpp_wksxp_set_srid(List wksxp, IntegerVector srid);
RcppExport SEXP _wkutils_cpp_wksxp_set_srid(SEXP wksxpSEXP, SEXP sridSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< List >::type wksxp(wksxpSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type srid(sridSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_wksxp_set_srid(wksxp, srid));
    return rcpp_result_gen;
END_RCPP
}
// cpp_wkt_set_z
CharacterVector cpp_wkt_set_z(CharacterVector wkt, NumericVector z, int precision, bool trim);
RcppExport SEXP _wkutils_cpp_wkt_set_z(SEXP wktSEXP, SEXP zSEXP, SEXP precisionSEXP, SEXP trimSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< CharacterVector >::type wkt(wktSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type z(zSEXP);
    Rcpp::traits::input_parameter< int >::type precision(precisionSEXP);
    Rcpp::traits::input_parameter< bool >::type trim(trimSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_wkt_set_z(wkt, z, precision, trim));
    return rcpp_result_gen;
END_RCPP
}
// cpp_wkb_set_z
List cpp_wkb_set_z(List wkb, NumericVector z, int endian);
RcppExport SEXP _wkutils_cpp_wkb_set_z(SEXP wkbSEXP, SEXP zSEXP, SEXP endianSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< List >::type wkb(wkbSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type z(zSEXP);
    Rcpp::traits::input_parameter< int >::type endian(endianSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_wkb_set_z(wkb, z, endian));
    return rcpp_result_gen;
END_RCPP
}
// cpp_wksxp_set_z
List cpp_wksxp_set_z(List wksxp, NumericVector z);
RcppExport SEXP _wkutils_cpp_wksxp_set_z(SEXP wksxpSEXP, SEXP zSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< List >::type wksxp(wksxpSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type z(zSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_wksxp_set_z(wksxp, z));
    return rcpp_result_gen;
END_RCPP
}
// cpp_wkt_transform
CharacterVector cpp_wkt_transform(CharacterVector wkt, NumericVector transform, int precision, bool trim);
RcppExport SEXP _wkutils_cpp_wkt_transform(SEXP wktSEXP, SEXP transformSEXP, SEXP precisionSEXP, SEXP trimSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< CharacterVector >::type wkt(wktSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type transform(transformSEXP);
    Rcpp::traits::input_parameter< int >::type precision(precisionSEXP);
    Rcpp::traits::input_parameter< bool >::type trim(trimSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_wkt_transform(wkt, transform, precision, trim));
    return rcpp_result_gen;
END_RCPP
}
// cpp_wkb_transform
List cpp_wkb_transform(List wkb, NumericVector transform, int endian);
RcppExport SEXP _wkutils_cpp_wkb_transform(SEXP wkbSEXP, SEXP transformSEXP, SEXP endianSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< List >::type wkb(wkbSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type transform(transformSEXP);
    Rcpp::traits::input_parameter< int >::type endian(endianSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_wkb_transform(wkb, transform, endian));
    return rcpp_result_gen;
END_RCPP
}
// cpp_wksxp_transform
List cpp_wksxp_transform(List wksxp, NumericVector transform);
RcppExport SEXP _wkutils_cpp_wksxp_transform(SEXP wksxpSEXP, SEXP transformSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< List >::type wksxp(wksxpSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type transform(transformSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_wksxp_transform(wksxp, transform));
    return rcpp_result_gen;
END_RCPP
}
// cpp_wkt_has_non_finite
LogicalVector cpp_wkt_has_non_finite(CharacterVector wkt);
RcppExport SEXP _wkutils_cpp_wkt_has_non_finite(SEXP wktSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< CharacterVector >::type wkt(wktSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_wkt_has_non_finite(wkt));
    return rcpp_result_gen;
END_RCPP
}
// cpp_wkb_has_non_finite
LogicalVector cpp_wkb_has_non_finite(List wkb);
RcppExport SEXP _wkutils_cpp_wkb_has_non_finite(SEXP wkbSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< List >::type wkb(wkbSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_wkb_has_non_finite(wkb));
    return rcpp_result_gen;
END_RCPP
}
// cpp_wksxp_has_non_finite
LogicalVector cpp_wksxp_has_non_finite(List wksxp);
RcppExport SEXP _wkutils_cpp_wksxp_has_non_finite(SEXP wksxpSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< List >::type wksxp(wksxpSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_wksxp_has_non_finite(wksxp));
    return rcpp_result_gen;
END_RCPP
}
// cpp_wkt_has_missing
LogicalVector cpp_wkt_has_missing(CharacterVector wkt);
RcppExport SEXP _wkutils_cpp_wkt_has_missing(SEXP wktSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< CharacterVector >::type wkt(wktSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_wkt_has_missing(wkt));
    return rcpp_result_gen;
END_RCPP
}
// cpp_wkb_has_missing
LogicalVector cpp_wkb_has_missing(List wkb);
RcppExport SEXP _wkutils_cpp_wkb_has_missing(SEXP wkbSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< List >::type wkb(wkbSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_wkb_has_missing(wkb));
    return rcpp_result_gen;
END_RCPP
}
// cpp_wksxp_has_missing
LogicalVector cpp_wksxp_has_missing(List wksxp);
RcppExport SEXP _wkutils_cpp_wksxp_has_missing(SEXP wksxpSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< List >::type wksxp(wksxpSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_wksxp_has_missing(wksxp));
    return rcpp_result_gen;
END_RCPP
}
// cpp_meta_wkb
List cpp_meta_wkb(List wkb, bool recursive);
RcppExport SEXP _wkutils_cpp_meta_wkb(SEXP wkbSEXP, SEXP recursiveSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< List >::type wkb(wkbSEXP);
    Rcpp::traits::input_parameter< bool >::type recursive(recursiveSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_meta_wkb(wkb, recursive));
    return rcpp_result_gen;
END_RCPP
}
// cpp_meta_wkt
List cpp_meta_wkt(CharacterVector wkt, bool recursive);
RcppExport SEXP _wkutils_cpp_meta_wkt(SEXP wktSEXP, SEXP recursiveSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< CharacterVector >::type wkt(wktSEXP);
    Rcpp::traits::input_parameter< bool >::type recursive(recursiveSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_meta_wkt(wkt, recursive));
    return rcpp_result_gen;
END_RCPP
}
// cpp_meta_wkt_streamer
List cpp_meta_wkt_streamer(CharacterVector wkt, bool recursive);
RcppExport SEXP _wkutils_cpp_meta_wkt_streamer(SEXP wktSEXP, SEXP recursiveSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< CharacterVector >::type wkt(wktSEXP);
    Rcpp::traits::input_parameter< bool >::type recursive(recursiveSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_meta_wkt_streamer(wkt, recursive));
    return rcpp_result_gen;
END_RCPP
}
// cpp_meta_wksxp
List cpp_meta_wksxp(List wksxp, bool recursive);
RcppExport SEXP _wkutils_cpp_meta_wksxp(SEXP wksxpSEXP, SEXP recursiveSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< List >::type wksxp(wksxpSEXP);
    Rcpp::traits::input_parameter< bool >::type recursive(recursiveSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_meta_wksxp(wksxp, recursive));
    return rcpp_result_gen;
END_RCPP
}
// cpp_ranges_wkb
List cpp_ranges_wkb(List wkb, bool naRm, bool onlyFinite);
RcppExport SEXP _wkutils_cpp_ranges_wkb(SEXP wkbSEXP, SEXP naRmSEXP, SEXP onlyFiniteSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< List >::type wkb(wkbSEXP);
    Rcpp::traits::input_parameter< bool >::type naRm(naRmSEXP);
    Rcpp::traits::input_parameter< bool >::type onlyFinite(onlyFiniteSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_ranges_wkb(wkb, naRm, onlyFinite));
    return rcpp_result_gen;
END_RCPP
}
// cpp_ranges_wkt
List cpp_ranges_wkt(CharacterVector wkt, bool naRm, bool onlyFinite);
RcppExport SEXP _wkutils_cpp_ranges_wkt(SEXP wktSEXP, SEXP naRmSEXP, SEXP onlyFiniteSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< CharacterVector >::type wkt(wktSEXP);
    Rcpp::traits::input_parameter< bool >::type naRm(naRmSEXP);
    Rcpp::traits::input_parameter< bool >::type onlyFinite(onlyFiniteSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_ranges_wkt(wkt, naRm, onlyFinite));
    return rcpp_result_gen;
END_RCPP
}
// cpp_ranges_wksxp
List cpp_ranges_wksxp(List wksxp, bool naRm, bool onlyFinite);
RcppExport SEXP _wkutils_cpp_ranges_wksxp(SEXP wksxpSEXP, SEXP naRmSEXP, SEXP onlyFiniteSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< List >::type wksxp(wksxpSEXP);
    Rcpp::traits::input_parameter< bool >::type naRm(naRmSEXP);
    Rcpp::traits::input_parameter< bool >::type onlyFinite(onlyFiniteSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_ranges_wksxp(wksxp, naRm, onlyFinite));
    return rcpp_result_gen;
END_RCPP
}
// cpp_feature_ranges_wkb
List cpp_feature_ranges_wkb(List wkb, bool naRm, bool onlyFinite);
RcppExport SEXP _wkutils_cpp_feature_ranges_wkb(SEXP wkbSEXP, SEXP naRmSEXP, SEXP onlyFiniteSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< List >::type wkb(wkbSEXP);
    Rcpp::traits::input_parameter< bool >::type naRm(naRmSEXP);
    Rcpp::traits::input_parameter< bool >::type onlyFinite(onlyFiniteSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_feature_ranges_wkb(wkb, naRm, onlyFinite));
    return rcpp_result_gen;
END_RCPP
}
// cpp_feature_ranges_wkt
List cpp_feature_ranges_wkt(CharacterVector wkt, bool naRm, bool onlyFinite);
RcppExport SEXP _wkutils_cpp_feature_ranges_wkt(SEXP wktSEXP, SEXP naRmSEXP, SEXP onlyFiniteSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< CharacterVector >::type wkt(wktSEXP);
    Rcpp::traits::input_parameter< bool >::type naRm(naRmSEXP);
    Rcpp::traits::input_parameter< bool >::type onlyFinite(onlyFiniteSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_feature_ranges_wkt(wkt, naRm, onlyFinite));
    return rcpp_result_gen;
END_RCPP
}
// cpp_feature_ranges_wksxp
List cpp_feature_ranges_wksxp(List wksxp, bool naRm, bool onlyFinite);
RcppExport SEXP _wkutils_cpp_feature_ranges_wksxp(SEXP wksxpSEXP, SEXP naRmSEXP, SEXP onlyFiniteSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< List >::type wksxp(wksxpSEXP);
    Rcpp::traits::input_parameter< bool >::type naRm(naRmSEXP);
    Rcpp::traits::input_parameter< bool >::type onlyFinite(onlyFiniteSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_feature_ranges_wksxp(wksxp, naRm, onlyFinite));
    return rcpp_result_gen;
END_RCPP
}
// cpp_wkt_unnest
CharacterVector cpp_wkt_unnest(CharacterVector wkt, bool keepEmpty, bool keepMulti, int maxUnnestDepth);
RcppExport SEXP _wkutils_cpp_wkt_unnest(SEXP wktSEXP, SEXP keepEmptySEXP, SEXP keepMultiSEXP, SEXP maxUnnestDepthSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< CharacterVector >::type wkt(wktSEXP);
    Rcpp::traits::input_parameter< bool >::type keepEmpty(keepEmptySEXP);
    Rcpp::traits::input_parameter< bool >::type keepMulti(keepMultiSEXP);
    Rcpp::traits::input_parameter< int >::type maxUnnestDepth(maxUnnestDepthSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_wkt_unnest(wkt, keepEmpty, keepMulti, maxUnnestDepth));
    return rcpp_result_gen;
END_RCPP
}
// cpp_wkb_unnest
List cpp_wkb_unnest(List wkb, bool keepEmpty, bool keepMulti, int maxUnnestDepth, int endian);
RcppExport SEXP _wkutils_cpp_wkb_unnest(SEXP wkbSEXP, SEXP keepEmptySEXP, SEXP keepMultiSEXP, SEXP maxUnnestDepthSEXP, SEXP endianSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< List >::type wkb(wkbSEXP);
    Rcpp::traits::input_parameter< bool >::type keepEmpty(keepEmptySEXP);
    Rcpp::traits::input_parameter< bool >::type keepMulti(keepMultiSEXP);
    Rcpp::traits::input_parameter< int >::type maxUnnestDepth(maxUnnestDepthSEXP);
    Rcpp::traits::input_parameter< int >::type endian(endianSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_wkb_unnest(wkb, keepEmpty, keepMulti, maxUnnestDepth, endian));
    return rcpp_result_gen;
END_RCPP
}
// cpp_wksxp_unnest
List cpp_wksxp_unnest(List wksxp, bool keepEmpty, bool keepMulti, int maxUnnestDepth);
RcppExport SEXP _wkutils_cpp_wksxp_unnest(SEXP wksxpSEXP, SEXP keepEmptySEXP, SEXP keepMultiSEXP, SEXP maxUnnestDepthSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< List >::type wksxp(wksxpSEXP);
    Rcpp::traits::input_parameter< bool >::type keepEmpty(keepEmptySEXP);
    Rcpp::traits::input_parameter< bool >::type keepMulti(keepMultiSEXP);
    Rcpp::traits::input_parameter< int >::type maxUnnestDepth(maxUnnestDepthSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_wksxp_unnest(wksxp, keepEmpty, keepMulti, maxUnnestDepth));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_wkutils_cpp_coords_point_translate_wkt", (DL_FUNC) &_wkutils_cpp_coords_point_translate_wkt, 6},
    {"_wkutils_cpp_coords_point_translate_wkb", (DL_FUNC) &_wkutils_cpp_coords_point_translate_wkb, 6},
    {"_wkutils_cpp_coords_point_translate_wksxp", (DL_FUNC) &_wkutils_cpp_coords_point_translate_wksxp, 4},
    {"_wkutils_cpp_coords_linestring_translate_wkt", (DL_FUNC) &_wkutils_cpp_coords_linestring_translate_wkt, 7},
    {"_wkutils_cpp_coords_linestring_translate_wkb", (DL_FUNC) &_wkutils_cpp_coords_linestring_translate_wkb, 7},
    {"_wkutils_cpp_coords_linestring_translate_wksxp", (DL_FUNC) &_wkutils_cpp_coords_linestring_translate_wksxp, 5},
    {"_wkutils_cpp_coords_polygon_translate_wkt", (DL_FUNC) &_wkutils_cpp_coords_polygon_translate_wkt, 8},
    {"_wkutils_cpp_coords_polygon_translate_wkb", (DL_FUNC) &_wkutils_cpp_coords_polygon_translate_wkb, 8},
    {"_wkutils_cpp_coords_polygon_translate_wksxp", (DL_FUNC) &_wkutils_cpp_coords_polygon_translate_wksxp, 6},
    {"_wkutils_cpp_coords_wkb", (DL_FUNC) &_wkutils_cpp_coords_wkb, 2},
    {"_wkutils_cpp_coords_wkt", (DL_FUNC) &_wkutils_cpp_coords_wkt, 2},
    {"_wkutils_cpp_coords_wksxp", (DL_FUNC) &_wkutils_cpp_coords_wksxp, 2},
    {"_wkutils_cpp_debug_wkb", (DL_FUNC) &_wkutils_cpp_debug_wkb, 1},
    {"_wkutils_cpp_debug_wkt", (DL_FUNC) &_wkutils_cpp_debug_wkt, 1},
    {"_wkutils_cpp_debug_wkt_streamer", (DL_FUNC) &_wkutils_cpp_debug_wkt_streamer, 1},
    {"_wkutils_cpp_debug_wksxp", (DL_FUNC) &_wkutils_cpp_debug_wksxp, 1},
    {"_wkutils_cpp_wkt_set_srid", (DL_FUNC) &_wkutils_cpp_wkt_set_srid, 4},
    {"_wkutils_cpp_wkb_set_srid", (DL_FUNC) &_wkutils_cpp_wkb_set_srid, 3},
    {"_wkutils_cpp_wksxp_set_srid", (DL_FUNC) &_wkutils_cpp_wksxp_set_srid, 2},
    {"_wkutils_cpp_wkt_set_z", (DL_FUNC) &_wkutils_cpp_wkt_set_z, 4},
    {"_wkutils_cpp_wkb_set_z", (DL_FUNC) &_wkutils_cpp_wkb_set_z, 3},
    {"_wkutils_cpp_wksxp_set_z", (DL_FUNC) &_wkutils_cpp_wksxp_set_z, 2},
    {"_wkutils_cpp_wkt_transform", (DL_FUNC) &_wkutils_cpp_wkt_transform, 4},
    {"_wkutils_cpp_wkb_transform", (DL_FUNC) &_wkutils_cpp_wkb_transform, 3},
    {"_wkutils_cpp_wksxp_transform", (DL_FUNC) &_wkutils_cpp_wksxp_transform, 2},
    {"_wkutils_cpp_wkt_has_non_finite", (DL_FUNC) &_wkutils_cpp_wkt_has_non_finite, 1},
    {"_wkutils_cpp_wkb_has_non_finite", (DL_FUNC) &_wkutils_cpp_wkb_has_non_finite, 1},
    {"_wkutils_cpp_wksxp_has_non_finite", (DL_FUNC) &_wkutils_cpp_wksxp_has_non_finite, 1},
    {"_wkutils_cpp_wkt_has_missing", (DL_FUNC) &_wkutils_cpp_wkt_has_missing, 1},
    {"_wkutils_cpp_wkb_has_missing", (DL_FUNC) &_wkutils_cpp_wkb_has_missing, 1},
    {"_wkutils_cpp_wksxp_has_missing", (DL_FUNC) &_wkutils_cpp_wksxp_has_missing, 1},
    {"_wkutils_cpp_meta_wkb", (DL_FUNC) &_wkutils_cpp_meta_wkb, 2},
    {"_wkutils_cpp_meta_wkt", (DL_FUNC) &_wkutils_cpp_meta_wkt, 2},
    {"_wkutils_cpp_meta_wkt_streamer", (DL_FUNC) &_wkutils_cpp_meta_wkt_streamer, 2},
    {"_wkutils_cpp_meta_wksxp", (DL_FUNC) &_wkutils_cpp_meta_wksxp, 2},
    {"_wkutils_cpp_ranges_wkb", (DL_FUNC) &_wkutils_cpp_ranges_wkb, 3},
    {"_wkutils_cpp_ranges_wkt", (DL_FUNC) &_wkutils_cpp_ranges_wkt, 3},
    {"_wkutils_cpp_ranges_wksxp", (DL_FUNC) &_wkutils_cpp_ranges_wksxp, 3},
    {"_wkutils_cpp_feature_ranges_wkb", (DL_FUNC) &_wkutils_cpp_feature_ranges_wkb, 3},
    {"_wkutils_cpp_feature_ranges_wkt", (DL_FUNC) &_wkutils_cpp_feature_ranges_wkt, 3},
    {"_wkutils_cpp_feature_ranges_wksxp", (DL_FUNC) &_wkutils_cpp_feature_ranges_wksxp, 3},
    {"_wkutils_cpp_wkt_unnest", (DL_FUNC) &_wkutils_cpp_wkt_unnest, 4},
    {"_wkutils_cpp_wkb_unnest", (DL_FUNC) &_wkutils_cpp_wkb_unnest, 5},
    {"_wkutils_cpp_wksxp_unnest", (DL_FUNC) &_wkutils_cpp_wksxp_unnest, 4},
    {NULL, NULL, 0}
};

RcppExport void R_init_wkutils(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
