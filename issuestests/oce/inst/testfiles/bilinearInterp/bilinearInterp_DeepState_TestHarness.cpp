#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector bilinearInterp(NumericVector x, NumericVector y, NumericVector gx, NumericVector gy, NumericMatrix g);

TEST(oce_deepstate_test,bilinearInterp_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  qs::c_qsave(x,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/bilinearInterp/inputs/x.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  qs::c_qsave(y,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/bilinearInterp/inputs/y.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericVector gx  = RcppDeepState_NumericVector();
  qs::c_qsave(gx,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/bilinearInterp/inputs/gx.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "gx values: "<< gx << std::endl;
  NumericVector gy  = RcppDeepState_NumericVector();
  qs::c_qsave(gy,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/bilinearInterp/inputs/gy.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "gy values: "<< gy << std::endl;
  NumericMatrix g  = RcppDeepState_NumericMatrix();
  qs::c_qsave(g,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/bilinearInterp/inputs/g.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "g values: "<< g << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    bilinearInterp(x,y,gx,gy,g);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
