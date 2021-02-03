#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix ipfNormDistance(NumericMatrix train, NumericMatrix test, double normVal);

TEST(ipft_deepstate_test,ipfNormDistance_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix train  = RcppDeepState_NumericMatrix();
  std::string train_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ipft/inst/testfiles/ipfNormDistance/libFuzzer_ipfNormDistance/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_train.qs";
  qs::c_qsave(train,train_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "train values: "<< train << std::endl;
  NumericMatrix test  = RcppDeepState_NumericMatrix();
  std::string test_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ipft/inst/testfiles/ipfNormDistance/libFuzzer_ipfNormDistance/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_test.qs";
  qs::c_qsave(test,test_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "test values: "<< test << std::endl;
  NumericVector normVal(1);
  normVal[0]  = RcppDeepState_double();
  std::string normVal_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ipft/inst/testfiles/ipfNormDistance/libFuzzer_ipfNormDistance/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_normVal.qs";
  qs::c_qsave(normVal,normVal_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "normVal values: "<< normVal << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    ipfNormDistance(train,test,normVal[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
