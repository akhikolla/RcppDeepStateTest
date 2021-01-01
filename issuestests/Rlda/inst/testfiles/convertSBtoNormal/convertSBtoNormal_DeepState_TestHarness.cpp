// AUTOMATICALLY GENERATED BY RCPPDEEPSTATE PLEASE DO NOT EDIT BY HAND, INSTEAD EDIT
// convertSBtoNormal_DeepState_TestHarness_generation.cpp and convertSBtoNormal_DeepState_TestHarness_checks.cpp

#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix convertSBtoNormal(NumericMatrix vmat, int ncol, int nrow, NumericVector prod);

TEST(Rlda_deepstate_test,convertSBtoNormal_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix vmat  = RcppDeepState_NumericMatrix();
  qs::c_qsave(vmat,"/home/akhila/fuzzer_packages/fuzzedpackages/Rlda/inst/testfiles/convertSBtoNormal/inputs/vmat.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "vmat values: "<< vmat << std::endl;
  IntegerVector ncol(1);
  ncol[0]  = RcppDeepState_int();
  qs::c_qsave(ncol,"/home/akhila/fuzzer_packages/fuzzedpackages/Rlda/inst/testfiles/convertSBtoNormal/inputs/ncol.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ncol values: "<< ncol << std::endl;
  IntegerVector nrow(1);
  nrow[0]  = RcppDeepState_int();
  qs::c_qsave(nrow,"/home/akhila/fuzzer_packages/fuzzedpackages/Rlda/inst/testfiles/convertSBtoNormal/inputs/nrow.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nrow values: "<< nrow << std::endl;
  NumericVector prod  = RcppDeepState_NumericVector();
  qs::c_qsave(prod,"/home/akhila/fuzzer_packages/fuzzedpackages/Rlda/inst/testfiles/convertSBtoNormal/inputs/prod.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "prod values: "<< prod << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    convertSBtoNormal(vmat,ncol[0],nrow[0],prod);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
