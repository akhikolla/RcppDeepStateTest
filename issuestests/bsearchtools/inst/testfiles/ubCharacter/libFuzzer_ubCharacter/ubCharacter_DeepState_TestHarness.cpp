#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

int ubCharacter(Rcpp::CharacterVector sortedValues, Rcpp::CharacterVector valueToSearch);

TEST(bsearchtools_deepstate_test,ubCharacter_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  CharacterVector sortedValues  = RcppDeepState_CharacterVector();
  std::string sortedValues_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/bsearchtools/inst/testfiles/ubCharacter/libFuzzer_ubCharacter/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_sortedValues.qs";
  qs::c_qsave(sortedValues,sortedValues_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "sortedValues values: "<< sortedValues << std::endl;
  CharacterVector valueToSearch  = RcppDeepState_CharacterVector();
  std::string valueToSearch_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/bsearchtools/inst/testfiles/ubCharacter/libFuzzer_ubCharacter/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_valueToSearch.qs";
  qs::c_qsave(valueToSearch,valueToSearch_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "valueToSearch values: "<< valueToSearch << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    ubCharacter(sortedValues,valueToSearch);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
