#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector lpm(NumericVector prob, NumericMatrix x, int h);

TEST(BalancedSampling_deepstate_test,lpm_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector prob  = RcppDeepState_NumericVector();
  std::string prob_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BalancedSampling/inst/testfiles/lpm/AFL_lpm/afl_inputs/" + std::to_string(t) + "_prob.qs";
  qs::c_qsave(prob,prob_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "prob values: "<< prob << std::endl;
  NumericMatrix x  = RcppDeepState_NumericMatrix();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BalancedSampling/inst/testfiles/lpm/AFL_lpm/afl_inputs/" + std::to_string(t) + "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  IntegerVector h(1);
  h[0]  = RcppDeepState_int();
  std::string h_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BalancedSampling/inst/testfiles/lpm/AFL_lpm/afl_inputs/" + std::to_string(t) + "_h.qs";
  qs::c_qsave(h,h_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "h values: "<< h << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    lpm(prob,x,h[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
