// AUTOMATICALLY GENERATED BY RCPPDEEPSTATE PLEASE DO NOT EDIT BY HAND, INSTEAD EDIT
// match_ij_DeepState_TestHarness_generation.cpp and match_ij_DeepState_TestHarness_checks.cpp

#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

IntegerVector match_ij(IntegerVector ix, IntegerVector jx, IntegerVector ti, IntegerVector tj);

TEST(multbxxc_deepstate_test,match_ij_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector ix  = RcppDeepState_IntegerVector();
  qs::c_qsave(ix,"/home/akhila/fuzzer_packages/fuzzedpackages/multbxxc/inst/testfiles/match_ij/inputs/ix.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ix values: "<< ix << std::endl;
  IntegerVector jx  = RcppDeepState_IntegerVector();
  qs::c_qsave(jx,"/home/akhila/fuzzer_packages/fuzzedpackages/multbxxc/inst/testfiles/match_ij/inputs/jx.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "jx values: "<< jx << std::endl;
  IntegerVector ti  = RcppDeepState_IntegerVector();
  qs::c_qsave(ti,"/home/akhila/fuzzer_packages/fuzzedpackages/multbxxc/inst/testfiles/match_ij/inputs/ti.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ti values: "<< ti << std::endl;
  IntegerVector tj  = RcppDeepState_IntegerVector();
  qs::c_qsave(tj,"/home/akhila/fuzzer_packages/fuzzedpackages/multbxxc/inst/testfiles/match_ij/inputs/tj.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tj values: "<< tj << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    match_ij(ix,jx,ti,tj);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
