// AUTOMATICALLY GENERATED BY RCPPDEEPSTATE PLEASE DO NOT EDIT BY HAND, INSTEAD EDIT
// hhgsurv_test_stat_DeepState_TestHarness_generation.cpp and hhgsurv_test_stat_DeepState_TestHarness_checks.cpp

#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List hhgsurv_test_stat(NumericVector s0, NumericVector s1, NumericVector time0, NumericVector time1, NumericVector time, IntegerVector delta, IntegerVector trt, double tau);

TEST(KONPsurv_deepstate_test,hhgsurv_test_stat_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector s0  = RcppDeepState_NumericVector();
  qs::c_qsave(s0,"/home/akhila/fuzzer_packages/fuzzedpackages/KONPsurv/inst/testfiles/hhgsurv_test_stat/inputs/s0.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "s0 values: "<< s0 << std::endl;
  NumericVector s1  = RcppDeepState_NumericVector();
  qs::c_qsave(s1,"/home/akhila/fuzzer_packages/fuzzedpackages/KONPsurv/inst/testfiles/hhgsurv_test_stat/inputs/s1.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "s1 values: "<< s1 << std::endl;
  NumericVector time0  = RcppDeepState_NumericVector();
  qs::c_qsave(time0,"/home/akhila/fuzzer_packages/fuzzedpackages/KONPsurv/inst/testfiles/hhgsurv_test_stat/inputs/time0.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "time0 values: "<< time0 << std::endl;
  NumericVector time1  = RcppDeepState_NumericVector();
  qs::c_qsave(time1,"/home/akhila/fuzzer_packages/fuzzedpackages/KONPsurv/inst/testfiles/hhgsurv_test_stat/inputs/time1.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "time1 values: "<< time1 << std::endl;
  NumericVector time  = RcppDeepState_NumericVector();
  qs::c_qsave(time,"/home/akhila/fuzzer_packages/fuzzedpackages/KONPsurv/inst/testfiles/hhgsurv_test_stat/inputs/time.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "time values: "<< time << std::endl;
  IntegerVector delta  = RcppDeepState_IntegerVector();
  qs::c_qsave(delta,"/home/akhila/fuzzer_packages/fuzzedpackages/KONPsurv/inst/testfiles/hhgsurv_test_stat/inputs/delta.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "delta values: "<< delta << std::endl;
  IntegerVector trt  = RcppDeepState_IntegerVector();
  qs::c_qsave(trt,"/home/akhila/fuzzer_packages/fuzzedpackages/KONPsurv/inst/testfiles/hhgsurv_test_stat/inputs/trt.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "trt values: "<< trt << std::endl;
  NumericVector tau(1);
  tau[0]  = RcppDeepState_double();
  qs::c_qsave(tau,"/home/akhila/fuzzer_packages/fuzzedpackages/KONPsurv/inst/testfiles/hhgsurv_test_stat/inputs/tau.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tau values: "<< tau << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    hhgsurv_test_stat(s0,s1,time0,time1,time,delta,trt,tau[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
