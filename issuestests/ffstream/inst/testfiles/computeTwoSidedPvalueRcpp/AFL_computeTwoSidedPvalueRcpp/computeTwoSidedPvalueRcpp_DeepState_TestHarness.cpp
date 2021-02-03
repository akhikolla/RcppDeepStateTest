#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericVector computeTwoSidedPvalueRcpp(Rcpp::NumericVector x_, Rcpp::NumericVector a_, Rcpp::NumericVector b_);

TEST(ffstream_deepstate_test,computeTwoSidedPvalueRcpp_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector x_  = RcppDeepState_NumericVector();
  std::string x__t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ffstream/inst/testfiles/computeTwoSidedPvalueRcpp/AFL_computeTwoSidedPvalueRcpp/afl_inputs/" + std::to_string(t) + "_x_.qs";
  qs::c_qsave(x_,x__t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x_ values: "<< x_ << std::endl;
  NumericVector a_  = RcppDeepState_NumericVector();
  std::string a__t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ffstream/inst/testfiles/computeTwoSidedPvalueRcpp/AFL_computeTwoSidedPvalueRcpp/afl_inputs/" + std::to_string(t) + "_a_.qs";
  qs::c_qsave(a_,a__t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "a_ values: "<< a_ << std::endl;
  NumericVector b_  = RcppDeepState_NumericVector();
  std::string b__t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ffstream/inst/testfiles/computeTwoSidedPvalueRcpp/AFL_computeTwoSidedPvalueRcpp/afl_inputs/" + std::to_string(t) + "_b_.qs";
  qs::c_qsave(b_,b__t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "b_ values: "<< b_ << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    computeTwoSidedPvalueRcpp(x_,a_,b_);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
