#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector bilinearInterp(NumericVector x, NumericVector y, NumericVector gx, NumericVector gy, NumericMatrix g);

TEST(oce_deepstate_test,bilinearInterp_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/bilinearInterp/AFL_bilinearInterp/afl_inputs/" + std::to_string(t) + "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  std::string y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/bilinearInterp/AFL_bilinearInterp/afl_inputs/" + std::to_string(t) + "_y.qs";
  qs::c_qsave(y,y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericVector gx  = RcppDeepState_NumericVector();
  std::string gx_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/bilinearInterp/AFL_bilinearInterp/afl_inputs/" + std::to_string(t) + "_gx.qs";
  std::string g_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/bilinearInterp/AFL_bilinearInterp/afl_inputs/" + std::to_string(t) + "_g.qs";
  qs::c_qsave(gx,gx_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "gx values: "<< gx << std::endl;
  NumericVector gy  = RcppDeepState_NumericVector();
  std::string gy_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/bilinearInterp/AFL_bilinearInterp/afl_inputs/" + std::to_string(t) + "_gy.qs";
  std::string g_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/bilinearInterp/AFL_bilinearInterp/afl_inputs/" + std::to_string(t) + "_g.qs";
  qs::c_qsave(gy,gy_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "gy values: "<< gy << std::endl;
  NumericMatrix g  = RcppDeepState_NumericMatrix();
  std::string g_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/bilinearInterp/AFL_bilinearInterp/afl_inputs/" + std::to_string(t) + "_g.qs";
  qs::c_qsave(g,g_t,
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
