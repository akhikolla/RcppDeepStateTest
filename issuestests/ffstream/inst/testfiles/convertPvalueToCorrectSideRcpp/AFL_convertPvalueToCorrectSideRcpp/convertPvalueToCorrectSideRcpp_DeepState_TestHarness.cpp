#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericVector convertPvalueToCorrectSideRcpp(Rcpp::NumericVector p_);

TEST(ffstream_deepstate_test,convertPvalueToCorrectSideRcpp_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector p_  = RcppDeepState_NumericVector();
  std::string p__t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ffstream/inst/testfiles/convertPvalueToCorrectSideRcpp/AFL_convertPvalueToCorrectSideRcpp/afl_inputs/" + std::to_string(t) + "_p_.qs";
  qs::c_qsave(p_,p__t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "p_ values: "<< p_ << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    convertPvalueToCorrectSideRcpp(p_);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
