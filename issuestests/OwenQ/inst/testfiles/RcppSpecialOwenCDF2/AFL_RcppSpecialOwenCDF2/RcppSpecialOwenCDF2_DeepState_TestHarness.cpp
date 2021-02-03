#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector RcppSpecialOwenCDF2(int nu, double t, NumericVector delta, int algo);

TEST(OwenQ_deepstate_test,RcppSpecialOwenCDF2_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector nu(1);
  nu[0]  = RcppDeepState_int();
  std::string nu_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/RcppSpecialOwenCDF2/AFL_RcppSpecialOwenCDF2/afl_inputs/" + std::to_string(t) + "_nu.qs";
  qs::c_qsave(nu,nu_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nu values: "<< nu << std::endl;
  NumericVector t(1);
  t[0]  = RcppDeepState_double();
  std::string t_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/RcppSpecialOwenCDF2/AFL_RcppSpecialOwenCDF2/afl_inputs/" + std::to_string(t) + "_t.qs";
  qs::c_qsave(t,t_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "t values: "<< t << std::endl;
  NumericVector delta  = RcppDeepState_NumericVector();
  std::string delta_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/RcppSpecialOwenCDF2/AFL_RcppSpecialOwenCDF2/afl_inputs/" + std::to_string(t) + "_delta.qs";
  qs::c_qsave(delta,delta_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "delta values: "<< delta << std::endl;
  IntegerVector algo(1);
  algo[0]  = RcppDeepState_int();
  std::string algo_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/RcppSpecialOwenCDF2/AFL_RcppSpecialOwenCDF2/afl_inputs/" + std::to_string(t) + "_algo.qs";
  qs::c_qsave(algo,algo_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "algo values: "<< algo << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    RcppSpecialOwenCDF2(nu[0],t[0],delta,algo[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
