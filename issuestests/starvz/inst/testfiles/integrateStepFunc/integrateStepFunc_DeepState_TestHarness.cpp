// AUTOMATICALLY GENERATED BY RCPPDEEPSTATE PLEASE DO NOT EDIT BY HAND, INSTEAD EDIT
// integrateStepFunc_DeepState_TestHarness_generation.cpp and integrateStepFunc_DeepState_TestHarness_checks.cpp

#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector integrateStepFunc(NumericVector x, NumericVector bounds, NumericVector values);

TEST(starvz_deepstate_test,integrateStepFunc_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  qs::c_qsave(x,"/home/akhila/fuzzer_packages/fuzzedpackages/starvz/inst/testfiles/integrateStepFunc/inputs/x.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector bounds  = RcppDeepState_NumericVector();
  qs::c_qsave(bounds,"/home/akhila/fuzzer_packages/fuzzedpackages/starvz/inst/testfiles/integrateStepFunc/inputs/bounds.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "bounds values: "<< bounds << std::endl;
  NumericVector values  = RcppDeepState_NumericVector();
  qs::c_qsave(values,"/home/akhila/fuzzer_packages/fuzzedpackages/starvz/inst/testfiles/integrateStepFunc/inputs/values.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "values values: "<< values << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    integrateStepFunc(x,bounds,values);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
