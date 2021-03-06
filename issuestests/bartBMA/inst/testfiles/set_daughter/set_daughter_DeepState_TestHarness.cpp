// AUTOMATICALLY GENERATED BY RCPPDEEPSTATE PLEASE DO NOT EDIT BY HAND, INSTEAD EDIT
// set_daughter_DeepState_TestHarness_generation.cpp and set_daughter_DeepState_TestHarness_checks.cpp

#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix set_daughter(int left_daughter, int right_daughter, IntegerVector ld_obs, IntegerVector rd_obs, NumericMatrix tree_matrix_temp, double term_cols);

TEST(bartBMA_deepstate_test,set_daughter_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector left_daughter(1);
  left_daughter[0]  = RcppDeepState_int();
  qs::c_qsave(left_daughter,"/home/akhila/fuzzer_packages/fuzzedpackages/bartBMA/inst/testfiles/set_daughter/inputs/left_daughter.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "left_daughter values: "<< left_daughter << std::endl;
  IntegerVector right_daughter(1);
  right_daughter[0]  = RcppDeepState_int();
  qs::c_qsave(right_daughter,"/home/akhila/fuzzer_packages/fuzzedpackages/bartBMA/inst/testfiles/set_daughter/inputs/right_daughter.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "right_daughter values: "<< right_daughter << std::endl;
  IntegerVector ld_obs  = RcppDeepState_IntegerVector();
  qs::c_qsave(ld_obs,"/home/akhila/fuzzer_packages/fuzzedpackages/bartBMA/inst/testfiles/set_daughter/inputs/ld_obs.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ld_obs values: "<< ld_obs << std::endl;
  IntegerVector rd_obs  = RcppDeepState_IntegerVector();
  qs::c_qsave(rd_obs,"/home/akhila/fuzzer_packages/fuzzedpackages/bartBMA/inst/testfiles/set_daughter/inputs/rd_obs.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "rd_obs values: "<< rd_obs << std::endl;
  NumericMatrix tree_matrix_temp  = RcppDeepState_NumericMatrix();
  qs::c_qsave(tree_matrix_temp,"/home/akhila/fuzzer_packages/fuzzedpackages/bartBMA/inst/testfiles/set_daughter/inputs/tree_matrix_temp.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tree_matrix_temp values: "<< tree_matrix_temp << std::endl;
  NumericVector term_cols(1);
  term_cols[0]  = RcppDeepState_double();
  qs::c_qsave(term_cols,"/home/akhila/fuzzer_packages/fuzzedpackages/bartBMA/inst/testfiles/set_daughter/inputs/term_cols.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "term_cols values: "<< term_cols << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    set_daughter(left_daughter[0],right_daughter[0],ld_obs,rd_obs,tree_matrix_temp,term_cols[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
