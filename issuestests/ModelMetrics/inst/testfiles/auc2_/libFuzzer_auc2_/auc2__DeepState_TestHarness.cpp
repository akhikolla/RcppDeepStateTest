#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double auc2_(NumericVector actual, NumericVector predicted);

TEST(ModelMetrics_deepstate_test,auc2__test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector actual  = RcppDeepState_NumericVector();
  std::string actual_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ModelMetrics/inst/testfiles/auc2_/libFuzzer_auc2_/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_actual.qs";
  qs::c_qsave(actual,actual_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "actual values: "<< actual << std::endl;
  NumericVector predicted  = RcppDeepState_NumericVector();
  std::string predicted_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ModelMetrics/inst/testfiles/auc2_/libFuzzer_auc2_/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_predicted.qs";
  qs::c_qsave(predicted,predicted_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "predicted values: "<< predicted << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    auc2_(actual,predicted);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
