#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix expZ_weib_C(NumericVector x, NumericVector pi, NumericVector k, NumericVector lambda);

TEST(mixR_deepstate_test,expZ_weib_C_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mixR/inst/testfiles/expZ_weib_C/libFuzzer_expZ_weib_C/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector pi  = RcppDeepState_NumericVector();
  std::string pi_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mixR/inst/testfiles/expZ_weib_C/libFuzzer_expZ_weib_C/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_pi.qs";
  qs::c_qsave(pi,pi_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pi values: "<< pi << std::endl;
  NumericVector k  = RcppDeepState_NumericVector();
  std::string k_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mixR/inst/testfiles/expZ_weib_C/libFuzzer_expZ_weib_C/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_k.qs";
  qs::c_qsave(k,k_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "k values: "<< k << std::endl;
  NumericVector lambda  = RcppDeepState_NumericVector();
  std::string lambda_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mixR/inst/testfiles/expZ_weib_C/libFuzzer_expZ_weib_C/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_lambda.qs";
  qs::c_qsave(lambda,lambda_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lambda values: "<< lambda << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    expZ_weib_C(x,pi,k,lambda);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
