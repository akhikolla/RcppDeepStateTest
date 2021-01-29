#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector auc_cpp(NumericVector fcst, NumericVector obs);

TEST(SpecsVerification_deepstate_test,auc_cpp_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector fcst  = RcppDeepState_NumericVector();
  std::string fcst_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/SpecsVerification/inst/testfiles/auc_cpp/libFuzzer_auc_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_fcst.qs";
  qs::c_qsave(fcst,fcst_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "fcst values: "<< fcst << std::endl;
  NumericVector obs  = RcppDeepState_NumericVector();
  std::string obs_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/SpecsVerification/inst/testfiles/auc_cpp/libFuzzer_auc_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_obs.qs";
  qs::c_qsave(obs,obs_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "obs values: "<< obs << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    auc_cpp(fcst,obs);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
