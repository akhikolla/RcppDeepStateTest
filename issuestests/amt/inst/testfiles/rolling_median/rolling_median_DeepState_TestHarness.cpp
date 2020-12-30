#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector rolling_median(NumericVector x, int win);

TEST(amt_deepstate_test,rolling_median_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  qs::c_qsave(x,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/rolling_median/inputs/x.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  IntegerVector win(1);
  win[0]  = RcppDeepState_int();
  qs::c_qsave(win,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/rolling_median/inputs/win.qs",
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
