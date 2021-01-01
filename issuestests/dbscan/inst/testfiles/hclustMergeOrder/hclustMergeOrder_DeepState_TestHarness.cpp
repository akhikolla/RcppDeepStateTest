// AUTOMATICALLY GENERATED BY RCPPDEEPSTATE PLEASE DO NOT EDIT BY HAND, INSTEAD EDIT
// hclustMergeOrder_DeepState_TestHarness_generation.cpp and hclustMergeOrder_DeepState_TestHarness_checks.cpp

#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List hclustMergeOrder(NumericMatrix mst, IntegerVector o);

TEST(dbscan_deepstate_test,hclustMergeOrder_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix mst  = RcppDeepState_NumericMatrix();
  qs::c_qsave(mst,"/home/akhila/fuzzer_packages/fuzzedpackages/dbscan/inst/testfiles/hclustMergeOrder/inputs/mst.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "mst values: "<< mst << std::endl;
  IntegerVector o  = RcppDeepState_IntegerVector();
  qs::c_qsave(o,"/home/akhila/fuzzer_packages/fuzzedpackages/dbscan/inst/testfiles/hclustMergeOrder/inputs/o.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "o values: "<< o << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    hclustMergeOrder(mst,o);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
