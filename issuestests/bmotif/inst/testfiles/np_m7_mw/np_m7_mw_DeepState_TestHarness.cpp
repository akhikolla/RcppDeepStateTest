// AUTOMATICALLY GENERATED BY RCPPDEEPSTATE PLEASE DO NOT EDIT BY HAND, INSTEAD EDIT
// np_m7_mw_DeepState_TestHarness_generation.cpp and np_m7_mw_DeepState_TestHarness_checks.cpp

#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List np_m7_mw(int NZ, int NP, NumericMatrix W);

TEST(bmotif_deepstate_test,np_m7_mw_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector NZ(1);
  NZ[0]  = RcppDeepState_int();
  qs::c_qsave(NZ,"/home/akhila/fuzzer_packages/fuzzedpackages/bmotif/inst/testfiles/np_m7_mw/inputs/NZ.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "NZ values: "<< NZ << std::endl;
  IntegerVector NP(1);
  NP[0]  = RcppDeepState_int();
  qs::c_qsave(NP,"/home/akhila/fuzzer_packages/fuzzedpackages/bmotif/inst/testfiles/np_m7_mw/inputs/NP.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "NP values: "<< NP << std::endl;
  NumericMatrix W  = RcppDeepState_NumericMatrix();
  qs::c_qsave(W,"/home/akhila/fuzzer_packages/fuzzedpackages/bmotif/inst/testfiles/np_m7_mw/inputs/W.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "W values: "<< W << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    np_m7_mw(NZ[0],NP[0],W);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
