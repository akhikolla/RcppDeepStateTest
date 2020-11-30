// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

// get_vit_index
Rcpp::NumericVector get_vit_index(Rcpp::CharacterVector t_id_key, Rcpp::CharacterVector control_treatment_t_ids, Rcpp::NumericVector control_treatment_set_nums);
RcppExport SEXP _PanelMatch_get_vit_index(SEXP t_id_keySEXP, SEXP control_treatment_t_idsSEXP, SEXP control_treatment_set_numsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type t_id_key(t_id_keySEXP);
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type control_treatment_t_ids(control_treatment_t_idsSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type control_treatment_set_nums(control_treatment_set_numsSEXP);
    rcpp_result_gen = Rcpp::wrap(get_vit_index(t_id_key, control_treatment_t_ids, control_treatment_set_nums));
    return rcpp_result_gen;
END_RCPP
}
// get_dits
Rcpp::NumericVector get_dits(Rcpp::CharacterVector t_id_key, Rcpp::CharacterVector nonempty_t_ids);
RcppExport SEXP _PanelMatch_get_dits(SEXP t_id_keySEXP, SEXP nonempty_t_idsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type t_id_key(t_id_keySEXP);
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type nonempty_t_ids(nonempty_t_idsSEXP);
    rcpp_result_gen = Rcpp::wrap(get_dits(t_id_key, nonempty_t_ids));
    return rcpp_result_gen;
END_RCPP
}
// prep_lead_years
Rcpp::List prep_lead_years(Rcpp::NumericVector ts, Rcpp::NumericVector lead_window);
RcppExport SEXP _PanelMatch_prep_lead_years(SEXP tsSEXP, SEXP lead_windowSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type ts(tsSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type lead_window(lead_windowSEXP);
    rcpp_result_gen = Rcpp::wrap(prep_lead_years(ts, lead_window));
    return rcpp_result_gen;
END_RCPP
}
// re_norm_index
Rcpp::List re_norm_index(Rcpp::NumericMatrix compmat, Rcpp::NumericVector compmat_row_units, Rcpp::NumericVector compmat_cols, int lead, Rcpp::List sets, Rcpp::NumericVector control_start_years);
RcppExport SEXP _PanelMatch_re_norm_index(SEXP compmatSEXP, SEXP compmat_row_unitsSEXP, SEXP compmat_colsSEXP, SEXP leadSEXP, SEXP setsSEXP, SEXP control_start_yearsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::NumericMatrix >::type compmat(compmatSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type compmat_row_units(compmat_row_unitsSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type compmat_cols(compmat_colsSEXP);
    Rcpp::traits::input_parameter< int >::type lead(leadSEXP);
    Rcpp::traits::input_parameter< Rcpp::List >::type sets(setsSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type control_start_years(control_start_yearsSEXP);
    rcpp_result_gen = Rcpp::wrap(re_norm_index(compmat, compmat_row_units, compmat_cols, lead, sets, control_start_years));
    return rcpp_result_gen;
END_RCPP
}
// check_treated_units
Rcpp::LogicalVector check_treated_units(Rcpp::NumericMatrix compmat, Rcpp::NumericVector compmat_row_units, Rcpp::NumericVector compmat_cols, int lead, Rcpp::NumericVector treated_ids, Rcpp::NumericVector treated_ts);
RcppExport SEXP _PanelMatch_check_treated_units(SEXP compmatSEXP, SEXP compmat_row_unitsSEXP, SEXP compmat_colsSEXP, SEXP leadSEXP, SEXP treated_idsSEXP, SEXP treated_tsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::NumericMatrix >::type compmat(compmatSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type compmat_row_units(compmat_row_unitsSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type compmat_cols(compmat_colsSEXP);
    Rcpp::traits::input_parameter< int >::type lead(leadSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type treated_ids(treated_idsSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type treated_ts(treated_tsSEXP);
    rcpp_result_gen = Rcpp::wrap(check_treated_units(compmat, compmat_row_units, compmat_cols, lead, treated_ids, treated_ts));
    return rcpp_result_gen;
END_RCPP
}
// needs_renormalization
Rcpp::LogicalVector needs_renormalization(Rcpp::List set_index_list);
RcppExport SEXP _PanelMatch_needs_renormalization(SEXP set_index_listSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::List >::type set_index_list(set_index_listSEXP);
    rcpp_result_gen = Rcpp::wrap(needs_renormalization(set_index_list));
    return rcpp_result_gen;
END_RCPP
}
// equality_four_cpp
Rcpp::NumericVector equality_four_cpp(Rcpp::NumericMatrix Wit_vals, Rcpp::NumericVector y, Rcpp::NumericVector z);
RcppExport SEXP _PanelMatch_equality_four_cpp(SEXP Wit_valsSEXP, SEXP ySEXP, SEXP zSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::NumericMatrix >::type Wit_vals(Wit_valsSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type y(ySEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type z(zSEXP);
    rcpp_result_gen = Rcpp::wrap(equality_four_cpp(Wit_vals, y, z));
    return rcpp_result_gen;
END_RCPP
}
// get_vit_index_unsigned
std::vector<unsigned int> get_vit_index_unsigned(Rcpp::CharacterVector t_id_key, Rcpp::CharacterVector control_treatment_t_ids, Rcpp::NumericVector control_treatment_set_nums);
RcppExport SEXP _PanelMatch_get_vit_index_unsigned(SEXP t_id_keySEXP, SEXP control_treatment_t_idsSEXP, SEXP control_treatment_set_numsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type t_id_key(t_id_keySEXP);
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type control_treatment_t_ids(control_treatment_t_idsSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type control_treatment_set_nums(control_treatment_set_numsSEXP);
    rcpp_result_gen = Rcpp::wrap(get_vit_index_unsigned(t_id_key, control_treatment_t_ids, control_treatment_set_nums));
    return rcpp_result_gen;
END_RCPP
}
// handle_vits
Rcpp::NumericVector handle_vits(unsigned int nrow_data, unsigned int mset_size, unsigned int num_empty, Rcpp::NumericVector weights, Rcpp::CharacterVector tidkey, Rcpp::CharacterVector control_treatment_tids, Rcpp::NumericVector ct_set_nums);
RcppExport SEXP _PanelMatch_handle_vits(SEXP nrow_dataSEXP, SEXP mset_sizeSEXP, SEXP num_emptySEXP, SEXP weightsSEXP, SEXP tidkeySEXP, SEXP control_treatment_tidsSEXP, SEXP ct_set_numsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< unsigned int >::type nrow_data(nrow_dataSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type mset_size(mset_sizeSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type num_empty(num_emptySEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type weights(weightsSEXP);
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type tidkey(tidkeySEXP);
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type control_treatment_tids(control_treatment_tidsSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type ct_set_nums(ct_set_numsSEXP);
    rcpp_result_gen = Rcpp::wrap(handle_vits(nrow_data, mset_size, num_empty, weights, tidkey, control_treatment_tids, ct_set_nums));
    return rcpp_result_gen;
END_RCPP
}
// get_treated_indices
Rcpp::LogicalVector get_treated_indices(const Rcpp::NumericMatrix& ordered_df, const Rcpp::NumericVector& treated_indices, int treat_col_idx, int unit_var_col);
RcppExport SEXP _PanelMatch_get_treated_indices(SEXP ordered_dfSEXP, SEXP treated_indicesSEXP, SEXP treat_col_idxSEXP, SEXP unit_var_colSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Rcpp::NumericMatrix& >::type ordered_df(ordered_dfSEXP);
    Rcpp::traits::input_parameter< const Rcpp::NumericVector& >::type treated_indices(treated_indicesSEXP);
    Rcpp::traits::input_parameter< int >::type treat_col_idx(treat_col_idxSEXP);
    Rcpp::traits::input_parameter< int >::type unit_var_col(unit_var_colSEXP);
    rcpp_result_gen = Rcpp::wrap(get_treated_indices(ordered_df, treated_indices, treat_col_idx, unit_var_col));
    return rcpp_result_gen;
END_RCPP
}
// get_comparison_histories
Rcpp::List get_comparison_histories(const Rcpp::NumericMatrix& compmat, const Rcpp::NumericVector& ts, const Rcpp::NumericVector& ids, int t_col, int id_col, int L, int treat_col);
RcppExport SEXP _PanelMatch_get_comparison_histories(SEXP compmatSEXP, SEXP tsSEXP, SEXP idsSEXP, SEXP t_colSEXP, SEXP id_colSEXP, SEXP LSEXP, SEXP treat_colSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Rcpp::NumericMatrix& >::type compmat(compmatSEXP);
    Rcpp::traits::input_parameter< const Rcpp::NumericVector& >::type ts(tsSEXP);
    Rcpp::traits::input_parameter< const Rcpp::NumericVector& >::type ids(idsSEXP);
    Rcpp::traits::input_parameter< int >::type t_col(t_colSEXP);
    Rcpp::traits::input_parameter< int >::type id_col(id_colSEXP);
    Rcpp::traits::input_parameter< int >::type L(LSEXP);
    Rcpp::traits::input_parameter< int >::type treat_col(treat_colSEXP);
    rcpp_result_gen = Rcpp::wrap(get_comparison_histories(compmat, ts, ids, t_col, id_col, L, treat_col));
    return rcpp_result_gen;
END_RCPP
}
// get_msets_helper
Rcpp:: List get_msets_helper(const Rcpp::List& control_history_list, const Rcpp::NumericMatrix& widemat, const Rcpp::NumericVector& t_as_col_nums, const Rcpp::NumericVector& ids, int L);
RcppExport SEXP _PanelMatch_get_msets_helper(SEXP control_history_listSEXP, SEXP widematSEXP, SEXP t_as_col_numsSEXP, SEXP idsSEXP, SEXP LSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Rcpp::List& >::type control_history_list(control_history_listSEXP);
    Rcpp::traits::input_parameter< const Rcpp::NumericMatrix& >::type widemat(widematSEXP);
    Rcpp::traits::input_parameter< const Rcpp::NumericVector& >::type t_as_col_nums(t_as_col_numsSEXP);
    Rcpp::traits::input_parameter< const Rcpp::NumericVector& >::type ids(idsSEXP);
    Rcpp::traits::input_parameter< int >::type L(LSEXP);
    rcpp_result_gen = Rcpp::wrap(get_msets_helper(control_history_list, widemat, t_as_col_nums, ids, L));
    return rcpp_result_gen;
END_RCPP
}
// non_matching_matcher
Rcpp:: List non_matching_matcher(const Rcpp::List& control_history_list, const Rcpp::NumericMatrix& widemat, const Rcpp::NumericVector& t_as_col_nums, const Rcpp::NumericVector& ids, int L, int missing_window);
RcppExport SEXP _PanelMatch_non_matching_matcher(SEXP control_history_listSEXP, SEXP widematSEXP, SEXP t_as_col_numsSEXP, SEXP idsSEXP, SEXP LSEXP, SEXP missing_windowSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Rcpp::List& >::type control_history_list(control_history_listSEXP);
    Rcpp::traits::input_parameter< const Rcpp::NumericMatrix& >::type widemat(widematSEXP);
    Rcpp::traits::input_parameter< const Rcpp::NumericVector& >::type t_as_col_nums(t_as_col_numsSEXP);
    Rcpp::traits::input_parameter< const Rcpp::NumericVector& >::type ids(idsSEXP);
    Rcpp::traits::input_parameter< int >::type L(LSEXP);
    Rcpp::traits::input_parameter< int >::type missing_window(missing_windowSEXP);
    rcpp_result_gen = Rcpp::wrap(non_matching_matcher(control_history_list, widemat, t_as_col_nums, ids, L, missing_window));
    return rcpp_result_gen;
END_RCPP
}
// get_yearly_dmats
List get_yearly_dmats(NumericMatrix expanded_data, NumericVector treated_ids, List ts_to_fetch, CharacterVector row_key, List matched_sets, int lag);
RcppExport SEXP _PanelMatch_get_yearly_dmats(SEXP expanded_dataSEXP, SEXP treated_idsSEXP, SEXP ts_to_fetchSEXP, SEXP row_keySEXP, SEXP matched_setsSEXP, SEXP lagSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericMatrix >::type expanded_data(expanded_dataSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type treated_ids(treated_idsSEXP);
    Rcpp::traits::input_parameter< List >::type ts_to_fetch(ts_to_fetchSEXP);
    Rcpp::traits::input_parameter< CharacterVector >::type row_key(row_keySEXP);
    Rcpp::traits::input_parameter< List >::type matched_sets(matched_setsSEXP);
    Rcpp::traits::input_parameter< int >::type lag(lagSEXP);
    rcpp_result_gen = Rcpp::wrap(get_yearly_dmats(expanded_data, treated_ids, ts_to_fetch, row_key, matched_sets, lag));
    return rcpp_result_gen;
END_RCPP
}
// check_treated_units_for_treatment_reversion
Rcpp::LogicalVector check_treated_units_for_treatment_reversion(Rcpp::NumericMatrix compmat, Rcpp::NumericVector compmat_row_units, Rcpp::NumericVector compmat_cols, int lead, Rcpp::NumericVector treated_ids, Rcpp::NumericVector treated_ts);
RcppExport SEXP _PanelMatch_check_treated_units_for_treatment_reversion(SEXP compmatSEXP, SEXP compmat_row_unitsSEXP, SEXP compmat_colsSEXP, SEXP leadSEXP, SEXP treated_idsSEXP, SEXP treated_tsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::NumericMatrix >::type compmat(compmatSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type compmat_row_units(compmat_row_unitsSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type compmat_cols(compmat_colsSEXP);
    Rcpp::traits::input_parameter< int >::type lead(leadSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type treated_ids(treated_idsSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type treated_ts(treated_tsSEXP);
    rcpp_result_gen = Rcpp::wrap(check_treated_units_for_treatment_reversion(compmat, compmat_row_units, compmat_cols, lead, treated_ids, treated_ts));
    return rcpp_result_gen;
END_RCPP
}
// check_control_units_for_treatment_restriction
Rcpp::List check_control_units_for_treatment_restriction(Rcpp::NumericMatrix compmat, Rcpp::NumericVector compmat_row_units, Rcpp::NumericVector compmat_cols, int lead, Rcpp::List sets, Rcpp::NumericVector control_start_years);
RcppExport SEXP _PanelMatch_check_control_units_for_treatment_restriction(SEXP compmatSEXP, SEXP compmat_row_unitsSEXP, SEXP compmat_colsSEXP, SEXP leadSEXP, SEXP setsSEXP, SEXP control_start_yearsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::NumericMatrix >::type compmat(compmatSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type compmat_row_units(compmat_row_unitsSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type compmat_cols(compmat_colsSEXP);
    Rcpp::traits::input_parameter< int >::type lead(leadSEXP);
    Rcpp::traits::input_parameter< Rcpp::List >::type sets(setsSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type control_start_years(control_start_yearsSEXP);
    rcpp_result_gen = Rcpp::wrap(check_control_units_for_treatment_restriction(compmat, compmat_row_units, compmat_cols, lead, sets, control_start_years));
    return rcpp_result_gen;
END_RCPP
}
// multiply_weights_msm
Rcpp::List multiply_weights_msm(Rcpp::List weights, int number_of_sets);
RcppExport SEXP _PanelMatch_multiply_weights_msm(SEXP weightsSEXP, SEXP number_of_setsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::List >::type weights(weightsSEXP);
    Rcpp::traits::input_parameter< int >::type number_of_sets(number_of_setsSEXP);
    rcpp_result_gen = Rcpp::wrap(multiply_weights_msm(weights, number_of_sets));
    return rcpp_result_gen;
END_RCPP
}
// do_exact_matching_refinement
Rcpp::List do_exact_matching_refinement(Rcpp::NumericMatrix balanced_data, int lag, Rcpp::CharacterVector row_key, Rcpp::List control_data, Rcpp::CharacterVector treatment_data, Rcpp::IntegerVector exact_match_variable_column_index);
RcppExport SEXP _PanelMatch_do_exact_matching_refinement(SEXP balanced_dataSEXP, SEXP lagSEXP, SEXP row_keySEXP, SEXP control_dataSEXP, SEXP treatment_dataSEXP, SEXP exact_match_variable_column_indexSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::NumericMatrix >::type balanced_data(balanced_dataSEXP);
    Rcpp::traits::input_parameter< int >::type lag(lagSEXP);
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type row_key(row_keySEXP);
    Rcpp::traits::input_parameter< Rcpp::List >::type control_data(control_dataSEXP);
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type treatment_data(treatment_dataSEXP);
    Rcpp::traits::input_parameter< Rcpp::IntegerVector >::type exact_match_variable_column_index(exact_match_variable_column_indexSEXP);
    rcpp_result_gen = Rcpp::wrap(do_exact_matching_refinement(balanced_data, lag, row_key, control_data, treatment_data, exact_match_variable_column_index));
    return rcpp_result_gen;
END_RCPP
}
