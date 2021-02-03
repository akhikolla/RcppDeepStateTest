#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector xlin_fits(NumericVector x, NumericVector y, NumericVector w, const int i, const int j);

TEST(RcppDynProg_deepstate_test,xlin_fits_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RcppDynProg/inst/testfiles/xlin_fits/AFL_xlin_fits/afl_inputs/" + std::to_string(t) + "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  std::string y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RcppDynProg/inst/testfiles/xlin_fits/AFL_xlin_fits/afl_inputs/" + std::to_string(t) + "_y.qs";
  qs::c_qsave(y,y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericVector w  = RcppDeepState_NumericVector();
  std::string w_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RcppDynProg/inst/testfiles/xlin_fits/AFL_xlin_fits/afl_inputs/" + std::to_string(t) + "_w.qs";
  qs::c_qsave(w,w_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "w values: "<< w << std::endl;
  IntegerVector i(1);
  i[0]  = RcppDeepState_int();
  std::string i_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RcppDynProg/inst/testfiles/xlin_fits/AFL_xlin_fits/afl_inputs/" + std::to_string(t) + "_i.qs";
  qs::c_qsave(i,i_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "i values: "<< i << std::endl;
  IntegerVector j(1);
  j[0]  = RcppDeepState_int();
  std::string j_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RcppDynProg/inst/testfiles/xlin_fits/AFL_xlin_fits/afl_inputs/" + std::to_string(t) + "_j.qs";
  qs::c_qsave(j,j_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "j values: "<< j << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    xlin_fits(x,y,w,i[0],j[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
