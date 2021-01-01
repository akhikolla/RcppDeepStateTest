// AUTOMATICALLY GENERATED BY RCPPDEEPSTATE PLEASE DO NOT EDIT BY HAND, INSTEAD EDIT
// AllNeighboursTri__DeepState_TestHarness_generation.cpp and AllNeighboursTri__DeepState_TestHarness_checks.cpp

#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix AllNeighboursTri_(NumericMatrix allFaces, NumericVector div);

TEST(icosa_deepstate_test,AllNeighboursTri__test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix allFaces  = RcppDeepState_NumericMatrix();
  qs::c_qsave(allFaces,"/home/akhila/fuzzer_packages/fuzzedpackages/icosa/inst/testfiles/AllNeighboursTri_/inputs/allFaces.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "allFaces values: "<< allFaces << std::endl;
  NumericVector div  = RcppDeepState_NumericVector();
  qs::c_qsave(div,"/home/akhila/fuzzer_packages/fuzzedpackages/icosa/inst/testfiles/AllNeighboursTri_/inputs/div.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "div values: "<< div << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    AllNeighboursTri_(allFaces,div);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
