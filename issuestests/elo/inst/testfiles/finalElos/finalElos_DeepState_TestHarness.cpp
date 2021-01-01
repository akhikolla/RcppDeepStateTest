// AUTOMATICALLY GENERATED BY RCPPDEEPSTATE PLEASE DO NOT EDIT BY HAND, INSTEAD EDIT
// finalElos_DeepState_TestHarness_generation.cpp and finalElos_DeepState_TestHarness_checks.cpp

#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector finalElos(NumericMatrix mat, int nTeams);

TEST(elo_deepstate_test,finalElos_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix mat  = RcppDeepState_NumericMatrix();
  qs::c_qsave(mat,"/home/akhila/fuzzer_packages/fuzzedpackages/elo/inst/testfiles/finalElos/inputs/mat.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "mat values: "<< mat << std::endl;
  IntegerVector nTeams(1);
  nTeams[0]  = RcppDeepState_int();
  qs::c_qsave(nTeams,"/home/akhila/fuzzer_packages/fuzzedpackages/elo/inst/testfiles/finalElos/inputs/nTeams.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nTeams values: "<< nTeams << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    finalElos(mat,nTeams[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
