#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector c_get_unique_times(NumericVector true_times, NumericVector req_times);

TEST(mlr3proba_deepstate_test,c_get_unique_times_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector true_times  = RcppDeepState_NumericVector();
  qs::c_qsave(true_times,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mlr3proba/inst/testfiles/c_get_unique_times/inputs/true_times.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "true_times values: "<< true_times << std::endl;
  NumericVector req_times  = RcppDeepState_NumericVector();
  qs::c_qsave(req_times,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mlr3proba/inst/testfiles/c_get_unique_times/inputs/req_times.qs",
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
