#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix ipfLGD(NumericMatrix train, NumericMatrix test, double sd, double epsilon);

TEST(ipft_deepstate_test,ipfLGD_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix train  = RcppDeepState_NumericMatrix();
  std::string train_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ipft/inst/testfiles/ipfLGD/libFuzzer_ipfLGD/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_train.qs";
  qs::c_qsave(train,train_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "train values: "<< train << std::endl;
  NumericMatrix test  = RcppDeepState_NumericMatrix();
  std::string test_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ipft/inst/testfiles/ipfLGD/libFuzzer_ipfLGD/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_test.qs";
  qs::c_qsave(test,test_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "test values: "<< test << std::endl;
  NumericVector sd(1);
  sd[0]  = RcppDeepState_double();
  std::string sd_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ipft/inst/testfiles/ipfLGD/libFuzzer_ipfLGD/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_sd.qs";
  qs::c_qsave(sd,sd_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "sd values: "<< sd << std::endl;
  NumericVector epsilon(1);
  epsilon[0]  = RcppDeepState_double();
  std::string epsilon_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ipft/inst/testfiles/ipfLGD/libFuzzer_ipfLGD/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_epsilon.qs";
  qs::c_qsave(epsilon,epsilon_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "epsilon values: "<< epsilon << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    ipfLGD(train,test,sd[0],epsilon[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
