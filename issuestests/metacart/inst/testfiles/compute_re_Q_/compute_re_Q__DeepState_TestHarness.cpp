#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector compute_re_Q_(NumericVector x1, NumericVector x2, NumericVector x3, NumericVector x4, NumericVector xuni, NumericVector x5, NumericVector x6);

TEST(metacart_deepstate_test,compute_re_Q__test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector x1  = RcppDeepState_NumericVector();
  qs::c_qsave(x1,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/metacart/inst/testfiles/compute_re_Q_/inputs/x1.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x1 values: "<< x1 << std::endl;
  NumericVector x2  = RcppDeepState_NumericVector();
  qs::c_qsave(x2,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/metacart/inst/testfiles/compute_re_Q_/inputs/x2.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x2 values: "<< x2 << std::endl;
  NumericVector x3  = RcppDeepState_NumericVector();
  qs::c_qsave(x3,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/metacart/inst/testfiles/compute_re_Q_/inputs/x3.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x3 values: "<< x3 << std::endl;
  NumericVector x4  = RcppDeepState_NumericVector();
  qs::c_qsave(x4,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/metacart/inst/testfiles/compute_re_Q_/inputs/x4.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x4 values: "<< x4 << std::endl;
  NumericVector xuni  = RcppDeepState_NumericVector();
  qs::c_qsave(xuni,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/metacart/inst/testfiles/compute_re_Q_/inputs/xuni.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "xuni values: "<< xuni << std::endl;
  NumericVector x5  = RcppDeepState_NumericVector();
  qs::c_qsave(x5,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/metacart/inst/testfiles/compute_re_Q_/inputs/x5.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x5 values: "<< x5 << std::endl;
  NumericVector x6  = RcppDeepState_NumericVector();
  qs::c_qsave(x6,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/metacart/inst/testfiles/compute_re_Q_/inputs/x6.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x6 values: "<< x6 << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    compute_re_Q_(x1,x2,x3,x4,xuni,x5,x6);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
