// AUTOMATICALLY GENERATED BY RCPPDEEPSTATE PLEASE DO NOT EDIT BY HAND, INSTEAD EDIT
// bsplineCpp_DeepState_TestHarness_generation.cpp and bsplineCpp_DeepState_TestHarness_checks.cpp

#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector bsplineCpp(NumericVector xs, int ord, NumericVector kns, NumericVector coef);

TEST(ibs_deepstate_test,bsplineCpp_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector xs  = RcppDeepState_NumericVector();
  qs::c_qsave(xs,"/home/akhila/fuzzer_packages/fuzzedpackages/ibs/inst/testfiles/bsplineCpp/inputs/xs.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "xs values: "<< xs << std::endl;
  IntegerVector ord(1);
  ord[0]  = RcppDeepState_int();
  qs::c_qsave(ord,"/home/akhila/fuzzer_packages/fuzzedpackages/ibs/inst/testfiles/bsplineCpp/inputs/ord.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ord values: "<< ord << std::endl;
  NumericVector kns  = RcppDeepState_NumericVector();
  qs::c_qsave(kns,"/home/akhila/fuzzer_packages/fuzzedpackages/ibs/inst/testfiles/bsplineCpp/inputs/kns.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "kns values: "<< kns << std::endl;
  NumericVector coef  = RcppDeepState_NumericVector();
  qs::c_qsave(coef,"/home/akhila/fuzzer_packages/fuzzedpackages/ibs/inst/testfiles/bsplineCpp/inputs/coef.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "coef values: "<< coef << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    bsplineCpp(xs,ord[0],kns,coef);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
