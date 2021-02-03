#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector splitn_var(NumericVector sigma, NumericVector lmd);

TEST(dng_deepstate_test,splitn_var_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector sigma  = RcppDeepState_NumericVector();
  std::string sigma_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/dng/inst/testfiles/splitn_var/AFL_splitn_var/afl_inputs/" + std::to_string(t) + "_sigma.qs";
  qs::c_qsave(sigma,sigma_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "sigma values: "<< sigma << std::endl;
  NumericVector lmd  = RcppDeepState_NumericVector();
  std::string lmd_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/dng/inst/testfiles/splitn_var/AFL_splitn_var/afl_inputs/" + std::to_string(t) + "_lmd.qs";
  qs::c_qsave(lmd,lmd_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lmd values: "<< lmd << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    splitn_var(sigma,lmd);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
