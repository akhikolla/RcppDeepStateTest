// AUTOMATICALLY GENERATED BY RCPPDEEPSTATE PLEASE DO NOT EDIT BY HAND, INSTEAD EDIT
// lun_eclipse_how_DeepState_TestHarness_generation.cpp and lun_eclipse_how_DeepState_TestHarness_checks.cpp

#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::List lun_eclipse_how(double jd_ut, int ephe_flag, Rcpp::NumericVector geopos);

TEST(swephR_deepstate_test,lun_eclipse_how_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector jd_ut(1);
  jd_ut[0]  = RcppDeepState_double();
  qs::c_qsave(jd_ut,"/home/akhila/fuzzer_packages/fuzzedpackages/swephR/inst/testfiles/lun_eclipse_how/inputs/jd_ut.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "jd_ut values: "<< jd_ut << std::endl;
  IntegerVector ephe_flag(1);
  ephe_flag[0]  = RcppDeepState_int();
  qs::c_qsave(ephe_flag,"/home/akhila/fuzzer_packages/fuzzedpackages/swephR/inst/testfiles/lun_eclipse_how/inputs/ephe_flag.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ephe_flag values: "<< ephe_flag << std::endl;
  NumericVector geopos  = RcppDeepState_NumericVector();
  qs::c_qsave(geopos,"/home/akhila/fuzzer_packages/fuzzedpackages/swephR/inst/testfiles/lun_eclipse_how/inputs/geopos.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "geopos values: "<< geopos << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    lun_eclipse_how(jd_ut[0],ephe_flag[0],geopos);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
