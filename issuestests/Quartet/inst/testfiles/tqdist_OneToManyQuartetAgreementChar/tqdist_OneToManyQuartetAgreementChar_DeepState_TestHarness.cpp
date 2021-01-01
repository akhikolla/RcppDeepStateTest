// AUTOMATICALLY GENERATED BY RCPPDEEPSTATE PLEASE DO NOT EDIT BY HAND, INSTEAD EDIT
// tqdist_OneToManyQuartetAgreementChar_DeepState_TestHarness_generation.cpp and tqdist_OneToManyQuartetAgreementChar_DeepState_TestHarness_checks.cpp

#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

IntegerVector tqdist_OneToManyQuartetAgreementChar(CharacterVector tree, CharacterVector trees);

TEST(Quartet_deepstate_test,tqdist_OneToManyQuartetAgreementChar_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  CharacterVector tree  = RcppDeepState_CharacterVector();
  qs::c_qsave(tree,"/home/akhila/fuzzer_packages/fuzzedpackages/Quartet/inst/testfiles/tqdist_OneToManyQuartetAgreementChar/inputs/tree.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tree values: "<< tree << std::endl;
  CharacterVector trees  = RcppDeepState_CharacterVector();
  qs::c_qsave(trees,"/home/akhila/fuzzer_packages/fuzzedpackages/Quartet/inst/testfiles/tqdist_OneToManyQuartetAgreementChar/inputs/trees.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "trees values: "<< trees << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    tqdist_OneToManyQuartetAgreementChar(tree,trees);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
