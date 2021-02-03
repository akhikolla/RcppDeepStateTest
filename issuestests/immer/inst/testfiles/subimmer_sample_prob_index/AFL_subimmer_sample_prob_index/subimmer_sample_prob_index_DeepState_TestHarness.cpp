#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericVector subimmer_sample_prob_index(Rcpp::NumericMatrix probs, Rcpp::NumericVector rn);

TEST(immer_deepstate_test,subimmer_sample_prob_index_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix probs  = RcppDeepState_NumericMatrix();
  std::string probs_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/subimmer_sample_prob_index/AFL_subimmer_sample_prob_index/afl_inputs/" + std::to_string(t) + "_probs.qs";
  qs::c_qsave(probs,probs_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "probs values: "<< probs << std::endl;
  NumericVector rn  = RcppDeepState_NumericVector();
  std::string rn_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/subimmer_sample_prob_index/AFL_subimmer_sample_prob_index/afl_inputs/" + std::to_string(t) + "_rn.qs";
  qs::c_qsave(rn,rn_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "rn values: "<< rn << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    subimmer_sample_prob_index(probs,rn);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
