#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector xlin_pfits(NumericVector x, NumericVector y, NumericVector w, const int i, const int j);

TEST(RcppDynProg_deepstate_test,xlin_pfits_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  qs::c_qsave(x,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RcppDynProg/inst/testfiles/xlin_pfits/inputs/x.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  qs::c_qsave(y,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RcppDynProg/inst/testfiles/xlin_pfits/inputs/y.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericVector w  = RcppDeepState_NumericVector();
  qs::c_qsave(w,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RcppDynProg/inst/testfiles/xlin_pfits/inputs/w.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "w values: "<< w << std::endl;
  IntegerVector i(1);
  i[0]  = RcppDeepState_int();
  qs::c_qsave(i,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RcppDynProg/inst/testfiles/xlin_pfits/inputs/i.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "i values: "<< i << std::endl;
  IntegerVector j(1);
  j[0]  = RcppDeepState_int();
  qs::c_qsave(j,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RcppDynProg/inst/testfiles/xlin_pfits/inputs/j.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "j values: "<< j << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    xlin_pfits(x,y,w,i[0],j[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
