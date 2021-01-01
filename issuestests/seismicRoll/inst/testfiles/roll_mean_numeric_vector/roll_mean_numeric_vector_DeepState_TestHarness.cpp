// AUTOMATICALLY GENERATED BY RCPPDEEPSTATE PLEASE DO NOT EDIT BY HAND, INSTEAD EDIT
// roll_mean_numeric_vector_DeepState_TestHarness_generation.cpp and roll_mean_numeric_vector_DeepState_TestHarness_checks.cpp

#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector roll_mean_numeric_vector(NumericVector x, int n, int increment, int alignCode);

TEST(seismicRoll_deepstate_test,roll_mean_numeric_vector_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  qs::c_qsave(x,"/home/akhila/fuzzer_packages/fuzzedpackages/seismicRoll/inst/testfiles/roll_mean_numeric_vector/inputs/x.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  IntegerVector n(1);
  n[0]  = RcppDeepState_int();
  qs::c_qsave(n,"/home/akhila/fuzzer_packages/fuzzedpackages/seismicRoll/inst/testfiles/roll_mean_numeric_vector/inputs/n.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n values: "<< n << std::endl;
  IntegerVector increment(1);
  increment[0]  = RcppDeepState_int();
  qs::c_qsave(increment,"/home/akhila/fuzzer_packages/fuzzedpackages/seismicRoll/inst/testfiles/roll_mean_numeric_vector/inputs/increment.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "increment values: "<< increment << std::endl;
  IntegerVector alignCode(1);
  alignCode[0]  = RcppDeepState_int();
  qs::c_qsave(alignCode,"/home/akhila/fuzzer_packages/fuzzedpackages/seismicRoll/inst/testfiles/roll_mean_numeric_vector/inputs/alignCode.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "alignCode values: "<< alignCode << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    roll_mean_numeric_vector(x,n[0],increment[0],alignCode[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
