#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List to_alpha_lambda_gamma_C(NumericVector mu, NumericVector sd);

TEST(mixR_deepstate_test,to_alpha_lambda_gamma_C_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector mu  = RcppDeepState_NumericVector();
  qs::c_qsave(mu,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mixR/inst/testfiles/to_alpha_lambda_gamma_C/inputs/mu.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "mu values: "<< mu << std::endl;
  NumericVector sd  = RcppDeepState_NumericVector();
  qs::c_qsave(sd,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mixR/inst/testfiles/to_alpha_lambda_gamma_C/inputs/sd.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "sd values: "<< sd << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    to_alpha_lambda_gamma_C(mu,sd);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
