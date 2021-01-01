// AUTOMATICALLY GENERATED BY RCPPDEEPSTATE PLEASE DO NOT EDIT BY HAND, INSTEAD EDIT
// scale_response_gs_DeepState_TestHarness_generation.cpp and scale_response_gs_DeepState_TestHarness_checks.cpp

#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector scale_response_gs(double a, double b, double c, double d, NumericVector y);

TEST(bartBMA_deepstate_test,scale_response_gs_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector a(1);
  a[0]  = RcppDeepState_double();
  qs::c_qsave(a,"/home/akhila/fuzzer_packages/fuzzedpackages/bartBMA/inst/testfiles/scale_response_gs/inputs/a.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "a values: "<< a << std::endl;
  NumericVector b(1);
  b[0]  = RcppDeepState_double();
  qs::c_qsave(b,"/home/akhila/fuzzer_packages/fuzzedpackages/bartBMA/inst/testfiles/scale_response_gs/inputs/b.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "b values: "<< b << std::endl;
  NumericVector c(1);
  c[0]  = RcppDeepState_double();
  qs::c_qsave(c,"/home/akhila/fuzzer_packages/fuzzedpackages/bartBMA/inst/testfiles/scale_response_gs/inputs/c.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "c values: "<< c << std::endl;
  NumericVector d(1);
  d[0]  = RcppDeepState_double();
  qs::c_qsave(d,"/home/akhila/fuzzer_packages/fuzzedpackages/bartBMA/inst/testfiles/scale_response_gs/inputs/d.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "d values: "<< d << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  qs::c_qsave(y,"/home/akhila/fuzzer_packages/fuzzedpackages/bartBMA/inst/testfiles/scale_response_gs/inputs/y.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    scale_response_gs(a[0],b[0],c[0],d[0],y);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
