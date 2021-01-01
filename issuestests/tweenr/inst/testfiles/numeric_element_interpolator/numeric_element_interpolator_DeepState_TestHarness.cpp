// AUTOMATICALLY GENERATED BY RCPPDEEPSTATE PLEASE DO NOT EDIT BY HAND, INSTEAD EDIT
// numeric_element_interpolator_DeepState_TestHarness_generation.cpp and numeric_element_interpolator_DeepState_TestHarness_checks.cpp

#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

DataFrame numeric_element_interpolator(NumericVector data, CharacterVector group, IntegerVector frame, CharacterVector ease);

TEST(tweenr_deepstate_test,numeric_element_interpolator_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector data  = RcppDeepState_NumericVector();
  qs::c_qsave(data,"/home/akhila/fuzzer_packages/fuzzedpackages/tweenr/inst/testfiles/numeric_element_interpolator/inputs/data.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "data values: "<< data << std::endl;
  CharacterVector group  = RcppDeepState_CharacterVector();
  qs::c_qsave(group,"/home/akhila/fuzzer_packages/fuzzedpackages/tweenr/inst/testfiles/numeric_element_interpolator/inputs/group.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "group values: "<< group << std::endl;
  IntegerVector frame  = RcppDeepState_IntegerVector();
  qs::c_qsave(frame,"/home/akhila/fuzzer_packages/fuzzedpackages/tweenr/inst/testfiles/numeric_element_interpolator/inputs/frame.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "frame values: "<< frame << std::endl;
  CharacterVector ease  = RcppDeepState_CharacterVector();
  qs::c_qsave(ease,"/home/akhila/fuzzer_packages/fuzzedpackages/tweenr/inst/testfiles/numeric_element_interpolator/inputs/ease.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ease values: "<< ease << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    numeric_element_interpolator(data,group,frame,ease);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
