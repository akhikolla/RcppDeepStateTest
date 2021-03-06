#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

bool hasSingleton(Rcpp::IntegerVector ances);

TEST(phylobase_deepstate_test,hasSingleton_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector ances  = RcppDeepState_IntegerVector();
  std::string ances_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/phylobase/inst/testfiles/hasSingleton/AFL_hasSingleton/afl_inputs/" + std::to_string(t) + "_ances.qs";
  qs::c_qsave(ances,ances_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ances values: "<< ances << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    hasSingleton(ances);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
