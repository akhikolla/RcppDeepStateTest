#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

int ubNumeric(Rcpp::NumericVector sortedValues, double valueToSearch);

TEST(bsearchtools_deepstate_test,ubNumeric_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector sortedValues  = RcppDeepState_NumericVector();
  std::string sortedValues_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/bsearchtools/inst/testfiles/ubNumeric/libFuzzer_ubNumeric/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_sortedValues.qs";
  qs::c_qsave(sortedValues,sortedValues_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "sortedValues values: "<< sortedValues << std::endl;
  NumericVector valueToSearch(1);
  valueToSearch[0]  = RcppDeepState_double();
  std::string valueToSearch_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/bsearchtools/inst/testfiles/ubNumeric/libFuzzer_ubNumeric/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_valueToSearch.qs";
  qs::c_qsave(valueToSearch,valueToSearch_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "valueToSearch values: "<< valueToSearch << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    ubNumeric(sortedValues,valueToSearch[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
