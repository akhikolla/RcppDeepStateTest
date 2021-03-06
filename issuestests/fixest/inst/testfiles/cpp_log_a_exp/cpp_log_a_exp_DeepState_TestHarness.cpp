// AUTOMATICALLY GENERATED BY RCPPDEEPSTATE PLEASE DO NOT EDIT BY HAND, INSTEAD EDIT
// cpp_log_a_exp_DeepState_TestHarness_generation.cpp and cpp_log_a_exp_DeepState_TestHarness_checks.cpp

#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector cpp_log_a_exp(double a, NumericVector mu, NumericVector exp_mu);

TEST(fixest_deepstate_test,cpp_log_a_exp_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector a(1);
  a[0]  = RcppDeepState_double();
  qs::c_qsave(a,"/home/akhila/fuzzer_packages/fuzzedpackages/fixest/inst/testfiles/cpp_log_a_exp/inputs/a.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "a values: "<< a << std::endl;
  NumericVector mu  = RcppDeepState_NumericVector();
  qs::c_qsave(mu,"/home/akhila/fuzzer_packages/fuzzedpackages/fixest/inst/testfiles/cpp_log_a_exp/inputs/mu.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "mu values: "<< mu << std::endl;
  NumericVector exp_mu  = RcppDeepState_NumericVector();
  qs::c_qsave(exp_mu,"/home/akhila/fuzzer_packages/fuzzedpackages/fixest/inst/testfiles/cpp_log_a_exp/inputs/exp_mu.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "exp_mu values: "<< exp_mu << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    cpp_log_a_exp(a[0],mu,exp_mu);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
