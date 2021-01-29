#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericVector rcpp_rdirichlet(Rcpp::NumericVector B);

TEST(NHMM_deepstate_test,rcpp_rdirichlet_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector B  = RcppDeepState_NumericVector();
  std::string B_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_rdirichlet/libFuzzer_rcpp_rdirichlet/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_B.qs";
  qs::c_qsave(B,B_t,
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
