#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector do_fill_gap_1d(NumericVector x, NumericVector rule);

TEST(oce_deepstate_test,do_fill_gap_1d_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_fill_gap_1d/AFL_do_fill_gap_1d/afl_inputs/" + std::to_string(t) + "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector rule  = RcppDeepState_NumericVector();
  std::string rule_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_fill_gap_1d/AFL_do_fill_gap_1d/afl_inputs/" + std::to_string(t) + "_rule.qs";
  qs::c_qsave(rule,rule_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "rule values: "<< rule << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    do_fill_gap_1d(x,rule);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
