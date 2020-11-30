#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double rcpp_prod(Rcpp::NumericVector A);

TEST(NHMM_deepstate_test,rcpp_prod_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector A  = RcppDeepState_NumericVector();
  qs::c_qsave(A,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_prod/inputs/A.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "A values: "<< A << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    rcpp_prod(A);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
