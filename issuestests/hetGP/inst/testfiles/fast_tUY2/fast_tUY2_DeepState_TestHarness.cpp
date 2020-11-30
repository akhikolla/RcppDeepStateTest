#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector fast_tUY2(IntegerVector mult, NumericVector Y2);

TEST(hetGP_deepstate_test,fast_tUY2_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector mult  = RcppDeepState_IntegerVector();
  qs::c_qsave(mult,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/hetGP/inst/testfiles/fast_tUY2/inputs/mult.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "mult values: "<< mult << std::endl;
  NumericVector Y2  = RcppDeepState_NumericVector();
  qs::c_qsave(Y2,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/hetGP/inst/testfiles/fast_tUY2/inputs/Y2.qs",
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
