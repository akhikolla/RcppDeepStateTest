#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector d_mat52_cpp(NumericVector X, double x, double sigma);

TEST(hetGP_deepstate_test,d_mat52_cpp_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector X  = RcppDeepState_NumericVector();
  std::string X_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/hetGP/inst/testfiles/d_mat52_cpp/AFL_d_mat52_cpp/afl_inputs/" + std::to_string(t) + "_X.qs";
  qs::c_qsave(X,X_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "X values: "<< X << std::endl;
  NumericVector x(1);
  x[0]  = RcppDeepState_double();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/hetGP/inst/testfiles/d_mat52_cpp/AFL_d_mat52_cpp/afl_inputs/" + std::to_string(t) + "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector sigma(1);
  sigma[0]  = RcppDeepState_double();
  std::string sigma_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/hetGP/inst/testfiles/d_mat52_cpp/AFL_d_mat52_cpp/afl_inputs/" + std::to_string(t) + "_sigma.qs";
  qs::c_qsave(sigma,sigma_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "sigma values: "<< sigma << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    d_mat52_cpp(X,x[0],sigma[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
