#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector spm(NumericVector prob);

TEST(BalancedSampling_deepstate_test,spm_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector prob  = RcppDeepState_NumericVector();
  std::string prob_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BalancedSampling/inst/testfiles/spm/AFL_spm/afl_inputs/" + std::to_string(t) + "_prob.qs";
  qs::c_qsave(prob,prob_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "prob values: "<< prob << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    spm(prob);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
