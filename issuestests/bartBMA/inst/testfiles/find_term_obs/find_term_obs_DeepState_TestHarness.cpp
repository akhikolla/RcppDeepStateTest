// AUTOMATICALLY GENERATED BY RCPPDEEPSTATE PLEASE DO NOT EDIT BY HAND, INSTEAD EDIT
// find_term_obs_DeepState_TestHarness_generation.cpp and find_term_obs_DeepState_TestHarness_checks.cpp

#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

arma::uvec find_term_obs(NumericMatrix tree_matrix_temp, double terminal_node);

TEST(bartBMA_deepstate_test,find_term_obs_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix tree_matrix_temp  = RcppDeepState_NumericMatrix();
  qs::c_qsave(tree_matrix_temp,"/home/akhila/fuzzer_packages/fuzzedpackages/bartBMA/inst/testfiles/find_term_obs/inputs/tree_matrix_temp.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tree_matrix_temp values: "<< tree_matrix_temp << std::endl;
  NumericVector terminal_node(1);
  terminal_node[0]  = RcppDeepState_double();
  qs::c_qsave(terminal_node,"/home/akhila/fuzzer_packages/fuzzedpackages/bartBMA/inst/testfiles/find_term_obs/inputs/terminal_node.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "terminal_node values: "<< terminal_node << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    find_term_obs(tree_matrix_temp,terminal_node[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
