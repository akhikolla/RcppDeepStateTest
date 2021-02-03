#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericMatrix DCTdenoising(Rcpp::NumericMatrix ipixelsR, int width, int height, double sigma, int flag_dct16x16);

TEST(imagerExtra_deepstate_test,DCTdenoising_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix ipixelsR  = RcppDeepState_NumericMatrix();
  std::string ipixelsR_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/DCTdenoising/libFuzzer_DCTdenoising/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_ipixelsR.qs";
  qs::c_qsave(ipixelsR,ipixelsR_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ipixelsR values: "<< ipixelsR << std::endl;
  IntegerVector width(1);
  width[0]  = RcppDeepState_int();
  std::string width_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/DCTdenoising/libFuzzer_DCTdenoising/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_width.qs";
  qs::c_qsave(width,width_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "width values: "<< width << std::endl;
  IntegerVector height(1);
  height[0]  = RcppDeepState_int();
  std::string height_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/DCTdenoising/libFuzzer_DCTdenoising/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_height.qs";
  qs::c_qsave(height,height_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "height values: "<< height << std::endl;
  NumericVector sigma(1);
  sigma[0]  = RcppDeepState_double();
  std::string sigma_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/DCTdenoising/libFuzzer_DCTdenoising/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_sigma.qs";
  qs::c_qsave(sigma,sigma_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "sigma values: "<< sigma << std::endl;
  IntegerVector flag_dct16x16(1);
  flag_dct16x16[0]  = RcppDeepState_int();
  std::string flag_dct16x16_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/DCTdenoising/libFuzzer_DCTdenoising/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_flag_dct16x16.qs";
  qs::c_qsave(flag_dct16x16,flag_dct16x16_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "flag_dct16x16 values: "<< flag_dct16x16 << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    DCTdenoising(ipixelsR,width[0],height[0],sigma[0],flag_dct16x16[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
