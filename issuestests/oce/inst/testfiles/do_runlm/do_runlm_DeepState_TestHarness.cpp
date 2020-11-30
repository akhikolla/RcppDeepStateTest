#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List do_runlm(NumericVector x, NumericVector y, NumericVector xout, NumericVector window, NumericVector L);

TEST(oce_deepstate_test,do_runlm_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  qs::c_qsave(x,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_runlm/inputs/x.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  qs::c_qsave(y,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_runlm/inputs/y.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericVector xout  = RcppDeepState_NumericVector();
  qs::c_qsave(xout,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_runlm/inputs/xout.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "xout values: "<< xout << std::endl;
  NumericVector window  = RcppDeepState_NumericVector();
  qs::c_qsave(window,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_runlm/inputs/window.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "window values: "<< window << std::endl;
  NumericVector L  = RcppDeepState_NumericVector();
  qs::c_qsave(L,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_runlm/inputs/L.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "L values: "<< L << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    do_runlm(x,y,xout,window,L);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
