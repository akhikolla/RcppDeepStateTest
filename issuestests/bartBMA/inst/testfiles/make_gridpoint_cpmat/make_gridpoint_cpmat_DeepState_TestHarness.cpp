// AUTOMATICALLY GENERATED BY RCPPDEEPSTATE PLEASE DO NOT EDIT BY HAND, INSTEAD EDIT
// make_gridpoint_cpmat_DeepState_TestHarness_generation.cpp and make_gridpoint_cpmat_DeepState_TestHarness_checks.cpp

#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List make_gridpoint_cpmat(NumericMatrix data, NumericVector resp, int gridsize, int num_cp);

TEST(bartBMA_deepstate_test,make_gridpoint_cpmat_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix data  = RcppDeepState_NumericMatrix();
  qs::c_qsave(data,"/home/akhila/fuzzer_packages/fuzzedpackages/bartBMA/inst/testfiles/make_gridpoint_cpmat/inputs/data.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "data values: "<< data << std::endl;
  NumericVector resp  = RcppDeepState_NumericVector();
  qs::c_qsave(resp,"/home/akhila/fuzzer_packages/fuzzedpackages/bartBMA/inst/testfiles/make_gridpoint_cpmat/inputs/resp.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "resp values: "<< resp << std::endl;
  IntegerVector gridsize(1);
  gridsize[0]  = RcppDeepState_int();
  qs::c_qsave(gridsize,"/home/akhila/fuzzer_packages/fuzzedpackages/bartBMA/inst/testfiles/make_gridpoint_cpmat/inputs/gridsize.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "gridsize values: "<< gridsize << std::endl;
  IntegerVector num_cp(1);
  num_cp[0]  = RcppDeepState_int();
  qs::c_qsave(num_cp,"/home/akhila/fuzzer_packages/fuzzedpackages/bartBMA/inst/testfiles/make_gridpoint_cpmat/inputs/num_cp.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "num_cp values: "<< num_cp << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    make_gridpoint_cpmat(data,resp,gridsize[0],num_cp[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
