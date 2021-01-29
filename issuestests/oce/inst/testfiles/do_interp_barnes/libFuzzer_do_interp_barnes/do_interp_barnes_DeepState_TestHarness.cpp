#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List do_interp_barnes(NumericVector x, NumericVector y, NumericVector z, NumericVector w, NumericVector xg, NumericVector yg, NumericVector xr, NumericVector yr, NumericVector gamma, NumericVector iterations);

TEST(oce_deepstate_test,do_interp_barnes_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_interp_barnes/libFuzzer_do_interp_barnes/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  std::string y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_interp_barnes/libFuzzer_do_interp_barnes/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_y.qs";
  qs::c_qsave(y,y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericVector z  = RcppDeepState_NumericVector();
  std::string z_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_interp_barnes/libFuzzer_do_interp_barnes/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_z.qs";
  qs::c_qsave(z,z_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "z values: "<< z << std::endl;
  NumericVector w  = RcppDeepState_NumericVector();
  std::string w_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_interp_barnes/libFuzzer_do_interp_barnes/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_w.qs";
  qs::c_qsave(w,w_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "w values: "<< w << std::endl;
  NumericVector xg  = RcppDeepState_NumericVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_interp_barnes/libFuzzer_do_interp_barnes/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_x.qs";
  std::string xg_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_interp_barnes/libFuzzer_do_interp_barnes/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_xg.qs";
  qs::c_qsave(xg,xg_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "xg values: "<< xg << std::endl;
  NumericVector yg  = RcppDeepState_NumericVector();
  std::string y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_interp_barnes/libFuzzer_do_interp_barnes/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_y.qs";
  std::string yg_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_interp_barnes/libFuzzer_do_interp_barnes/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_yg.qs";
  qs::c_qsave(yg,yg_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "yg values: "<< yg << std::endl;
  NumericVector xr  = RcppDeepState_NumericVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_interp_barnes/libFuzzer_do_interp_barnes/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_x.qs";
  std::string xr_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_interp_barnes/libFuzzer_do_interp_barnes/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_xr.qs";
  qs::c_qsave(xr,xr_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "xr values: "<< xr << std::endl;
  NumericVector yr  = RcppDeepState_NumericVector();
  std::string y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_interp_barnes/libFuzzer_do_interp_barnes/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_y.qs";
  std::string yr_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_interp_barnes/libFuzzer_do_interp_barnes/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_yr.qs";
  qs::c_qsave(yr,yr_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "yr values: "<< yr << std::endl;
  NumericVector gamma  = RcppDeepState_NumericVector();
  std::string gamma_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_interp_barnes/libFuzzer_do_interp_barnes/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_gamma.qs";
  qs::c_qsave(gamma,gamma_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "gamma values: "<< gamma << std::endl;
  NumericVector iterations  = RcppDeepState_NumericVector();
  std::string iterations_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_interp_barnes/libFuzzer_do_interp_barnes/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_iterations.qs";
  qs::c_qsave(iterations,iterations_t,
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
