#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double recall_(NumericVector actual, NumericVector predicted, double cutoff);

TEST(ModelMetrics_deepstate_test,recall__test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector actual  = RcppDeepState_NumericVector();
  std::string actual_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ModelMetrics/inst/testfiles/recall_/AFL_recall_/afl_inputs/" + std::to_string(t) + "_actual.qs";
  qs::c_qsave(actual,actual_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "actual values: "<< actual << std::endl;
  NumericVector predicted  = RcppDeepState_NumericVector();
  std::string predicted_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ModelMetrics/inst/testfiles/recall_/AFL_recall_/afl_inputs/" + std::to_string(t) + "_predicted.qs";
  qs::c_qsave(predicted,predicted_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "predicted values: "<< predicted << std::endl;
  NumericVector cutoff(1);
  cutoff[0]  = RcppDeepState_double();
  std::string cutoff_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ModelMetrics/inst/testfiles/recall_/AFL_recall_/afl_inputs/" + std::to_string(t) + "_cutoff.qs";
  qs::c_qsave(cutoff,cutoff_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "cutoff values: "<< cutoff << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    recall_(actual,predicted,cutoff[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
