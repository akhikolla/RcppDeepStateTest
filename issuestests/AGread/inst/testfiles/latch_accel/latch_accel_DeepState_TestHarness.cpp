#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector latch_accel(int vector_size, NumericVector accel_input, int samp_rate);

TEST(AGread_deepstate_test,latch_accel_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector vector_size(1);
  vector_size[0]  = RcppDeepState_int();
  qs::c_qsave(vector_size,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/AGread/inst/testfiles/latch_accel/inputs/vector_size.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "vector_size values: "<< vector_size << std::endl;
  NumericVector accel_input  = RcppDeepState_NumericVector();
  qs::c_qsave(accel_input,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/AGread/inst/testfiles/latch_accel/inputs/accel_input.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "accel_input values: "<< accel_input << std::endl;
  IntegerVector samp_rate(1);
  samp_rate[0]  = RcppDeepState_int();
  qs::c_qsave(samp_rate,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/AGread/inst/testfiles/latch_accel/inputs/samp_rate.qs",
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
