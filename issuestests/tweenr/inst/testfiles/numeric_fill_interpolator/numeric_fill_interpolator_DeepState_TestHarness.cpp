// AUTOMATICALLY GENERATED BY RCPPDEEPSTATE PLEASE DO NOT EDIT BY HAND, INSTEAD EDIT
// numeric_fill_interpolator_DeepState_TestHarness_generation.cpp and numeric_fill_interpolator_DeepState_TestHarness_checks.cpp

#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector numeric_fill_interpolator(NumericVector data, CharacterVector ease);

TEST(tweenr_deepstate_test,numeric_fill_interpolator_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector data  = RcppDeepState_NumericVector();
  qs::c_qsave(data,"/home/akhila/fuzzer_packages/fuzzedpackages/tweenr/inst/testfiles/numeric_fill_interpolator/inputs/data.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "data values: "<< data << std::endl;
  CharacterVector ease  = RcppDeepState_CharacterVector();
  qs::c_qsave(ease,"/home/akhila/fuzzer_packages/fuzzedpackages/tweenr/inst/testfiles/numeric_fill_interpolator/inputs/ease.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ease values: "<< ease << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    numeric_fill_interpolator(data,ease);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
