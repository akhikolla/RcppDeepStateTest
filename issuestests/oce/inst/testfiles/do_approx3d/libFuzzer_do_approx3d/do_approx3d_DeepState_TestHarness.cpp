#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector do_approx3d(NumericVector x, NumericVector y, NumericVector z, NumericVector f, NumericVector xout, NumericVector yout, NumericVector zout);

TEST(oce_deepstate_test,do_approx3d_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_approx3d/libFuzzer_do_approx3d/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  std::string y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_approx3d/libFuzzer_do_approx3d/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_y.qs";
  qs::c_qsave(y,y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericVector z  = RcppDeepState_NumericVector();
  std::string z_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_approx3d/libFuzzer_do_approx3d/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_z.qs";
  qs::c_qsave(z,z_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "z values: "<< z << std::endl;
  NumericVector f  = RcppDeepState_NumericVector();
  std::string f_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_approx3d/libFuzzer_do_approx3d/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_f.qs";
  qs::c_qsave(f,f_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "f values: "<< f << std::endl;
  NumericVector xout  = RcppDeepState_NumericVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_approx3d/libFuzzer_do_approx3d/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_x.qs";
  std::string xout_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_approx3d/libFuzzer_do_approx3d/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_xout.qs";
  qs::c_qsave(xout,xout_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "xout values: "<< xout << std::endl;
  NumericVector yout  = RcppDeepState_NumericVector();
  std::string y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_approx3d/libFuzzer_do_approx3d/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_y.qs";
  std::string yout_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_approx3d/libFuzzer_do_approx3d/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_yout.qs";
  qs::c_qsave(yout,yout_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "yout values: "<< yout << std::endl;
  NumericVector zout  = RcppDeepState_NumericVector();
  std::string z_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_approx3d/libFuzzer_do_approx3d/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_z.qs";
  std::string zout_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_approx3d/libFuzzer_do_approx3d/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_zout.qs";
  qs::c_qsave(zout,zout_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "zout values: "<< zout << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    do_approx3d(x,y,z,f,xout,yout,zout);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
