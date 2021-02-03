#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericVector rcpp_getNQQ(Rcpp::NumericMatrix beta, Rcpp::NumericMatrix XX);

TEST(NHMM_deepstate_test,rcpp_getNQQ_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix beta  = RcppDeepState_NumericMatrix();
  std::string beta_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getNQQ/AFL_rcpp_getNQQ/afl_inputs/" + std::to_string(t) + "_beta.qs";
  qs::c_qsave(beta,beta_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "beta values: "<< beta << std::endl;
  NumericMatrix XX  = RcppDeepState_NumericMatrix();
  std::string XX_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getNQQ/AFL_rcpp_getNQQ/afl_inputs/" + std::to_string(t) + "_XX.qs";
  qs::c_qsave(XX,XX_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "XX values: "<< XX << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    rcpp_getNQQ(beta,XX);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
