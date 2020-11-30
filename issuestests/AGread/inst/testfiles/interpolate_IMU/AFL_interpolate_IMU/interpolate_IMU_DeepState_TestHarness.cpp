#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector interpolate_IMU(NumericVector original_samples, int target_frequency);

TEST(AGread_deepstate_test,interpolate_IMU_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector original_samples  = RcppDeepState_NumericVector();
  std::string original_samples_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/AGread/inst/testfiles/interpolate_IMU/AFL_interpolate_IMU/afl_inputs/" + std::to_string(t) + "_original_samples.qs";
  qs::c_qsave(original_samples,original_samples_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "original_samples values: "<< original_samples << std::endl;
  IntegerVector target_frequency(1);
  target_frequency[0]  = RcppDeepState_int();
  std::string target_frequency_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/AGread/inst/testfiles/interpolate_IMU/AFL_interpolate_IMU/afl_inputs/" + std::to_string(t) + "_target_frequency.qs";
  qs::c_qsave(target_frequency,target_frequency_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "target_frequency values: "<< target_frequency << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    interpolate_IMU(original_samples,target_frequency[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
