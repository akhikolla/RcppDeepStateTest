#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector compute_tau_(NumericVector x1, NumericVector x2, NumericVector x3, NumericVector xuni, NumericVector x4, NumericVector x5);

TEST(metacart_deepstate_test,compute_tau__test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector x1  = RcppDeepState_NumericVector();
  std::string x1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/metacart/inst/testfiles/compute_tau_/libFuzzer_compute_tau_/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_x1.qs";
  qs::c_qsave(x1,x1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x1 values: "<< x1 << std::endl;
  NumericVector x2  = RcppDeepState_NumericVector();
  std::string x2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/metacart/inst/testfiles/compute_tau_/libFuzzer_compute_tau_/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_x2.qs";
  qs::c_qsave(x2,x2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x2 values: "<< x2 << std::endl;
  NumericVector x3  = RcppDeepState_NumericVector();
  std::string x3_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/metacart/inst/testfiles/compute_tau_/libFuzzer_compute_tau_/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_x3.qs";
  qs::c_qsave(x3,x3_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x3 values: "<< x3 << std::endl;
  NumericVector xuni  = RcppDeepState_NumericVector();
  std::string xuni_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/metacart/inst/testfiles/compute_tau_/libFuzzer_compute_tau_/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_xuni.qs";
  qs::c_qsave(xuni,xuni_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "xuni values: "<< xuni << std::endl;
  NumericVector x4  = RcppDeepState_NumericVector();
  std::string x4_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/metacart/inst/testfiles/compute_tau_/libFuzzer_compute_tau_/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_x4.qs";
  qs::c_qsave(x4,x4_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x4 values: "<< x4 << std::endl;
  NumericVector x5  = RcppDeepState_NumericVector();
  std::string x5_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/metacart/inst/testfiles/compute_tau_/libFuzzer_compute_tau_/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_x5.qs";
  qs::c_qsave(x5,x5_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x5 values: "<< x5 << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    compute_tau_(x1,x2,x3,xuni,x4,x5);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
