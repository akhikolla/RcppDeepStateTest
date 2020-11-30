#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double auc3_(NumericVector actual, NumericVector predicted, NumericVector ranks);

TEST(ModelMetrics_deepstate_test,auc3__test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector actual  = RcppDeepState_NumericVector();
  std::string actual_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ModelMetrics/inst/testfiles/auc3_/AFL_auc3_/afl_inputs/" + std::to_string(t) + "_actual.qs";
  qs::c_qsave(actual,actual_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "actual values: "<< actual << std::endl;
  NumericVector predicted  = RcppDeepState_NumericVector();
  std::string predicted_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ModelMetrics/inst/testfiles/auc3_/AFL_auc3_/afl_inputs/" + std::to_string(t) + "_predicted.qs";
  qs::c_qsave(predicted,predicted_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "predicted values: "<< predicted << std::endl;
  NumericVector ranks  = RcppDeepState_NumericVector();
  std::string ranks_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ModelMetrics/inst/testfiles/auc3_/AFL_auc3_/afl_inputs/" + std::to_string(t) + "_ranks.qs";
  qs::c_qsave(ranks,ranks_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ranks values: "<< ranks << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    auc3_(actual,predicted,ranks);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
