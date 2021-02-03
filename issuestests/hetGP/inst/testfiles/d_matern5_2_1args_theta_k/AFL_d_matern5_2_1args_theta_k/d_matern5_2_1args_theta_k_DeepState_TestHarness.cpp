#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix d_matern5_2_1args_theta_k(NumericMatrix X1, double theta);

TEST(hetGP_deepstate_test,d_matern5_2_1args_theta_k_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix X1  = RcppDeepState_NumericMatrix();
  std::string X1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/hetGP/inst/testfiles/d_matern5_2_1args_theta_k/AFL_d_matern5_2_1args_theta_k/afl_inputs/" + std::to_string(t) + "_X1.qs";
  qs::c_qsave(X1,X1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "X1 values: "<< X1 << std::endl;
  NumericVector theta(1);
  theta[0]  = RcppDeepState_double();
  std::string theta_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/hetGP/inst/testfiles/d_matern5_2_1args_theta_k/AFL_d_matern5_2_1args_theta_k/afl_inputs/" + std::to_string(t) + "_theta.qs";
  qs::c_qsave(theta,theta_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "theta values: "<< theta << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    d_matern5_2_1args_theta_k(X1,theta[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
