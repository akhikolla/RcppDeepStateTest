#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix ipfEuclidean(NumericMatrix train, NumericMatrix test);

TEST(ipft_deepstate_test,ipfEuclidean_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix train  = RcppDeepState_NumericMatrix();
  std::string train_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ipft/inst/testfiles/ipfEuclidean/libFuzzer_ipfEuclidean/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_train.qs";
  qs::c_qsave(train,train_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "train values: "<< train << std::endl;
  NumericMatrix test  = RcppDeepState_NumericMatrix();
  std::string test_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ipft/inst/testfiles/ipfEuclidean/libFuzzer_ipfEuclidean/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_test.qs";
  qs::c_qsave(test,test_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "test values: "<< test << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    ipfEuclidean(train,test);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
