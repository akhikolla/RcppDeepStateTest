#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector rcmean(NumericMatrix x, int margin);

TEST(mixR_deepstate_test,rcmean_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix x  = RcppDeepState_NumericMatrix();
  qs::c_qsave(x,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mixR/inst/testfiles/rcmean/inputs/x.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  IntegerVector margin(1);
  margin[0]  = RcppDeepState_int();
  qs::c_qsave(margin,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mixR/inst/testfiles/rcmean/inputs/margin.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "margin values: "<< margin << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    rcmean(x,margin[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
