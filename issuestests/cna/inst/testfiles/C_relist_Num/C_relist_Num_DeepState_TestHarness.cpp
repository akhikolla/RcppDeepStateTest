// AUTOMATICALLY GENERATED BY RCPPDEEPSTATE PLEASE DO NOT EDIT BY HAND, INSTEAD EDIT
// C_relist_Num_DeepState_TestHarness_generation.cpp and C_relist_Num_DeepState_TestHarness_checks.cpp

#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List C_relist_Num(const NumericVector x, const IntegerVector l);

TEST(cna_deepstate_test,C_relist_Num_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  qs::c_qsave(x,"/home/akhila/fuzzer_packages/fuzzedpackages/cna/inst/testfiles/C_relist_Num/inputs/x.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  IntegerVector l  = RcppDeepState_IntegerVector();
  qs::c_qsave(l,"/home/akhila/fuzzer_packages/fuzzedpackages/cna/inst/testfiles/C_relist_Num/inputs/l.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "l values: "<< l << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    C_relist_Num(x,l);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
