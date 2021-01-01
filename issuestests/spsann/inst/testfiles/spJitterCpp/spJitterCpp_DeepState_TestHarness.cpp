// AUTOMATICALLY GENERATED BY RCPPDEEPSTATE PLEASE DO NOT EDIT BY HAND, INSTEAD EDIT
// spJitterCpp_DeepState_TestHarness_generation.cpp and spJitterCpp_DeepState_TestHarness_checks.cpp

#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

IntegerVector spJitterCpp(NumericMatrix x, NumericMatrix y, double xmax, double xmin, double ymax, double ymin, int idx);

TEST(spsann_deepstate_test,spJitterCpp_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix x  = RcppDeepState_NumericMatrix();
  qs::c_qsave(x,"/home/akhila/fuzzer_packages/fuzzedpackages/spsann/inst/testfiles/spJitterCpp/inputs/x.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericMatrix y  = RcppDeepState_NumericMatrix();
  qs::c_qsave(y,"/home/akhila/fuzzer_packages/fuzzedpackages/spsann/inst/testfiles/spJitterCpp/inputs/y.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericVector xmax(1);
  xmax[0]  = RcppDeepState_double();
  qs::c_qsave(xmax,"/home/akhila/fuzzer_packages/fuzzedpackages/spsann/inst/testfiles/spJitterCpp/inputs/xmax.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "xmax values: "<< xmax << std::endl;
  NumericVector xmin(1);
  xmin[0]  = RcppDeepState_double();
  qs::c_qsave(xmin,"/home/akhila/fuzzer_packages/fuzzedpackages/spsann/inst/testfiles/spJitterCpp/inputs/xmin.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "xmin values: "<< xmin << std::endl;
  NumericVector ymax(1);
  ymax[0]  = RcppDeepState_double();
  qs::c_qsave(ymax,"/home/akhila/fuzzer_packages/fuzzedpackages/spsann/inst/testfiles/spJitterCpp/inputs/ymax.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ymax values: "<< ymax << std::endl;
  NumericVector ymin(1);
  ymin[0]  = RcppDeepState_double();
  qs::c_qsave(ymin,"/home/akhila/fuzzer_packages/fuzzedpackages/spsann/inst/testfiles/spJitterCpp/inputs/ymin.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ymin values: "<< ymin << std::endl;
  IntegerVector idx(1);
  idx[0]  = RcppDeepState_int();
  qs::c_qsave(idx,"/home/akhila/fuzzer_packages/fuzzedpackages/spsann/inst/testfiles/spJitterCpp/inputs/idx.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "idx values: "<< idx << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    spJitterCpp(x,y,xmax[0],xmin[0],ymax[0],ymin[0],idx[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
