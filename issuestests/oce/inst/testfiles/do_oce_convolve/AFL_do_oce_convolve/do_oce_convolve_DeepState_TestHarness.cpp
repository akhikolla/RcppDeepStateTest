#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector do_oce_convolve(NumericVector x, NumericVector f, NumericVector end);

TEST(oce_deepstate_test,do_oce_convolve_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_oce_convolve/AFL_do_oce_convolve/afl_inputs/" + std::to_string(t) + "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector f  = RcppDeepState_NumericVector();
  std::string f_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_oce_convolve/AFL_do_oce_convolve/afl_inputs/" + std::to_string(t) + "_f.qs";
  qs::c_qsave(f,f_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "f values: "<< f << std::endl;
  NumericVector end  = RcppDeepState_NumericVector();
  std::string end_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_oce_convolve/AFL_do_oce_convolve/afl_inputs/" + std::to_string(t) + "_end.qs";
  qs::c_qsave(end,end_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "end values: "<< end << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    do_oce_convolve(x,f,end);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
