#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

int lbCharacter(Rcpp::CharacterVector sortedValues, Rcpp::CharacterVector valueToSearch);

TEST(bsearchtools_deepstate_test,lbCharacter_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  CharacterVector sortedValues  = RcppDeepState_CharacterVector();
  qs::c_qsave(sortedValues,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/bsearchtools/inst/testfiles/lbCharacter/inputs/sortedValues.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "sortedValues values: "<< sortedValues << std::endl;
  CharacterVector valueToSearch  = RcppDeepState_CharacterVector();
  qs::c_qsave(valueToSearch,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/bsearchtools/inst/testfiles/lbCharacter/inputs/valueToSearch.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "valueToSearch values: "<< valueToSearch << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    lbCharacter(sortedValues,valueToSearch);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
