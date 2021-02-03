#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double scobit_loglike_cpp(NumericVector x1, NumericVector x2, NumericVector y, NumericVector params);

TEST(backbone_deepstate_test,scobit_loglike_cpp_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector x1  = RcppDeepState_NumericVector();
  std::string x1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/backbone/inst/testfiles/scobit_loglike_cpp/AFL_scobit_loglike_cpp/afl_inputs/" + std::to_string(t) + "_x1.qs";
  qs::c_qsave(x1,x1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x1 values: "<< x1 << std::endl;
  NumericVector x2  = RcppDeepState_NumericVector();
  std::string x2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/backbone/inst/testfiles/scobit_loglike_cpp/AFL_scobit_loglike_cpp/afl_inputs/" + std::to_string(t) + "_x2.qs";
  qs::c_qsave(x2,x2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x2 values: "<< x2 << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  std::string y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/backbone/inst/testfiles/scobit_loglike_cpp/AFL_scobit_loglike_cpp/afl_inputs/" + std::to_string(t) + "_y.qs";
  qs::c_qsave(y,y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericVector params  = RcppDeepState_NumericVector();
  std::string params_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/backbone/inst/testfiles/scobit_loglike_cpp/AFL_scobit_loglike_cpp/afl_inputs/" + std::to_string(t) + "_params.qs";
  qs::c_qsave(params,params_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "params values: "<< params << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    scobit_loglike_cpp(x1,x2,y,params);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
