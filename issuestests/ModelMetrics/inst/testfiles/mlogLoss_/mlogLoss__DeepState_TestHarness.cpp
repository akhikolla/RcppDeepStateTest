#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double mlogLoss_(NumericVector actual, NumericMatrix predicted);

TEST(ModelMetrics_deepstate_test,mlogLoss__test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector actual  = RcppDeepState_NumericVector();
  qs::c_qsave(actual,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ModelMetrics/inst/testfiles/mlogLoss_/inputs/actual.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "actual values: "<< actual << std::endl;
  NumericMatrix predicted  = RcppDeepState_NumericMatrix();
  qs::c_qsave(predicted,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ModelMetrics/inst/testfiles/mlogLoss_/inputs/predicted.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "predicted values: "<< predicted << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    mlogLoss_(actual,predicted);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
