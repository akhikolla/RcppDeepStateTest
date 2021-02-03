#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector hills3d1p12(NumericVector cv1, NumericVector cv2, NumericVector cv3, double width1, double width2, double width3, NumericVector heights, int n, int tmin, int tmax);

TEST(metadynminer3d_deepstate_test,hills3d1p12_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector cv1  = RcppDeepState_NumericVector();
  std::string cv1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/metadynminer3d/inst/testfiles/hills3d1p12/libFuzzer_hills3d1p12/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_cv1.qs";
  qs::c_qsave(cv1,cv1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "cv1 values: "<< cv1 << std::endl;
  NumericVector cv2  = RcppDeepState_NumericVector();
  std::string cv2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/metadynminer3d/inst/testfiles/hills3d1p12/libFuzzer_hills3d1p12/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_cv2.qs";
  qs::c_qsave(cv2,cv2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "cv2 values: "<< cv2 << std::endl;
  NumericVector cv3  = RcppDeepState_NumericVector();
  std::string cv3_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/metadynminer3d/inst/testfiles/hills3d1p12/libFuzzer_hills3d1p12/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_cv3.qs";
  qs::c_qsave(cv3,cv3_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "cv3 values: "<< cv3 << std::endl;
  NumericVector width1(1);
  width1[0]  = RcppDeepState_double();
  std::string width1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/metadynminer3d/inst/testfiles/hills3d1p12/libFuzzer_hills3d1p12/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_width1.qs";
  qs::c_qsave(width1,width1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "width1 values: "<< width1 << std::endl;
  NumericVector width2(1);
  width2[0]  = RcppDeepState_double();
  std::string width2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/metadynminer3d/inst/testfiles/hills3d1p12/libFuzzer_hills3d1p12/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_width2.qs";
  qs::c_qsave(width2,width2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "width2 values: "<< width2 << std::endl;
  NumericVector width3(1);
  width3[0]  = RcppDeepState_double();
  std::string width3_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/metadynminer3d/inst/testfiles/hills3d1p12/libFuzzer_hills3d1p12/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_width3.qs";
  qs::c_qsave(width3,width3_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "width3 values: "<< width3 << std::endl;
  NumericVector heights  = RcppDeepState_NumericVector();
  std::string heights_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/metadynminer3d/inst/testfiles/hills3d1p12/libFuzzer_hills3d1p12/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_heights.qs";
  qs::c_qsave(heights,heights_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "heights values: "<< heights << std::endl;
  IntegerVector n(1);
  n[0]  = RcppDeepState_int();
  std::string n_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/metadynminer3d/inst/testfiles/hills3d1p12/libFuzzer_hills3d1p12/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_n.qs";
  qs::c_qsave(n,n_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n values: "<< n << std::endl;
  IntegerVector tmin(1);
  tmin[0]  = RcppDeepState_int();
  std::string tmin_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/metadynminer3d/inst/testfiles/hills3d1p12/libFuzzer_hills3d1p12/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_tmin.qs";
  qs::c_qsave(tmin,tmin_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tmin values: "<< tmin << std::endl;
  IntegerVector tmax(1);
  tmax[0]  = RcppDeepState_int();
  std::string tmax_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/metadynminer3d/inst/testfiles/hills3d1p12/libFuzzer_hills3d1p12/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_tmax.qs";
  qs::c_qsave(tmax,tmax_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tmax values: "<< tmax << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    hills3d1p12(cv1,cv2,cv3,width1[0],width2[0],width3[0],heights,n[0],tmin[0],tmax[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
