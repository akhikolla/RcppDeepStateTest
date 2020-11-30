#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericVector computeTwoSidedPvalueRcpp(Rcpp::NumericVector x_, Rcpp::NumericVector a_, Rcpp::NumericVector b_);

TEST(ffstream_deepstate_test,computeTwoSidedPvalueRcpp_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector x_  = RcppDeepState_NumericVector();
  qs::c_qsave(x_,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ffstream/inst/testfiles/computeTwoSidedPvalueRcpp/inputs/x_.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x_ values: "<< x_ << std::endl;
  NumericVector a_  = RcppDeepState_NumericVector();
  qs::c_qsave(a_,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ffstream/inst/testfiles/computeTwoSidedPvalueRcpp/inputs/a_.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "a_ values: "<< a_ << std::endl;
  NumericVector b_  = RcppDeepState_NumericVector();
  qs::c_qsave(b_,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ffstream/inst/testfiles/computeTwoSidedPvalueRcpp/inputs/b_.qs",
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
