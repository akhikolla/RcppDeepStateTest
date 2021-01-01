// AUTOMATICALLY GENERATED BY RCPPDEEPSTATE PLEASE DO NOT EDIT BY HAND, INSTEAD EDIT
// parse_names_DeepState_TestHarness_generation.cpp and parse_names_DeepState_TestHarness_checks.cpp

#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

DataFrame parse_names(CharacterVector names);

TEST(humaniformat_deepstate_test,parse_names_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  CharacterVector names  = RcppDeepState_CharacterVector();
  qs::c_qsave(names,"/home/akhila/fuzzer_packages/fuzzedpackages/humaniformat/inst/testfiles/parse_names/inputs/names.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "names values: "<< names << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    parse_names(names);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
