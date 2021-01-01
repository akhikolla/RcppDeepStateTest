// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// alphaEst
List alphaEst(Rcpp::NumericVector dtime, Rcpp::NumericVector delta);
RcppExport SEXP _lclGWAS_alphaEst(SEXP dtimeSEXP, SEXP deltaSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type dtime(dtimeSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type delta(deltaSEXP);
    rcpp_result_gen = Rcpp::wrap(alphaEst(dtime, delta));
    return rcpp_result_gen;
END_RCPP
}
// betaEst
List betaEst(Rcpp::NumericVector fam_group, Rcpp::NumericVector alpha, Rcpp::NumericVector dtime, Rcpp::NumericVector delta, Rcpp::NumericVector g, double var, double lower, double upper);
RcppExport SEXP _lclGWAS_betaEst(SEXP fam_groupSEXP, SEXP alphaSEXP, SEXP dtimeSEXP, SEXP deltaSEXP, SEXP gSEXP, SEXP varSEXP, SEXP lowerSEXP, SEXP upperSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type fam_group(fam_groupSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type alpha(alphaSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type dtime(dtimeSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type delta(deltaSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type g(gSEXP);
    Rcpp::traits::input_parameter< double >::type var(varSEXP);
    Rcpp::traits::input_parameter< double >::type lower(lowerSEXP);
    Rcpp::traits::input_parameter< double >::type upper(upperSEXP);
    rcpp_result_gen = Rcpp::wrap(betaEst(fam_group, alpha, dtime, delta, g, var, lower, upper));
    return rcpp_result_gen;
END_RCPP
}
// varEst
List varEst(Rcpp::NumericVector fam_group, Rcpp::NumericVector alpha, Rcpp::NumericVector dtime, Rcpp::NumericVector delta, Rcpp::NumericVector g, double beta, double lower, double upper);
RcppExport SEXP _lclGWAS_varEst(SEXP fam_groupSEXP, SEXP alphaSEXP, SEXP dtimeSEXP, SEXP deltaSEXP, SEXP gSEXP, SEXP betaSEXP, SEXP lowerSEXP, SEXP upperSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type fam_group(fam_groupSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type alpha(alphaSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type dtime(dtimeSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type delta(deltaSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type g(gSEXP);
    Rcpp::traits::input_parameter< double >::type beta(betaSEXP);
    Rcpp::traits::input_parameter< double >::type lower(lowerSEXP);
    Rcpp::traits::input_parameter< double >::type upper(upperSEXP);
    rcpp_result_gen = Rcpp::wrap(varEst(fam_group, alpha, dtime, delta, g, beta, lower, upper));
    return rcpp_result_gen;
END_RCPP
}
