// AUTOMATICALLY GENERATED BY RCPPDEEPSTATE PLEASE DO NOT EDIT BY HAND, INSTEAD EDIT
// cpppar_exp_DeepState_TestHarness_generation.cpp and cpppar_exp_DeepState_TestHarness_checks.cpp

#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector cpppar_exp(NumericVector x, int nthreads);

TEST(fixest_deepstate_test,cpppar_exp_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  qs::c_qsave(x,"/home/akhila/fuzzer_packages/fuzzedpackages/fixest/inst/testfiles/cpppar_exp/inputs/x.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  IntegerVector nthreads(1);
  nthreads[0]  = RcppDeepState_int();
  qs::c_qsave(nthreads,"/home/akhila/fuzzer_packages/fuzzedpackages/fixest/inst/testfiles/cpppar_exp/inputs/nthreads.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nthreads values: "<< nthreads << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    cpppar_exp(x,nthreads[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
