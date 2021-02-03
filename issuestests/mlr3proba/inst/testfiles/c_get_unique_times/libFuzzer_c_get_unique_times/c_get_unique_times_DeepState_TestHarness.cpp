#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector c_get_unique_times(NumericVector true_times, NumericVector req_times);

TEST(mlr3proba_deepstate_test,c_get_unique_times_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector true_times  = RcppDeepState_NumericVector();
  std::string true_times_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mlr3proba/inst/testfiles/c_get_unique_times/libFuzzer_c_get_unique_times/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_true_times.qs";
  qs::c_qsave(true_times,true_times_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "true_times values: "<< true_times << std::endl;
  NumericVector req_times  = RcppDeepState_NumericVector();
  std::string req_times_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mlr3proba/inst/testfiles/c_get_unique_times/libFuzzer_c_get_unique_times/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_req_times.qs";
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
