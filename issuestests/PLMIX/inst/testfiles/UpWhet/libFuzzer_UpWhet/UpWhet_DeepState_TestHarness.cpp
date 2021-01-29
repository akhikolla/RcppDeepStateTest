#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector UpWhet(NumericMatrix z_hat, NumericVector alpha0);

TEST(PLMIX_deepstate_test,UpWhet_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix z_hat  = RcppDeepState_NumericMatrix();
  std::string z_hat_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/UpWhet/libFuzzer_UpWhet/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_z_hat.qs";
  qs::c_qsave(z_hat,z_hat_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "z_hat values: "<< z_hat << std::endl;
  NumericVector alpha0  = RcppDeepState_NumericVector();
  std::string alpha0_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/UpWhet/libFuzzer_UpWhet/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_alpha0.qs";
  qs::c_qsave(alpha0,alpha0_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "alpha0 values: "<< alpha0 << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    UpWhet(z_hat,alpha0);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
