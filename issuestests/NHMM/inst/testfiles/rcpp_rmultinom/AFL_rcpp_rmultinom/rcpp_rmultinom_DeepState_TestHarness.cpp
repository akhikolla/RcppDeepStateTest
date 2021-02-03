#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

int rcpp_rmultinom(Rcpp::NumericVector probs);

TEST(NHMM_deepstate_test,rcpp_rmultinom_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector probs  = RcppDeepState_NumericVector();
  std::string probs_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_rmultinom/AFL_rcpp_rmultinom/afl_inputs/" + std::to_string(t) + "_probs.qs";
  qs::c_qsave(probs,probs_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "probs values: "<< probs << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    rcpp_rmultinom(probs);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
