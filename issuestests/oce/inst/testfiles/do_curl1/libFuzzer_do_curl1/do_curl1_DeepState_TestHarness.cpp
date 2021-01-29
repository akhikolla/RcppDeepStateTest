#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List do_curl1(NumericMatrix u, NumericMatrix v, NumericVector x, NumericVector y, NumericVector geographical);

TEST(oce_deepstate_test,do_curl1_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix u  = RcppDeepState_NumericMatrix();
  std::string u_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_curl1/libFuzzer_do_curl1/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_u.qs";
  qs::c_qsave(u,u_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "u values: "<< u << std::endl;
  NumericMatrix v  = RcppDeepState_NumericMatrix();
  std::string v_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_curl1/libFuzzer_do_curl1/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_v.qs";
  qs::c_qsave(v,v_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "v values: "<< v << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_curl1/libFuzzer_do_curl1/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  std::string y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_curl1/libFuzzer_do_curl1/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_y.qs";
  qs::c_qsave(y,y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericVector geographical  = RcppDeepState_NumericVector();
  std::string geographical_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_curl1/libFuzzer_do_curl1/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_geographical.qs";
  qs::c_qsave(geographical,geographical_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "geographical values: "<< geographical << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    do_curl1(u,v,x,y,geographical);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
