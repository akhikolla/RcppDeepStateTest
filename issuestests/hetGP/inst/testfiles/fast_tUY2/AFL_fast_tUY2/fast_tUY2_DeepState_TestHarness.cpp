#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector fast_tUY2(IntegerVector mult, NumericVector Y2);

TEST(hetGP_deepstate_test,fast_tUY2_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector mult  = RcppDeepState_IntegerVector();
  std::string mult_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/hetGP/inst/testfiles/fast_tUY2/AFL_fast_tUY2/afl_inputs/" + std::to_string(t) + "_mult.qs";
  qs::c_qsave(mult,mult_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "mult values: "<< mult << std::endl;
  NumericVector Y2  = RcppDeepState_NumericVector();
  std::string Y2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/hetGP/inst/testfiles/fast_tUY2/AFL_fast_tUY2/afl_inputs/" + std::to_string(t) + "_Y2.qs";
  qs::c_qsave(Y2,Y2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Y2 values: "<< Y2 << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    fast_tUY2(mult,Y2);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
