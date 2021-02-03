#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericVector computeStdNormCdf(Rcpp::NumericVector x_);

TEST(ffstream_deepstate_test,computeStdNormCdf_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector x_  = RcppDeepState_NumericVector();
  std::string x__t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ffstream/inst/testfiles/computeStdNormCdf/AFL_computeStdNormCdf/afl_inputs/" + std::to_string(t) + "_x_.qs";
  qs::c_qsave(x_,x__t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x_ values: "<< x_ << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    computeStdNormCdf(x_);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
