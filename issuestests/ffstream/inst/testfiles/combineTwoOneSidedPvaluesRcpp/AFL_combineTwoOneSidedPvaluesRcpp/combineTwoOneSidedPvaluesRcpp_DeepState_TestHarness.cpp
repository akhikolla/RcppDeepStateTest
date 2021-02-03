#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericVector combineTwoOneSidedPvaluesRcpp(Rcpp::NumericVector p1_, Rcpp::NumericVector p2_);

TEST(ffstream_deepstate_test,combineTwoOneSidedPvaluesRcpp_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector p1_  = RcppDeepState_NumericVector();
  std::string p1__t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ffstream/inst/testfiles/combineTwoOneSidedPvaluesRcpp/AFL_combineTwoOneSidedPvaluesRcpp/afl_inputs/" + std::to_string(t) + "_p1_.qs";
  qs::c_qsave(p1_,p1__t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "p1_ values: "<< p1_ << std::endl;
  NumericVector p2_  = RcppDeepState_NumericVector();
  std::string p2__t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ffstream/inst/testfiles/combineTwoOneSidedPvaluesRcpp/AFL_combineTwoOneSidedPvaluesRcpp/afl_inputs/" + std::to_string(t) + "_p2_.qs";
  qs::c_qsave(p2_,p2__t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "p2_ values: "<< p2_ << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    combineTwoOneSidedPvaluesRcpp(p1_,p2_);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
