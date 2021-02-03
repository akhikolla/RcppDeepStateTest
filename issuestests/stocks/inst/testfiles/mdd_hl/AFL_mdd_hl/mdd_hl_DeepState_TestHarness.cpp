#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double mdd_hl(NumericVector highs, NumericVector lows);

TEST(stocks_deepstate_test,mdd_hl_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector highs  = RcppDeepState_NumericVector();
  std::string highs_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/stocks/inst/testfiles/mdd_hl/AFL_mdd_hl/afl_inputs/" + std::to_string(t) + "_highs.qs";
  qs::c_qsave(highs,highs_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "highs values: "<< highs << std::endl;
  NumericVector lows  = RcppDeepState_NumericVector();
  std::string lows_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/stocks/inst/testfiles/mdd_hl/AFL_mdd_hl/afl_inputs/" + std::to_string(t) + "_lows.qs";
  qs::c_qsave(lows,lows_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lows values: "<< lows << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    mdd_hl(highs,lows);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
