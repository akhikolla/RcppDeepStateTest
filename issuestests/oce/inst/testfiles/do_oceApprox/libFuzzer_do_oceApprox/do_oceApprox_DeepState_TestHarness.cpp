#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector do_oceApprox(NumericVector x, NumericVector y, NumericVector xout, NumericVector method);

TEST(oce_deepstate_test,do_oceApprox_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_oceApprox/libFuzzer_do_oceApprox/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  std::string y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_oceApprox/libFuzzer_do_oceApprox/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_y.qs";
  qs::c_qsave(y,y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericVector xout  = RcppDeepState_NumericVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_oceApprox/libFuzzer_do_oceApprox/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_x.qs";
  std::string xout_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_oceApprox/libFuzzer_do_oceApprox/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_xout.qs";
  qs::c_qsave(xout,xout_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "xout values: "<< xout << std::endl;
  NumericVector method  = RcppDeepState_NumericVector();
  std::string method_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_oceApprox/libFuzzer_do_oceApprox/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_method.qs";
  qs::c_qsave(method,method_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "method values: "<< method << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    do_oceApprox(x,y,xout,method);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
