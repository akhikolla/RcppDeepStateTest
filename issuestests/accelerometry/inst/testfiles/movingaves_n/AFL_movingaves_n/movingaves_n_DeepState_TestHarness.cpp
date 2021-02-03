#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector movingaves_n(NumericVector x, double window);

TEST(accelerometry_deepstate_test,movingaves_n_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/accelerometry/inst/testfiles/movingaves_n/AFL_movingaves_n/afl_inputs/" + std::to_string(t) + "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector window(1);
  window[0]  = RcppDeepState_double();
  std::string window_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/accelerometry/inst/testfiles/movingaves_n/AFL_movingaves_n/afl_inputs/" + std::to_string(t) + "_window.qs";
  qs::c_qsave(window,window_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "window values: "<< window << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    movingaves_n(x,window[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
