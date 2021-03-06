// AUTOMATICALLY GENERATED BY RCPPDEEPSTATE PLEASE DO NOT EDIT BY HAND, INSTEAD EDIT
// d11_DeepState_TestHarness_generation.cpp and d11_DeepState_TestHarness_checks.cpp

#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double d11(NumericVector T, double x, double xl, NumericMatrix inv, NumericMatrix inv1, int order);

TEST(Opt5PL_deepstate_test,d11_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector T  = RcppDeepState_NumericVector();
  std::string T_t = "/home/akhila/fuzzer_packages/fuzzedpackages/Opt5PL/inst/testfiles/d11/libFuzzer_d11/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_T.qs";
  qs::c_qsave(T,T_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "T values: "<< T << std::endl;
  NumericVector x(1);
  x[0]  = RcppDeepState_double();
  std::string x_t = "/home/akhila/fuzzer_packages/fuzzedpackages/Opt5PL/inst/testfiles/d11/libFuzzer_d11/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector xl(1);
  xl[0]  = RcppDeepState_double();
  std::string x_t = "/home/akhila/fuzzer_packages/fuzzedpackages/Opt5PL/inst/testfiles/d11/libFuzzer_d11/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_x.qs";
  std::string xl_t = "/home/akhila/fuzzer_packages/fuzzedpackages/Opt5PL/inst/testfiles/d11/libFuzzer_d11/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_xl.qs";
  qs::c_qsave(xl,xl_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "xl values: "<< xl << std::endl;
  NumericMatrix inv  = RcppDeepState_NumericMatrix();
  std::string inv_t = "/home/akhila/fuzzer_packages/fuzzedpackages/Opt5PL/inst/testfiles/d11/libFuzzer_d11/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_inv.qs";
  qs::c_qsave(inv,inv_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "inv values: "<< inv << std::endl;
  NumericMatrix inv1  = RcppDeepState_NumericMatrix();
  std::string inv_t = "/home/akhila/fuzzer_packages/fuzzedpackages/Opt5PL/inst/testfiles/d11/libFuzzer_d11/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_inv.qs";
  std::string inv1_t = "/home/akhila/fuzzer_packages/fuzzedpackages/Opt5PL/inst/testfiles/d11/libFuzzer_d11/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_inv1.qs";
  qs::c_qsave(inv1,inv1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "inv1 values: "<< inv1 << std::endl;
  IntegerVector order(1);
  order[0]  = RcppDeepState_int();
  std::string order_t = "/home/akhila/fuzzer_packages/fuzzedpackages/Opt5PL/inst/testfiles/d11/libFuzzer_d11/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_order.qs";
  qs::c_qsave(order,order_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "order values: "<< order << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    d11(T,x[0],xl[0],inv,inv1,order[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
