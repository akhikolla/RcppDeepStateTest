#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::List cpp_detectEWMAMeanMultiple(Rcpp::NumericVector x, double r, double L, int BL);

TEST(ffstream_deepstate_test,cpp_detectEWMAMeanMultiple_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ffstream/inst/testfiles/cpp_detectEWMAMeanMultiple/AFL_cpp_detectEWMAMeanMultiple/afl_inputs/" + std::to_string(t) + "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector r(1);
  r[0]  = RcppDeepState_double();
  std::string r_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ffstream/inst/testfiles/cpp_detectEWMAMeanMultiple/AFL_cpp_detectEWMAMeanMultiple/afl_inputs/" + std::to_string(t) + "_r.qs";
  qs::c_qsave(r,r_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "r values: "<< r << std::endl;
  NumericVector L(1);
  L[0]  = RcppDeepState_double();
  std::string L_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ffstream/inst/testfiles/cpp_detectEWMAMeanMultiple/AFL_cpp_detectEWMAMeanMultiple/afl_inputs/" + std::to_string(t) + "_L.qs";
  qs::c_qsave(L,L_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "L values: "<< L << std::endl;
  IntegerVector BL(1);
  BL[0]  = RcppDeepState_int();
  std::string BL_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ffstream/inst/testfiles/cpp_detectEWMAMeanMultiple/AFL_cpp_detectEWMAMeanMultiple/afl_inputs/" + std::to_string(t) + "_BL.qs";
  qs::c_qsave(BL,BL_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "BL values: "<< BL << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    cpp_detectEWMAMeanMultiple(x,r[0],L[0],BL[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
