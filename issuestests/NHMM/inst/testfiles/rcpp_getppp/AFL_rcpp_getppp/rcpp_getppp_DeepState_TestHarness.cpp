#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericVector rcpp_getppp(Rcpp::NumericMatrix gamy, Rcpp::NumericMatrix mus);

TEST(NHMM_deepstate_test,rcpp_getppp_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix gamy  = RcppDeepState_NumericMatrix();
  std::string gamy_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getppp/AFL_rcpp_getppp/afl_inputs/" + std::to_string(t) + "_gamy.qs";
  qs::c_qsave(gamy,gamy_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "gamy values: "<< gamy << std::endl;
  NumericMatrix mus  = RcppDeepState_NumericMatrix();
  std::string mus_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getppp/AFL_rcpp_getppp/afl_inputs/" + std::to_string(t) + "_mus.qs";
  qs::c_qsave(mus,mus_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "mus values: "<< mus << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    rcpp_getppp(gamy,mus);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
