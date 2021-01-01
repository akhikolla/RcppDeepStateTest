// AUTOMATICALLY GENERATED BY RCPPDEEPSTATE PLEASE DO NOT EDIT BY HAND, INSTEAD EDIT
// graphs_find_subgraphs_DeepState_TestHarness_generation.cpp and graphs_find_subgraphs_DeepState_TestHarness_checks.cpp

#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

IntegerVector graphs_find_subgraphs(IntegerVector id_1, IntegerVector id_2, int verbose);

TEST(dsmisc_deepstate_test,graphs_find_subgraphs_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector id_1  = RcppDeepState_IntegerVector();
  qs::c_qsave(id_1,"/home/akhila/fuzzer_packages/fuzzedpackages/dsmisc/inst/testfiles/graphs_find_subgraphs/inputs/id_1.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "id_1 values: "<< id_1 << std::endl;
  IntegerVector id_2  = RcppDeepState_IntegerVector();
  qs::c_qsave(id_2,"/home/akhila/fuzzer_packages/fuzzedpackages/dsmisc/inst/testfiles/graphs_find_subgraphs/inputs/id_2.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "id_2 values: "<< id_2 << std::endl;
  IntegerVector verbose(1);
  verbose[0]  = RcppDeepState_int();
  qs::c_qsave(verbose,"/home/akhila/fuzzer_packages/fuzzedpackages/dsmisc/inst/testfiles/graphs_find_subgraphs/inputs/verbose.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "verbose values: "<< verbose << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    graphs_find_subgraphs(id_1,id_2,verbose[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
