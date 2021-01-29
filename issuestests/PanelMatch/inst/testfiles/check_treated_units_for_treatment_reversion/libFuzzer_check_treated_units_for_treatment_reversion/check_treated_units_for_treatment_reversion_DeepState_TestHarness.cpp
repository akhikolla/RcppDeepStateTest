#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::LogicalVector check_treated_units_for_treatment_reversion(Rcpp::NumericMatrix compmat, Rcpp::NumericVector compmat_row_units, Rcpp::NumericVector compmat_cols, int lead, Rcpp::NumericVector treated_ids, Rcpp::NumericVector treated_ts);

TEST(PanelMatch_deepstate_test,check_treated_units_for_treatment_reversion_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix compmat  = RcppDeepState_NumericMatrix();
  std::string compmat_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PanelMatch/inst/testfiles/check_treated_units_for_treatment_reversion/libFuzzer_check_treated_units_for_treatment_reversion/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_compmat.qs";
  qs::c_qsave(compmat,compmat_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "compmat values: "<< compmat << std::endl;
  NumericVector compmat_row_units  = RcppDeepState_NumericVector();
  std::string compmat_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PanelMatch/inst/testfiles/check_treated_units_for_treatment_reversion/libFuzzer_check_treated_units_for_treatment_reversion/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_compmat.qs";
  std::string compmat_row_units_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PanelMatch/inst/testfiles/check_treated_units_for_treatment_reversion/libFuzzer_check_treated_units_for_treatment_reversion/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_compmat_row_units.qs";
  qs::c_qsave(compmat_row_units,compmat_row_units_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "compmat_row_units values: "<< compmat_row_units << std::endl;
  NumericVector compmat_cols  = RcppDeepState_NumericVector();
  std::string compmat_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PanelMatch/inst/testfiles/check_treated_units_for_treatment_reversion/libFuzzer_check_treated_units_for_treatment_reversion/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_compmat.qs";
  std::string compmat_cols_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PanelMatch/inst/testfiles/check_treated_units_for_treatment_reversion/libFuzzer_check_treated_units_for_treatment_reversion/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_compmat_cols.qs";
  qs::c_qsave(compmat_cols,compmat_cols_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "compmat_cols values: "<< compmat_cols << std::endl;
  IntegerVector lead(1);
  lead[0]  = RcppDeepState_int();
  std::string lead_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PanelMatch/inst/testfiles/check_treated_units_for_treatment_reversion/libFuzzer_check_treated_units_for_treatment_reversion/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_lead.qs";
  qs::c_qsave(lead,lead_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lead values: "<< lead << std::endl;
  NumericVector treated_ids  = RcppDeepState_NumericVector();
  std::string treated_ids_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PanelMatch/inst/testfiles/check_treated_units_for_treatment_reversion/libFuzzer_check_treated_units_for_treatment_reversion/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_treated_ids.qs";
  qs::c_qsave(treated_ids,treated_ids_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "treated_ids values: "<< treated_ids << std::endl;
  NumericVector treated_ts  = RcppDeepState_NumericVector();
  std::string treated_ts_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PanelMatch/inst/testfiles/check_treated_units_for_treatment_reversion/libFuzzer_check_treated_units_for_treatment_reversion/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_treated_ts.qs";
  qs::c_qsave(treated_ts,treated_ts_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "treated_ts values: "<< treated_ts << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    check_treated_units_for_treatment_reversion(compmat,compmat_row_units,compmat_cols,lead[0],treated_ids,treated_ts);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
