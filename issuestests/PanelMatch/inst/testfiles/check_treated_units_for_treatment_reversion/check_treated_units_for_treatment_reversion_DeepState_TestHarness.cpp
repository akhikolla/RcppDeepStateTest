#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::LogicalVector check_treated_units_for_treatment_reversion(Rcpp::NumericMatrix compmat, Rcpp::NumericVector compmat_row_units, Rcpp::NumericVector compmat_cols, int lead, Rcpp::NumericVector treated_ids, Rcpp::NumericVector treated_ts);

TEST(PanelMatch_deepstate_test,check_treated_units_for_treatment_reversion_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix compmat  = RcppDeepState_NumericMatrix();
  qs::c_qsave(compmat,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PanelMatch/inst/testfiles/check_treated_units_for_treatment_reversion/inputs/compmat.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "compmat values: "<< compmat << std::endl;
  NumericVector compmat_row_units  = RcppDeepState_NumericVector();
  qs::c_qsave(compmat_row_units,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PanelMatch/inst/testfiles/check_treated_units_for_treatment_reversion/inputs/compmat_row_units.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "compmat_row_units values: "<< compmat_row_units << std::endl;
  NumericVector compmat_cols  = RcppDeepState_NumericVector();
  qs::c_qsave(compmat_cols,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PanelMatch/inst/testfiles/check_treated_units_for_treatment_reversion/inputs/compmat_cols.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "compmat_cols values: "<< compmat_cols << std::endl;
  IntegerVector lead(1);
  lead[0]  = RcppDeepState_int();
  qs::c_qsave(lead,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PanelMatch/inst/testfiles/check_treated_units_for_treatment_reversion/inputs/lead.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lead values: "<< lead << std::endl;
  NumericVector treated_ids  = RcppDeepState_NumericVector();
  qs::c_qsave(treated_ids,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PanelMatch/inst/testfiles/check_treated_units_for_treatment_reversion/inputs/treated_ids.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "treated_ids values: "<< treated_ids << std::endl;
  NumericVector treated_ts  = RcppDeepState_NumericVector();
  qs::c_qsave(treated_ts,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PanelMatch/inst/testfiles/check_treated_units_for_treatment_reversion/inputs/treated_ts.qs",
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
