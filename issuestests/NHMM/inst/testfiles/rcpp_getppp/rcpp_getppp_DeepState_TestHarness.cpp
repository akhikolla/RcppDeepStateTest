#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericVector rcpp_getppp(Rcpp::NumericMatrix gamy, Rcpp::NumericMatrix mus);

TEST(NHMM_deepstate_test,rcpp_getppp_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix gamy  = RcppDeepState_NumericMatrix();
  qs::c_qsave(gamy,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getppp/inputs/gamy.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "gamy values: "<< gamy << std::endl;
  NumericMatrix mus  = RcppDeepState_NumericMatrix();
  qs::c_qsave(mus,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getppp/inputs/mus.qs",
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
