// AUTOMATICALLY GENERATED BY RCPPDEEPSTATE PLEASE DO NOT EDIT BY HAND, INSTEAD EDIT
// haversine_DeepState_TestHarness_generation.cpp and haversine_DeepState_TestHarness_checks.cpp

#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericVector haversine(Rcpp::NumericVector lat1, Rcpp::NumericVector lon1, Rcpp::NumericVector lat2, Rcpp::NumericVector lon2);

TEST(hans_deepstate_test,haversine_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector lat1  = RcppDeepState_NumericVector();
  std::string lat1_t = "/home/akhila/fuzzer_packages/fuzzedpackages/hans/inst/testfiles/haversine/AFL_haversine/afl_inputs/" + std::to_string(t) + "_lat1.qs";
  qs::c_qsave(lat1,lat1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lat1 values: "<< lat1 << std::endl;
  NumericVector lon1  = RcppDeepState_NumericVector();
  std::string lon1_t = "/home/akhila/fuzzer_packages/fuzzedpackages/hans/inst/testfiles/haversine/AFL_haversine/afl_inputs/" + std::to_string(t) + "_lon1.qs";
  qs::c_qsave(lon1,lon1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lon1 values: "<< lon1 << std::endl;
  NumericVector lat2  = RcppDeepState_NumericVector();
  std::string lat2_t = "/home/akhila/fuzzer_packages/fuzzedpackages/hans/inst/testfiles/haversine/AFL_haversine/afl_inputs/" + std::to_string(t) + "_lat2.qs";
  qs::c_qsave(lat2,lat2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lat2 values: "<< lat2 << std::endl;
  NumericVector lon2  = RcppDeepState_NumericVector();
  std::string lon2_t = "/home/akhila/fuzzer_packages/fuzzedpackages/hans/inst/testfiles/haversine/AFL_haversine/afl_inputs/" + std::to_string(t) + "_lon2.qs";
  qs::c_qsave(lon2,lon2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lon2 values: "<< lon2 << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    haversine(lat1,lon1,lat2,lon2);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
