// AUTOMATICALLY GENERATED BY RCPPDEEPSTATE PLEASE DO NOT EDIT BY HAND, INSTEAD EDIT
// updateresidual_DeepState_TestHarness_generation.cpp and updateresidual_DeepState_TestHarness_checks.cpp

#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

void updateresidual(NumericVector resid, NumericVector y, NumericMatrix thetamat, int j, int n, int p);

TEST(flam_deepstate_test,updateresidual_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector resid  = RcppDeepState_NumericVector();
  qs::c_qsave(resid,"/home/akhila/fuzzer_packages/fuzzedpackages/flam/inst/testfiles/updateresidual/inputs/resid.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "resid values: "<< resid << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  qs::c_qsave(y,"/home/akhila/fuzzer_packages/fuzzedpackages/flam/inst/testfiles/updateresidual/inputs/y.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericMatrix thetamat  = RcppDeepState_NumericMatrix();
  qs::c_qsave(thetamat,"/home/akhila/fuzzer_packages/fuzzedpackages/flam/inst/testfiles/updateresidual/inputs/thetamat.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "thetamat values: "<< thetamat << std::endl;
  IntegerVector j(1);
  j[0]  = RcppDeepState_int();
  qs::c_qsave(j,"/home/akhila/fuzzer_packages/fuzzedpackages/flam/inst/testfiles/updateresidual/inputs/j.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "j values: "<< j << std::endl;
  IntegerVector n(1);
  n[0]  = RcppDeepState_int();
  qs::c_qsave(n,"/home/akhila/fuzzer_packages/fuzzedpackages/flam/inst/testfiles/updateresidual/inputs/n.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n values: "<< n << std::endl;
  IntegerVector p(1);
  p[0]  = RcppDeepState_int();
  qs::c_qsave(p,"/home/akhila/fuzzer_packages/fuzzedpackages/flam/inst/testfiles/updateresidual/inputs/p.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "p values: "<< p << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    updateresidual(resid,y,thetamat,j[0],n[0],p[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
