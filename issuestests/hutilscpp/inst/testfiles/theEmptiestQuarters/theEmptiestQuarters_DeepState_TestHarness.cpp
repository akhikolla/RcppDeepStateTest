// AUTOMATICALLY GENERATED BY RCPPDEEPSTATE PLEASE DO NOT EDIT BY HAND, INSTEAD EDIT
// theEmptiestQuarters_DeepState_TestHarness_generation.cpp and theEmptiestQuarters_DeepState_TestHarness_checks.cpp

#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

IntegerVector theEmptiestQuarters(NumericVector x, NumericVector y, double minx, double maxx, double miny, double maxy, int depth);

TEST(hutilscpp_deepstate_test,theEmptiestQuarters_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  qs::c_qsave(x,"/home/akhila/fuzzer_packages/fuzzedpackages/hutilscpp/inst/testfiles/theEmptiestQuarters/inputs/x.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  qs::c_qsave(y,"/home/akhila/fuzzer_packages/fuzzedpackages/hutilscpp/inst/testfiles/theEmptiestQuarters/inputs/y.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericVector minx(1);
  minx[0]  = RcppDeepState_double();
  qs::c_qsave(minx,"/home/akhila/fuzzer_packages/fuzzedpackages/hutilscpp/inst/testfiles/theEmptiestQuarters/inputs/minx.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "minx values: "<< minx << std::endl;
  NumericVector maxx(1);
  maxx[0]  = RcppDeepState_double();
  qs::c_qsave(maxx,"/home/akhila/fuzzer_packages/fuzzedpackages/hutilscpp/inst/testfiles/theEmptiestQuarters/inputs/maxx.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "maxx values: "<< maxx << std::endl;
  NumericVector miny(1);
  miny[0]  = RcppDeepState_double();
  qs::c_qsave(miny,"/home/akhila/fuzzer_packages/fuzzedpackages/hutilscpp/inst/testfiles/theEmptiestQuarters/inputs/miny.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "miny values: "<< miny << std::endl;
  NumericVector maxy(1);
  maxy[0]  = RcppDeepState_double();
  qs::c_qsave(maxy,"/home/akhila/fuzzer_packages/fuzzedpackages/hutilscpp/inst/testfiles/theEmptiestQuarters/inputs/maxy.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "maxy values: "<< maxy << std::endl;
  IntegerVector depth(1);
  depth[0]  = RcppDeepState_int();
  qs::c_qsave(depth,"/home/akhila/fuzzer_packages/fuzzedpackages/hutilscpp/inst/testfiles/theEmptiestQuarters/inputs/depth.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "depth values: "<< depth << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    theEmptiestQuarters(x,y,minx[0],maxx[0],miny[0],maxy[0],depth[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
