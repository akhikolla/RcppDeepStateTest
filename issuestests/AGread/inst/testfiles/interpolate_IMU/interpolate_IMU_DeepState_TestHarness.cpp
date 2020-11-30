#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector interpolate_IMU(NumericVector original_samples, int target_frequency);

TEST(AGread_deepstate_test,interpolate_IMU_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector original_samples  = RcppDeepState_NumericVector();
  qs::c_qsave(original_samples,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/AGread/inst/testfiles/interpolate_IMU/inputs/original_samples.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "original_samples values: "<< original_samples << std::endl;
  IntegerVector target_frequency(1);
  target_frequency[0]  = RcppDeepState_int();
  qs::c_qsave(target_frequency,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/AGread/inst/testfiles/interpolate_IMU/inputs/target_frequency.qs",
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
