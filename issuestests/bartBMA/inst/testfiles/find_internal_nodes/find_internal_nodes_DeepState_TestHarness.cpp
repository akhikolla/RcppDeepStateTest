// AUTOMATICALLY GENERATED BY RCPPDEEPSTATE PLEASE DO NOT EDIT BY HAND, INSTEAD EDIT
// find_internal_nodes_DeepState_TestHarness_generation.cpp and find_internal_nodes_DeepState_TestHarness_checks.cpp

#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

arma::uvec find_internal_nodes(NumericMatrix treetable);

TEST(bartBMA_deepstate_test,find_internal_nodes_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix treetable  = RcppDeepState_NumericMatrix();
  qs::c_qsave(treetable,"/home/akhila/fuzzer_packages/fuzzedpackages/bartBMA/inst/testfiles/find_internal_nodes/inputs/treetable.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "treetable values: "<< treetable << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    find_internal_nodes(treetable);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
