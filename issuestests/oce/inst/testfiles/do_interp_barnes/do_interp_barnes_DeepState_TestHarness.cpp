#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List do_interp_barnes(NumericVector x, NumericVector y, NumericVector z, NumericVector w, NumericVector xg, NumericVector yg, NumericVector xr, NumericVector yr, NumericVector gamma, NumericVector iterations);

TEST(oce_deepstate_test,do_interp_barnes_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  qs::c_qsave(x,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_interp_barnes/inputs/x.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  qs::c_qsave(y,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_interp_barnes/inputs/y.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericVector z  = RcppDeepState_NumericVector();
  qs::c_qsave(z,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_interp_barnes/inputs/z.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "z values: "<< z << std::endl;
  NumericVector w  = RcppDeepState_NumericVector();
  qs::c_qsave(w,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_interp_barnes/inputs/w.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "w values: "<< w << std::endl;
  NumericVector xg  = RcppDeepState_NumericVector();
  qs::c_qsave(xg,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_interp_barnes/inputs/xg.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "xg values: "<< xg << std::endl;
  NumericVector yg  = RcppDeepState_NumericVector();
  qs::c_qsave(yg,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_interp_barnes/inputs/yg.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "yg values: "<< yg << std::endl;
  NumericVector xr  = RcppDeepState_NumericVector();
  qs::c_qsave(xr,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_interp_barnes/inputs/xr.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "xr values: "<< xr << std::endl;
  NumericVector yr  = RcppDeepState_NumericVector();
  qs::c_qsave(yr,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_interp_barnes/inputs/yr.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "yr values: "<< yr << std::endl;
  NumericVector gamma  = RcppDeepState_NumericVector();
  qs::c_qsave(gamma,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_interp_barnes/inputs/gamma.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "gamma values: "<< gamma << std::endl;
  NumericVector iterations  = RcppDeepState_NumericVector();
  qs::c_qsave(iterations,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_interp_barnes/inputs/iterations.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "iterations values: "<< iterations << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    do_interp_barnes(x,y,z,w,xg,yg,xr,yr,gamma,iterations);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
