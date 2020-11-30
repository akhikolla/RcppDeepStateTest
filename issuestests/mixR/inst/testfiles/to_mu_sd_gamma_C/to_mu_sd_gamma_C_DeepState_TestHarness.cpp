#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List to_mu_sd_gamma_C(NumericVector alpha, NumericVector lambda);

TEST(mixR_deepstate_test,to_mu_sd_gamma_C_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector alpha  = RcppDeepState_NumericVector();
  qs::c_qsave(alpha,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mixR/inst/testfiles/to_mu_sd_gamma_C/inputs/alpha.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "alpha values: "<< alpha << std::endl;
  NumericVector lambda  = RcppDeepState_NumericVector();
  qs::c_qsave(lambda,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mixR/inst/testfiles/to_mu_sd_gamma_C/inputs/lambda.qs",
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
