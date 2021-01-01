// AUTOMATICALLY GENERATED BY RCPPDEEPSTATE PLEASE DO NOT EDIT BY HAND, INSTEAD EDIT
// nonDomSet_DeepState_TestHarness_generation.cpp and nonDomSet_DeepState_TestHarness_checks.cpp

#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

LogicalVector nonDomSet(NumericMatrix points, NumericMatrix ref);

TEST(GPareto_deepstate_test,nonDomSet_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix points  = RcppDeepState_NumericMatrix();
  qs::c_qsave(points,"/home/akhila/fuzzer_packages/fuzzedpackages/GPareto/inst/testfiles/nonDomSet/inputs/points.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "points values: "<< points << std::endl;
  NumericMatrix ref  = RcppDeepState_NumericMatrix();
  qs::c_qsave(ref,"/home/akhila/fuzzer_packages/fuzzedpackages/GPareto/inst/testfiles/nonDomSet/inputs/ref.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ref values: "<< ref << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    nonDomSet(points,ref);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
