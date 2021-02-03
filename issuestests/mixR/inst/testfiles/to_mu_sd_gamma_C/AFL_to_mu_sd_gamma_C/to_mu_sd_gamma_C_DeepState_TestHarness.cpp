#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List to_mu_sd_gamma_C(NumericVector alpha, NumericVector lambda);

TEST(mixR_deepstate_test,to_mu_sd_gamma_C_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector alpha  = RcppDeepState_NumericVector();
  std::string alpha_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mixR/inst/testfiles/to_mu_sd_gamma_C/AFL_to_mu_sd_gamma_C/afl_inputs/" + std::to_string(t) + "_alpha.qs";
  qs::c_qsave(alpha,alpha_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "alpha values: "<< alpha << std::endl;
  NumericVector lambda  = RcppDeepState_NumericVector();
  std::string lambda_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mixR/inst/testfiles/to_mu_sd_gamma_C/AFL_to_mu_sd_gamma_C/afl_inputs/" + std::to_string(t) + "_lambda.qs";
  qs::c_qsave(lambda,lambda_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lambda values: "<< lambda << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    to_mu_sd_gamma_C(alpha,lambda);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
