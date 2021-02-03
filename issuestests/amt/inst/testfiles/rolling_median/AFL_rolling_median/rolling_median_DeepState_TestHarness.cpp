#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector rolling_median(NumericVector x, int win);

TEST(amt_deepstate_test,rolling_median_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/rolling_median/AFL_rolling_median/afl_inputs/" + std::to_string(t) + "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  IntegerVector win(1);
  win[0]  = RcppDeepState_int();
  std::string win_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/rolling_median/AFL_rolling_median/afl_inputs/" + std::to_string(t) + "_win.qs";
  qs::c_qsave(win,win_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "win values: "<< win << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    rolling_median(x,win[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
