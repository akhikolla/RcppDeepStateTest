#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix d_matern3_2_1args_theta_k(NumericMatrix X1, double theta);

TEST(hetGP_deepstate_test,d_matern3_2_1args_theta_k_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix X1  = RcppDeepState_NumericMatrix();
  qs::c_qsave(X1,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/hetGP/inst/testfiles/d_matern3_2_1args_theta_k/inputs/X1.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "X1 values: "<< X1 << std::endl;
  NumericVector theta(1);
  theta[0]  = RcppDeepState_double();
  qs::c_qsave(theta,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/hetGP/inst/testfiles/d_matern3_2_1args_theta_k/inputs/theta.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "theta values: "<< theta << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    d_matern3_2_1args_theta_k(X1,theta[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
