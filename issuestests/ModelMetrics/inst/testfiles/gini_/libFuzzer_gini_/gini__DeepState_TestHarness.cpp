#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double gini_(NumericVector actual);

TEST(ModelMetrics_deepstate_test,gini__test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector actual  = RcppDeepState_NumericVector();
  std::string actual_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ModelMetrics/inst/testfiles/gini_/libFuzzer_gini_/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_actual.qs";
  qs::c_qsave(actual,actual_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "actual values: "<< actual << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    gini_(actual);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
