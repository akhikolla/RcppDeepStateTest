#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector diff_rcpp(NumericVector xs);

TEST(amt_deepstate_test,diff_rcpp_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector xs  = RcppDeepState_NumericVector();
  std::string xs_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/diff_rcpp/AFL_diff_rcpp/afl_inputs/" + std::to_string(t) + "_xs.qs";
  qs::c_qsave(xs,xs_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "xs values: "<< xs << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    diff_rcpp(xs);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
