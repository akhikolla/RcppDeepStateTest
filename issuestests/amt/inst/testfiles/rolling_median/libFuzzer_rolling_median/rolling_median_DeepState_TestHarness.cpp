#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector rolling_median(NumericVector x, int win);

TEST(amt_deepstate_test,rolling_median_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/rolling_median/libFuzzer_rolling_median/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  IntegerVector win(1);
  win[0]  = RcppDeepState_int();
  std::string win_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/rolling_median/libFuzzer_rolling_median/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_win.qs";
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
