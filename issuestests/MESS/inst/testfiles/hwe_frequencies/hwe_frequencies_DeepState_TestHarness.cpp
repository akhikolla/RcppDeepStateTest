// AUTOMATICALLY GENERATED BY RCPPDEEPSTATE PLEASE DO NOT EDIT BY HAND, INSTEAD EDIT
// hwe_frequencies_DeepState_TestHarness_generation.cpp and hwe_frequencies_DeepState_TestHarness_checks.cpp

#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List hwe_frequencies(IntegerVector allele1, IntegerVector allele2, int min_alleles);

TEST(MESS_deepstate_test,hwe_frequencies_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector allele1  = RcppDeepState_IntegerVector();
  qs::c_qsave(allele1,"/home/akhila/fuzzer_packages/fuzzedpackages/MESS/inst/testfiles/hwe_frequencies/inputs/allele1.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "allele1 values: "<< allele1 << std::endl;
  IntegerVector allele2  = RcppDeepState_IntegerVector();
  qs::c_qsave(allele2,"/home/akhila/fuzzer_packages/fuzzedpackages/MESS/inst/testfiles/hwe_frequencies/inputs/allele2.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "allele2 values: "<< allele2 << std::endl;
  IntegerVector min_alleles(1);
  min_alleles[0]  = RcppDeepState_int();
  qs::c_qsave(min_alleles,"/home/akhila/fuzzer_packages/fuzzedpackages/MESS/inst/testfiles/hwe_frequencies/inputs/min_alleles.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "min_alleles values: "<< min_alleles << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    hwe_frequencies(allele1,allele2,min_alleles[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
