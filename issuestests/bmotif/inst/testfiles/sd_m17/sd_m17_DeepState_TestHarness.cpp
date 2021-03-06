// AUTOMATICALLY GENERATED BY RCPPDEEPSTATE PLEASE DO NOT EDIT BY HAND, INSTEAD EDIT
// sd_m17_DeepState_TestHarness_generation.cpp and sd_m17_DeepState_TestHarness_checks.cpp

#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double sd_m17(int NZ, int NP, NumericMatrix W, double m);

TEST(bmotif_deepstate_test,sd_m17_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector NZ(1);
  NZ[0]  = RcppDeepState_int();
  qs::c_qsave(NZ,"/home/akhila/fuzzer_packages/fuzzedpackages/bmotif/inst/testfiles/sd_m17/inputs/NZ.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "NZ values: "<< NZ << std::endl;
  IntegerVector NP(1);
  NP[0]  = RcppDeepState_int();
  qs::c_qsave(NP,"/home/akhila/fuzzer_packages/fuzzedpackages/bmotif/inst/testfiles/sd_m17/inputs/NP.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "NP values: "<< NP << std::endl;
  NumericMatrix W  = RcppDeepState_NumericMatrix();
  qs::c_qsave(W,"/home/akhila/fuzzer_packages/fuzzedpackages/bmotif/inst/testfiles/sd_m17/inputs/W.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "W values: "<< W << std::endl;
  NumericVector m(1);
  m[0]  = RcppDeepState_double();
  qs::c_qsave(m,"/home/akhila/fuzzer_packages/fuzzedpackages/bmotif/inst/testfiles/sd_m17/inputs/m.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "m values: "<< m << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    sd_m17(NZ[0],NP[0],W,m[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
