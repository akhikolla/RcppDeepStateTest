#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

IntegerVector Match_C(NumericVector x_subset, NumericVector x_set);

TEST(BoostMLR_deepstate_test,Match_C_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector x_subset  = RcppDeepState_NumericVector();
  qs::c_qsave(x_subset,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BoostMLR/inst/testfiles/Match_C/inputs/x_subset.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x_subset values: "<< x_subset << std::endl;
  NumericVector x_set  = RcppDeepState_NumericVector();
  qs::c_qsave(x_set,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BoostMLR/inst/testfiles/Match_C/inputs/x_set.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x_set values: "<< x_set << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    Match_C(x_subset,x_set);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
