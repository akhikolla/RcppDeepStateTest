// AUTOMATICALLY GENERATED BY RCPPDEEPSTATE PLEASE DO NOT EDIT BY HAND, INSTEAD EDIT
// cpp_ssq_DeepState_TestHarness_generation.cpp and cpp_ssq_DeepState_TestHarness_checks.cpp

#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double cpp_ssq(NumericVector x, NumericVector w);

TEST(fixest_deepstate_test,cpp_ssq_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  qs::c_qsave(x,"/home/akhila/fuzzer_packages/fuzzedpackages/fixest/inst/testfiles/cpp_ssq/inputs/x.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector w  = RcppDeepState_NumericVector();
  qs::c_qsave(w,"/home/akhila/fuzzer_packages/fuzzedpackages/fixest/inst/testfiles/cpp_ssq/inputs/w.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "w values: "<< w << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    cpp_ssq(x,w);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
