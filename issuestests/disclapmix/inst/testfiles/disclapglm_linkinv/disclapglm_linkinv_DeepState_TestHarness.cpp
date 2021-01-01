// AUTOMATICALLY GENERATED BY RCPPDEEPSTATE PLEASE DO NOT EDIT BY HAND, INSTEAD EDIT
// disclapglm_linkinv_DeepState_TestHarness_generation.cpp and disclapglm_linkinv_DeepState_TestHarness_checks.cpp

#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector disclapglm_linkinv(NumericVector eta);

TEST(disclapmix_deepstate_test,disclapglm_linkinv_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector eta  = RcppDeepState_NumericVector();
  qs::c_qsave(eta,"/home/akhila/fuzzer_packages/fuzzedpackages/disclapmix/inst/testfiles/disclapglm_linkinv/inputs/eta.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "eta values: "<< eta << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    disclapglm_linkinv(eta);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
