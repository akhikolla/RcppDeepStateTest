#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector zero2one(NumericVector samples);

TEST(AGread_deepstate_test,zero2one_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector samples  = RcppDeepState_NumericVector();
  qs::c_qsave(samples,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/AGread/inst/testfiles/zero2one/inputs/samples.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "samples values: "<< samples << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    zero2one(samples);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
