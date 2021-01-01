// AUTOMATICALLY GENERATED BY RCPPDEEPSTATE PLEASE DO NOT EDIT BY HAND, INSTEAD EDIT
// dbscan_density_int_DeepState_TestHarness_generation.cpp and dbscan_density_int_DeepState_TestHarness_checks.cpp

#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

IntegerVector dbscan_density_int(NumericMatrix data, double eps, int type, int bucketSize, int splitRule, double approx);

TEST(dbscan_deepstate_test,dbscan_density_int_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix data  = RcppDeepState_NumericMatrix();
  qs::c_qsave(data,"/home/akhila/fuzzer_packages/fuzzedpackages/dbscan/inst/testfiles/dbscan_density_int/inputs/data.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "data values: "<< data << std::endl;
  NumericVector eps(1);
  eps[0]  = RcppDeepState_double();
  qs::c_qsave(eps,"/home/akhila/fuzzer_packages/fuzzedpackages/dbscan/inst/testfiles/dbscan_density_int/inputs/eps.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "eps values: "<< eps << std::endl;
  IntegerVector type(1);
  type[0]  = RcppDeepState_int();
  qs::c_qsave(type,"/home/akhila/fuzzer_packages/fuzzedpackages/dbscan/inst/testfiles/dbscan_density_int/inputs/type.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "type values: "<< type << std::endl;
  IntegerVector bucketSize(1);
  bucketSize[0]  = RcppDeepState_int();
  qs::c_qsave(bucketSize,"/home/akhila/fuzzer_packages/fuzzedpackages/dbscan/inst/testfiles/dbscan_density_int/inputs/bucketSize.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "bucketSize values: "<< bucketSize << std::endl;
  IntegerVector splitRule(1);
  splitRule[0]  = RcppDeepState_int();
  qs::c_qsave(splitRule,"/home/akhila/fuzzer_packages/fuzzedpackages/dbscan/inst/testfiles/dbscan_density_int/inputs/splitRule.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "splitRule values: "<< splitRule << std::endl;
  NumericVector approx(1);
  approx[0]  = RcppDeepState_double();
  qs::c_qsave(approx,"/home/akhila/fuzzer_packages/fuzzedpackages/dbscan/inst/testfiles/dbscan_density_int/inputs/approx.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "approx values: "<< approx << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    dbscan_density_int(data,eps[0],type[0],bucketSize[0],splitRule[0],approx[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
