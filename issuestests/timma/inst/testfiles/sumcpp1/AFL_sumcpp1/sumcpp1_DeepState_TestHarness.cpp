#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

arma::rowvec sumcpp1(NumericVector tau, int x, int y);

TEST(timma_deepstate_test,sumcpp1_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector tau  = RcppDeepState_NumericVector();
  std::string tau_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/timma/inst/testfiles/sumcpp1/AFL_sumcpp1/afl_inputs/" + std::to_string(t) + "_tau.qs";
  qs::c_qsave(tau,tau_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tau values: "<< tau << std::endl;
  IntegerVector x(1);
  x[0]  = RcppDeepState_int();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/timma/inst/testfiles/sumcpp1/AFL_sumcpp1/afl_inputs/" + std::to_string(t) + "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  IntegerVector y(1);
  y[0]  = RcppDeepState_int();
  std::string y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/timma/inst/testfiles/sumcpp1/AFL_sumcpp1/afl_inputs/" + std::to_string(t) + "_y.qs";
  qs::c_qsave(y,y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    sumcpp1(tau,x[0],y[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
