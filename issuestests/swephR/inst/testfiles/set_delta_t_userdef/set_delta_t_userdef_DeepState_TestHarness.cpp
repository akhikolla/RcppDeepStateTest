// AUTOMATICALLY GENERATED BY RCPPDEEPSTATE PLEASE DO NOT EDIT BY HAND, INSTEAD EDIT
// set_delta_t_userdef_DeepState_TestHarness_generation.cpp and set_delta_t_userdef_DeepState_TestHarness_checks.cpp

#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

void set_delta_t_userdef(double delta_t);

TEST(swephR_deepstate_test,set_delta_t_userdef_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector delta_t(1);
  delta_t[0]  = RcppDeepState_double();
  qs::c_qsave(delta_t,"/home/akhila/fuzzer_packages/fuzzedpackages/swephR/inst/testfiles/set_delta_t_userdef/inputs/delta_t.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "delta_t values: "<< delta_t << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    set_delta_t_userdef(delta_t[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
