// AUTOMATICALLY GENERATED BY RCPPDEEPSTATE PLEASE DO NOT EDIT BY HAND, INSTEAD EDIT
// c_Compute_M_from_MM_DeepState_TestHarness_generation.cpp and c_Compute_M_from_MM_DeepState_TestHarness_checks.cpp

#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List c_Compute_M_from_MM(NumericMatrix subMM);

TEST(HistDAWass_deepstate_test,c_Compute_M_from_MM_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix subMM  = RcppDeepState_NumericMatrix();
  qs::c_qsave(subMM,"/home/akhila/fuzzer_packages/fuzzedpackages/HistDAWass/inst/testfiles/c_Compute_M_from_MM/inputs/subMM.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "subMM values: "<< subMM << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    c_Compute_M_from_MM(subMM);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
