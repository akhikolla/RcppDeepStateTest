#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector RcppOwenQ1(int nu, double t, NumericVector delta, NumericVector R, int algo);

TEST(OwenQ_deepstate_test,RcppOwenQ1_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector nu(1);
  nu[0]  = RcppDeepState_int();
  std::string nu_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/RcppOwenQ1/AFL_RcppOwenQ1/afl_inputs/" + std::to_string(t) + "_nu.qs";
  qs::c_qsave(nu,nu_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nu values: "<< nu << std::endl;
  NumericVector t(1);
  t[0]  = RcppDeepState_double();
  std::string t_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/RcppOwenQ1/AFL_RcppOwenQ1/afl_inputs/" + std::to_string(t) + "_t.qs";
  qs::c_qsave(t,t_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "t values: "<< t << std::endl;
  NumericVector delta  = RcppDeepState_NumericVector();
  std::string delta_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/RcppOwenQ1/AFL_RcppOwenQ1/afl_inputs/" + std::to_string(t) + "_delta.qs";
  qs::c_qsave(delta,delta_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "delta values: "<< delta << std::endl;
  NumericVector R  = RcppDeepState_NumericVector();
  std::string R_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/RcppOwenQ1/AFL_RcppOwenQ1/afl_inputs/" + std::to_string(t) + "_R.qs";
  qs::c_qsave(R,R_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "R values: "<< R << std::endl;
  IntegerVector algo(1);
  algo[0]  = RcppDeepState_int();
  std::string algo_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/RcppOwenQ1/AFL_RcppOwenQ1/afl_inputs/" + std::to_string(t) + "_algo.qs";
  qs::c_qsave(algo,algo_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "algo values: "<< algo << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    RcppOwenQ1(nu[0],t[0],delta,R,algo[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
