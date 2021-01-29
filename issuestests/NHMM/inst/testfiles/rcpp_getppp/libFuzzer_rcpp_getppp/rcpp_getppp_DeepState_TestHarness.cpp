#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericVector rcpp_getppp(Rcpp::NumericMatrix gamy, Rcpp::NumericMatrix mus);

TEST(NHMM_deepstate_test,rcpp_getppp_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix gamy  = RcppDeepState_NumericMatrix();
  std::string gamy_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getppp/libFuzzer_rcpp_getppp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_gamy.qs";
  qs::c_qsave(gamy,gamy_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "gamy values: "<< gamy << std::endl;
  NumericMatrix mus  = RcppDeepState_NumericMatrix();
  std::string mus_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getppp/libFuzzer_rcpp_getppp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_mus.qs";
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
