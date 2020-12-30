#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double scobit_loglike_cpp(NumericVector x1, NumericVector x2, NumericVector y, NumericVector params);

TEST(backbone_deepstate_test,scobit_loglike_cpp_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector x1  = RcppDeepState_NumericVector();
  qs::c_qsave(x1,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/backbone/inst/testfiles/scobit_loglike_cpp/inputs/x1.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x1 values: "<< x1 << std::endl;
  NumericVector x2  = RcppDeepState_NumericVector();
  qs::c_qsave(x2,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/backbone/inst/testfiles/scobit_loglike_cpp/inputs/x2.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x2 values: "<< x2 << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  qs::c_qsave(y,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/backbone/inst/testfiles/scobit_loglike_cpp/inputs/y.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericVector params  = RcppDeepState_NumericVector();
  qs::c_qsave(params,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/backbone/inst/testfiles/scobit_loglike_cpp/inputs/params.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "params values: "<< params << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    scobit_loglike_cpp(x1,x2,y,params);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
