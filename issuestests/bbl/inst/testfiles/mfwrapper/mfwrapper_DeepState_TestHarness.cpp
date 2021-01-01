// AUTOMATICALLY GENERATED BY RCPPDEEPSTATE PLEASE DO NOT EDIT BY HAND, INSTEAD EDIT
// mfwrapper_DeepState_TestHarness_generation.cpp and mfwrapper_DeepState_TestHarness_checks.cpp

#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List mfwrapper(NumericMatrix xi, IntegerVector weights, NumericMatrix qJ, IntegerVector Lv, NumericVector Eps, NumericVector priorCount);

TEST(bbl_deepstate_test,mfwrapper_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix xi  = RcppDeepState_NumericMatrix();
  qs::c_qsave(xi,"/home/akhila/fuzzer_packages/fuzzedpackages/bbl/inst/testfiles/mfwrapper/inputs/xi.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "xi values: "<< xi << std::endl;
  IntegerVector weights  = RcppDeepState_IntegerVector();
  qs::c_qsave(weights,"/home/akhila/fuzzer_packages/fuzzedpackages/bbl/inst/testfiles/mfwrapper/inputs/weights.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "weights values: "<< weights << std::endl;
  NumericMatrix qJ  = RcppDeepState_NumericMatrix();
  qs::c_qsave(qJ,"/home/akhila/fuzzer_packages/fuzzedpackages/bbl/inst/testfiles/mfwrapper/inputs/qJ.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "qJ values: "<< qJ << std::endl;
  IntegerVector Lv  = RcppDeepState_IntegerVector();
  qs::c_qsave(Lv,"/home/akhila/fuzzer_packages/fuzzedpackages/bbl/inst/testfiles/mfwrapper/inputs/Lv.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Lv values: "<< Lv << std::endl;
  NumericVector Eps  = RcppDeepState_NumericVector();
  qs::c_qsave(Eps,"/home/akhila/fuzzer_packages/fuzzedpackages/bbl/inst/testfiles/mfwrapper/inputs/Eps.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Eps values: "<< Eps << std::endl;
  NumericVector priorCount  = RcppDeepState_NumericVector();
  qs::c_qsave(priorCount,"/home/akhila/fuzzer_packages/fuzzedpackages/bbl/inst/testfiles/mfwrapper/inputs/priorCount.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "priorCount values: "<< priorCount << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    mfwrapper(xi,weights,qJ,Lv,Eps,priorCount);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
