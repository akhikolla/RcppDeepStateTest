#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List maxcpp1(NumericVector tau, int x, int y);

TEST(timma_deepstate_test,maxcpp1_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector tau  = RcppDeepState_NumericVector();
  qs::c_qsave(tau,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/timma/inst/testfiles/maxcpp1/inputs/tau.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tau values: "<< tau << std::endl;
  IntegerVector x(1);
  x[0]  = RcppDeepState_int();
  qs::c_qsave(x,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/timma/inst/testfiles/maxcpp1/inputs/x.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  IntegerVector y(1);
  y[0]  = RcppDeepState_int();
  qs::c_qsave(y,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/timma/inst/testfiles/maxcpp1/inputs/y.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    maxcpp1(tau,x[0],y[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
