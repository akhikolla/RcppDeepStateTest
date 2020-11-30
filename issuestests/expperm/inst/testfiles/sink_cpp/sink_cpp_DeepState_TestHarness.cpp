#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix sink_cpp(NumericMatrix A, int maxit);

TEST(expperm_deepstate_test,sink_cpp_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix A  = RcppDeepState_NumericMatrix();
  qs::c_qsave(A,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/expperm/inst/testfiles/sink_cpp/inputs/A.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "A values: "<< A << std::endl;
  IntegerVector maxit(1);
  maxit[0]  = RcppDeepState_int();
  qs::c_qsave(maxit,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/expperm/inst/testfiles/sink_cpp/inputs/maxit.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "maxit values: "<< maxit << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    sink_cpp(A,maxit[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
