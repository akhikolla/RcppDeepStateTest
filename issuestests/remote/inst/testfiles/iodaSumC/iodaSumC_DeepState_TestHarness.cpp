// AUTOMATICALLY GENERATED BY RCPPDEEPSTATE PLEASE DO NOT EDIT BY HAND, INSTEAD EDIT
// iodaSumC_DeepState_TestHarness_generation.cpp and iodaSumC_DeepState_TestHarness_checks.cpp

#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector iodaSumC(NumericMatrix pred_vals, NumericMatrix resp_vals);

TEST(remote_deepstate_test,iodaSumC_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix pred_vals  = RcppDeepState_NumericMatrix();
  qs::c_qsave(pred_vals,"/home/akhila/fuzzer_packages/fuzzedpackages/remote/inst/testfiles/iodaSumC/inputs/pred_vals.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pred_vals values: "<< pred_vals << std::endl;
  NumericMatrix resp_vals  = RcppDeepState_NumericMatrix();
  qs::c_qsave(resp_vals,"/home/akhila/fuzzer_packages/fuzzedpackages/remote/inst/testfiles/iodaSumC/inputs/resp_vals.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "resp_vals values: "<< resp_vals << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    iodaSumC(pred_vals,resp_vals);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
