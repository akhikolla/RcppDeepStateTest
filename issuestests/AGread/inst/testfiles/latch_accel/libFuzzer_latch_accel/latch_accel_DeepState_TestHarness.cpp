#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector latch_accel(int vector_size, NumericVector accel_input, int samp_rate);

TEST(AGread_deepstate_test,latch_accel_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector vector_size(1);
  vector_size[0]  = RcppDeepState_int();
  std::string vector_size_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/AGread/inst/testfiles/latch_accel/libFuzzer_latch_accel/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_vector_size.qs";
  qs::c_qsave(vector_size,vector_size_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "vector_size values: "<< vector_size << std::endl;
  NumericVector accel_input  = RcppDeepState_NumericVector();
  std::string accel_input_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/AGread/inst/testfiles/latch_accel/libFuzzer_latch_accel/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_accel_input.qs";
  qs::c_qsave(accel_input,accel_input_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "accel_input values: "<< accel_input << std::endl;
  IntegerVector samp_rate(1);
  samp_rate[0]  = RcppDeepState_int();
  std::string samp_rate_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/AGread/inst/testfiles/latch_accel/libFuzzer_latch_accel/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_samp_rate.qs";
  qs::c_qsave(samp_rate,samp_rate_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "samp_rate values: "<< samp_rate << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    latch_accel(vector_size[0],accel_input,samp_rate[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
