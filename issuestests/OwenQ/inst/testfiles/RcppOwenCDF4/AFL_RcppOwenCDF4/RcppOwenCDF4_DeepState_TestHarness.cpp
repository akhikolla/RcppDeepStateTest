#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector RcppOwenCDF4(int nu, double t1, double t2, NumericVector delta1, NumericVector delta2, int algo);

TEST(OwenQ_deepstate_test,RcppOwenCDF4_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector nu(1);
  nu[0]  = RcppDeepState_int();
  std::string nu_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/RcppOwenCDF4/AFL_RcppOwenCDF4/afl_inputs/" + std::to_string(t) + "_nu.qs";
  qs::c_qsave(nu,nu_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nu values: "<< nu << std::endl;
  NumericVector t1(1);
  t1[0]  = RcppDeepState_double();
  std::string t1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/RcppOwenCDF4/AFL_RcppOwenCDF4/afl_inputs/" + std::to_string(t) + "_t1.qs";
  qs::c_qsave(t1,t1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "t1 values: "<< t1 << std::endl;
  NumericVector t2(1);
  t2[0]  = RcppDeepState_double();
  std::string t2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/RcppOwenCDF4/AFL_RcppOwenCDF4/afl_inputs/" + std::to_string(t) + "_t2.qs";
  qs::c_qsave(t2,t2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "t2 values: "<< t2 << std::endl;
  NumericVector delta1  = RcppDeepState_NumericVector();
  std::string delta1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/RcppOwenCDF4/AFL_RcppOwenCDF4/afl_inputs/" + std::to_string(t) + "_delta1.qs";
  qs::c_qsave(delta1,delta1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "delta1 values: "<< delta1 << std::endl;
  NumericVector delta2  = RcppDeepState_NumericVector();
  std::string delta2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/RcppOwenCDF4/AFL_RcppOwenCDF4/afl_inputs/" + std::to_string(t) + "_delta2.qs";
  qs::c_qsave(delta2,delta2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "delta2 values: "<< delta2 << std::endl;
  IntegerVector algo(1);
  algo[0]  = RcppDeepState_int();
  std::string algo_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/RcppOwenCDF4/AFL_RcppOwenCDF4/afl_inputs/" + std::to_string(t) + "_algo.qs";
  qs::c_qsave(algo,algo_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "algo values: "<< algo << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    RcppOwenCDF4(nu[0],t1[0],t2[0],delta1,delta2,algo[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
