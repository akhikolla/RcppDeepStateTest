#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericVector combineTwoOneSidedPvaluesRcpp(Rcpp::NumericVector p1_, Rcpp::NumericVector p2_);

TEST(ffstream_deepstate_test,combineTwoOneSidedPvaluesRcpp_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector p1_  = RcppDeepState_NumericVector();
  qs::c_qsave(p1_,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ffstream/inst/testfiles/combineTwoOneSidedPvaluesRcpp/inputs/p1_.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "p1_ values: "<< p1_ << std::endl;
  NumericVector p2_  = RcppDeepState_NumericVector();
  qs::c_qsave(p2_,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ffstream/inst/testfiles/combineTwoOneSidedPvaluesRcpp/inputs/p2_.qs",
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
