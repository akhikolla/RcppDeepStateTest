#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double vsb(NumericVector probs, NumericVector ys, NumericMatrix xs);

TEST(BalancedSampling_deepstate_test,vsb_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector probs  = RcppDeepState_NumericVector();
  std::string probs_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BalancedSampling/inst/testfiles/vsb/AFL_vsb/afl_inputs/" + std::to_string(t) + "_probs.qs";
  qs::c_qsave(probs,probs_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "probs values: "<< probs << std::endl;
  NumericVector ys  = RcppDeepState_NumericVector();
  std::string ys_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BalancedSampling/inst/testfiles/vsb/AFL_vsb/afl_inputs/" + std::to_string(t) + "_ys.qs";
  qs::c_qsave(ys,ys_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ys values: "<< ys << std::endl;
  NumericMatrix xs  = RcppDeepState_NumericMatrix();
  std::string xs_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BalancedSampling/inst/testfiles/vsb/AFL_vsb/afl_inputs/" + std::to_string(t) + "_xs.qs";
  qs::c_qsave(xs,xs_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "xs values: "<< xs << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    vsb(probs,ys,xs);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
