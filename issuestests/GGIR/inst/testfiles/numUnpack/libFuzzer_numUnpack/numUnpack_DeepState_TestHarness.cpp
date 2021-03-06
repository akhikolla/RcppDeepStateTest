// AUTOMATICALLY GENERATED BY RCPPDEEPSTATE PLEASE DO NOT EDIT BY HAND, INSTEAD EDIT
// numUnpack_DeepState_TestHarness_generation.cpp and numUnpack_DeepState_TestHarness_checks.cpp

#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

IntegerMatrix numUnpack(IntegerVector pack);

TEST(GGIR_deepstate_test,numUnpack_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector pack  = RcppDeepState_IntegerVector();
  std::string pack_t = "/home/akhila/fuzzer_packages/fuzzedpackages/GGIR/inst/testfiles/numUnpack/libFuzzer_numUnpack/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_pack.qs";
  qs::c_qsave(pack,pack_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pack values: "<< pack << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    numUnpack(pack);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
