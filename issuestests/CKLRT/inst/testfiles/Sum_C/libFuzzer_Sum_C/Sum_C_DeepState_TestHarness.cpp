// AUTOMATICALLY GENERATED BY RCPPDEEPSTATE PLEASE DO NOT EDIT BY HAND, INSTEAD EDIT
// Sum_C_DeepState_TestHarness_generation.cpp and Sum_C_DeepState_TestHarness_checks.cpp

#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double Sum_C(NumericVector AA);

TEST(CKLRT_deepstate_test,Sum_C_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector AA  = RcppDeepState_NumericVector();
  std::string AA_t = "/home/akhila/fuzzer_packages/fuzzedpackages/CKLRT/inst/testfiles/Sum_C/libFuzzer_Sum_C/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_AA.qs";
  qs::c_qsave(AA,AA_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "AA values: "<< AA << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    Sum_C(AA);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
