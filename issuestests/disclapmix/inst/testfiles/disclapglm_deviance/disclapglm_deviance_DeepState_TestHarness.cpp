// AUTOMATICALLY GENERATED BY RCPPDEEPSTATE PLEASE DO NOT EDIT BY HAND, INSTEAD EDIT
// disclapglm_deviance_DeepState_TestHarness_generation.cpp and disclapglm_deviance_DeepState_TestHarness_checks.cpp

#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double disclapglm_deviance(NumericVector y, NumericVector mu, NumericVector wt);

TEST(disclapmix_deepstate_test,disclapglm_deviance_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  qs::c_qsave(y,"/home/akhila/fuzzer_packages/fuzzedpackages/disclapmix/inst/testfiles/disclapglm_deviance/inputs/y.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericVector mu  = RcppDeepState_NumericVector();
  qs::c_qsave(mu,"/home/akhila/fuzzer_packages/fuzzedpackages/disclapmix/inst/testfiles/disclapglm_deviance/inputs/mu.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "mu values: "<< mu << std::endl;
  NumericVector wt  = RcppDeepState_NumericVector();
  qs::c_qsave(wt,"/home/akhila/fuzzer_packages/fuzzedpackages/disclapmix/inst/testfiles/disclapglm_deviance/inputs/wt.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "wt values: "<< wt << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    disclapglm_deviance(y,mu,wt);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
