#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector c_get_unique_times(NumericVector true_times, NumericVector req_times);

TEST(mlr3proba_deepstate_test,c_get_unique_times_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector true_times  = RcppDeepState_NumericVector();
  std::string true_times_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mlr3proba/inst/testfiles/c_get_unique_times/AFL_c_get_unique_times/afl_inputs/" + std::to_string(t) + "_true_times.qs";
  qs::c_qsave(true_times,true_times_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "true_times values: "<< true_times << std::endl;
  NumericVector req_times  = RcppDeepState_NumericVector();
  std::string req_times_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mlr3proba/inst/testfiles/c_get_unique_times/AFL_c_get_unique_times/afl_inputs/" + std::to_string(t) + "_req_times.qs";
  qs::c_qsave(req_times,req_times_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "req_times values: "<< req_times << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    c_get_unique_times(true_times,req_times);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
