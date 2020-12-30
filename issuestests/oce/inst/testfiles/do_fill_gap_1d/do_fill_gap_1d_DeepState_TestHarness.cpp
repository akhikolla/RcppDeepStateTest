#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector do_fill_gap_1d(NumericVector x, NumericVector rule);

TEST(oce_deepstate_test,do_fill_gap_1d_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  qs::c_qsave(x,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_fill_gap_1d/inputs/x.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector rule  = RcppDeepState_NumericVector();
  qs::c_qsave(rule,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_fill_gap_1d/inputs/rule.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "rule values: "<< rule << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    do_fill_gap_1d(x,rule);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
