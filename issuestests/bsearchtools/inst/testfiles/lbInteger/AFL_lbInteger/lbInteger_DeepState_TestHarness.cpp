#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

int lbInteger(Rcpp::IntegerVector sortedValues, int valueToSearch);

TEST(bsearchtools_deepstate_test,lbInteger_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector sortedValues  = RcppDeepState_IntegerVector();
  std::string sortedValues_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/bsearchtools/inst/testfiles/lbInteger/AFL_lbInteger/afl_inputs/" + std::to_string(t) + "_sortedValues.qs";
  qs::c_qsave(sortedValues,sortedValues_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "sortedValues values: "<< sortedValues << std::endl;
  IntegerVector valueToSearch(1);
  valueToSearch[0]  = RcppDeepState_int();
  std::string valueToSearch_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/bsearchtools/inst/testfiles/lbInteger/AFL_lbInteger/afl_inputs/" + std::to_string(t) + "_valueToSearch.qs";
  qs::c_qsave(valueToSearch,valueToSearch_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "valueToSearch values: "<< valueToSearch << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    lbInteger(sortedValues,valueToSearch[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
