#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::IntegerVector int_randomShuffle(Rcpp::IntegerVector a);

TEST(BoostMLR_deepstate_test,int_randomShuffle_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector a  = RcppDeepState_IntegerVector();
  std::string a_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BoostMLR/inst/testfiles/int_randomShuffle/AFL_int_randomShuffle/afl_inputs/" + std::to_string(t) + "_a.qs";
  qs::c_qsave(a,a_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "a values: "<< a << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    int_randomShuffle(a);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
