#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List do_runlm(NumericVector x, NumericVector y, NumericVector xout, NumericVector window, NumericVector L);

TEST(oce_deepstate_test,do_runlm_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_runlm/AFL_do_runlm/afl_inputs/" + std::to_string(t) + "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  std::string y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_runlm/AFL_do_runlm/afl_inputs/" + std::to_string(t) + "_y.qs";
  qs::c_qsave(y,y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericVector xout  = RcppDeepState_NumericVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_runlm/AFL_do_runlm/afl_inputs/" + std::to_string(t) + "_x.qs";
  std::string xout_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_runlm/AFL_do_runlm/afl_inputs/" + std::to_string(t) + "_xout.qs";
  qs::c_qsave(xout,xout_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "xout values: "<< xout << std::endl;
  NumericVector window  = RcppDeepState_NumericVector();
  std::string window_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_runlm/AFL_do_runlm/afl_inputs/" + std::to_string(t) + "_window.qs";
  qs::c_qsave(window,window_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "window values: "<< window << std::endl;
  NumericVector L  = RcppDeepState_NumericVector();
  std::string L_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_runlm/AFL_do_runlm/afl_inputs/" + std::to_string(t) + "_L.qs";
  qs::c_qsave(L,L_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "L values: "<< L << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    do_runlm(x,y,xout,window,L);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
