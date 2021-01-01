// AUTOMATICALLY GENERATED BY RCPPDEEPSTATE PLEASE DO NOT EDIT BY HAND, INSTEAD EDIT
// sb2_DeepState_TestHarness_generation.cpp and sb2_DeepState_TestHarness_checks.cpp

#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector sb2(NumericVector m1, NumericVector bg, IntegerVector d, IntegerVector e);

TEST(trackdem_deepstate_test,sb2_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector m1  = RcppDeepState_NumericVector();
  qs::c_qsave(m1,"/home/akhila/fuzzer_packages/fuzzedpackages/trackdem/inst/testfiles/sb2/inputs/m1.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "m1 values: "<< m1 << std::endl;
  NumericVector bg  = RcppDeepState_NumericVector();
  qs::c_qsave(bg,"/home/akhila/fuzzer_packages/fuzzedpackages/trackdem/inst/testfiles/sb2/inputs/bg.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "bg values: "<< bg << std::endl;
  IntegerVector d  = RcppDeepState_IntegerVector();
  qs::c_qsave(d,"/home/akhila/fuzzer_packages/fuzzedpackages/trackdem/inst/testfiles/sb2/inputs/d.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "d values: "<< d << std::endl;
  IntegerVector e  = RcppDeepState_IntegerVector();
  qs::c_qsave(e,"/home/akhila/fuzzer_packages/fuzzedpackages/trackdem/inst/testfiles/sb2/inputs/e.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "e values: "<< e << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    sb2(m1,bg,d,e);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
