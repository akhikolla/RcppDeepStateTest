#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericVector rcpp_rdirichlet(Rcpp::NumericVector B);

TEST(NHMM_deepstate_test,rcpp_rdirichlet_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector B  = RcppDeepState_NumericVector();
  qs::c_qsave(B,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_rdirichlet/inputs/B.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "B values: "<< B << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    rcpp_rdirichlet(B);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
