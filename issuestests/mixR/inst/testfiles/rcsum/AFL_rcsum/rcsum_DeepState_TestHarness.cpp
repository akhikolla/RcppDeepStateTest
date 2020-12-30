#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector rcsum(NumericMatrix x, int margin);

TEST(mixR_deepstate_test,rcsum_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix x  = RcppDeepState_NumericMatrix();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mixR/inst/testfiles/rcsum/AFL_rcsum/afl_inputs/" + std::to_string(t) + "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  IntegerVector margin(1);
  margin[0]  = RcppDeepState_int();
  std::string margin_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mixR/inst/testfiles/rcsum/AFL_rcsum/afl_inputs/" + std::to_string(t) + "_margin.qs";
  qs::c_qsave(margin,margin_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "margin values: "<< margin << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    rcsum(x,margin[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
