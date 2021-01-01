// AUTOMATICALLY GENERATED BY RCPPDEEPSTATE PLEASE DO NOT EDIT BY HAND, INSTEAD EDIT
// GoFNS_DeepState_TestHarness_generation.cpp and GoFNS_DeepState_TestHarness_checks.cpp

#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector GoFNS(double t, double n, double m);

TEST(EWGoF_deepstate_test,GoFNS_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector t(1);
  t[0]  = RcppDeepState_double();
  qs::c_qsave(t,"/home/akhila/fuzzer_packages/fuzzedpackages/EWGoF/inst/testfiles/GoFNS/inputs/t.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "t values: "<< t << std::endl;
  NumericVector n(1);
  n[0]  = RcppDeepState_double();
  qs::c_qsave(n,"/home/akhila/fuzzer_packages/fuzzedpackages/EWGoF/inst/testfiles/GoFNS/inputs/n.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n values: "<< n << std::endl;
  NumericVector m(1);
  m[0]  = RcppDeepState_double();
  qs::c_qsave(m,"/home/akhila/fuzzer_packages/fuzzedpackages/EWGoF/inst/testfiles/GoFNS/inputs/m.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "m values: "<< m << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    GoFNS(t[0],n[0],m[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
