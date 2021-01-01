// AUTOMATICALLY GENERATED BY RCPPDEEPSTATE PLEASE DO NOT EDIT BY HAND, INSTEAD EDIT
// cpp_table_DeepState_TestHarness_generation.cpp and cpp_table_DeepState_TestHarness_checks.cpp

#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector cpp_table(int Q, IntegerVector dum);

TEST(FENmlm_deepstate_test,cpp_table_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector Q(1);
  Q[0]  = RcppDeepState_int();
  qs::c_qsave(Q,"/home/akhila/fuzzer_packages/fuzzedpackages/FENmlm/inst/testfiles/cpp_table/inputs/Q.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Q values: "<< Q << std::endl;
  IntegerVector dum  = RcppDeepState_IntegerVector();
  qs::c_qsave(dum,"/home/akhila/fuzzer_packages/fuzzedpackages/FENmlm/inst/testfiles/cpp_table/inputs/dum.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "dum values: "<< dum << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    cpp_table(Q[0],dum);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
