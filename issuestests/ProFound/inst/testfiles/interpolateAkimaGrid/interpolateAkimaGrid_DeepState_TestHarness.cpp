// AUTOMATICALLY GENERATED BY RCPPDEEPSTATE PLEASE DO NOT EDIT BY HAND, INSTEAD EDIT
// interpolateAkimaGrid_DeepState_TestHarness_generation.cpp and interpolateAkimaGrid_DeepState_TestHarness_checks.cpp

#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

void interpolateAkimaGrid(NumericVector x, NumericVector y, NumericMatrix grid, NumericMatrix output);

TEST(ProFound_deepstate_test,interpolateAkimaGrid_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  qs::c_qsave(x,"/home/akhila/fuzzer_packages/fuzzedpackages/ProFound/inst/testfiles/interpolateAkimaGrid/inputs/x.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  qs::c_qsave(y,"/home/akhila/fuzzer_packages/fuzzedpackages/ProFound/inst/testfiles/interpolateAkimaGrid/inputs/y.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericMatrix grid  = RcppDeepState_NumericMatrix();
  qs::c_qsave(grid,"/home/akhila/fuzzer_packages/fuzzedpackages/ProFound/inst/testfiles/interpolateAkimaGrid/inputs/grid.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "grid values: "<< grid << std::endl;
  NumericMatrix output  = RcppDeepState_NumericMatrix();
  qs::c_qsave(output,"/home/akhila/fuzzer_packages/fuzzedpackages/ProFound/inst/testfiles/interpolateAkimaGrid/inputs/output.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "output values: "<< output << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    interpolateAkimaGrid(x,y,grid,output);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
