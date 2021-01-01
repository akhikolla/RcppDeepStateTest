// AUTOMATICALLY GENERATED BY RCPPDEEPSTATE PLEASE DO NOT EDIT BY HAND, INSTEAD EDIT
// cumsum_elp_DeepState_TestHarness_generation.cpp and cumsum_elp_DeepState_TestHarness_checks.cpp

#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector cumsum_elp(NumericVector left, NumericVector right, NumericVector elp, int maxlength);

TEST(frailtyEM_deepstate_test,cumsum_elp_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector left  = RcppDeepState_NumericVector();
  qs::c_qsave(left,"/home/akhila/fuzzer_packages/fuzzedpackages/frailtyEM/inst/testfiles/cumsum_elp/inputs/left.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "left values: "<< left << std::endl;
  NumericVector right  = RcppDeepState_NumericVector();
  qs::c_qsave(right,"/home/akhila/fuzzer_packages/fuzzedpackages/frailtyEM/inst/testfiles/cumsum_elp/inputs/right.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "right values: "<< right << std::endl;
  NumericVector elp  = RcppDeepState_NumericVector();
  qs::c_qsave(elp,"/home/akhila/fuzzer_packages/fuzzedpackages/frailtyEM/inst/testfiles/cumsum_elp/inputs/elp.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "elp values: "<< elp << std::endl;
  IntegerVector maxlength(1);
  maxlength[0]  = RcppDeepState_int();
  qs::c_qsave(maxlength,"/home/akhila/fuzzer_packages/fuzzedpackages/frailtyEM/inst/testfiles/cumsum_elp/inputs/maxlength.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "maxlength values: "<< maxlength << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    cumsum_elp(left,right,elp,maxlength[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
