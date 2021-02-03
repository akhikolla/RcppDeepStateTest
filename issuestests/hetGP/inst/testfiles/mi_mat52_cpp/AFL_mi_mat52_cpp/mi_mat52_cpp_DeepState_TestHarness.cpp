#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector mi_mat52_cpp(NumericMatrix Mu, NumericVector sigma);

TEST(hetGP_deepstate_test,mi_mat52_cpp_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix Mu  = RcppDeepState_NumericMatrix();
  std::string Mu_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/hetGP/inst/testfiles/mi_mat52_cpp/AFL_mi_mat52_cpp/afl_inputs/" + std::to_string(t) + "_Mu.qs";
  qs::c_qsave(Mu,Mu_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Mu values: "<< Mu << std::endl;
  NumericVector sigma  = RcppDeepState_NumericVector();
  std::string sigma_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/hetGP/inst/testfiles/mi_mat52_cpp/AFL_mi_mat52_cpp/afl_inputs/" + std::to_string(t) + "_sigma.qs";
  qs::c_qsave(sigma,sigma_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "sigma values: "<< sigma << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    mi_mat52_cpp(Mu,sigma);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
