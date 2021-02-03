#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix EXweib_C(NumericMatrix data, NumericVector k, NumericVector lambda);

TEST(mixR_deepstate_test,EXweib_C_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix data  = RcppDeepState_NumericMatrix();
  std::string data_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mixR/inst/testfiles/EXweib_C/libFuzzer_EXweib_C/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_data.qs";
  qs::c_qsave(data,data_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "data values: "<< data << std::endl;
  NumericVector k  = RcppDeepState_NumericVector();
  std::string k_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mixR/inst/testfiles/EXweib_C/libFuzzer_EXweib_C/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_k.qs";
  qs::c_qsave(k,k_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "k values: "<< k << std::endl;
  NumericVector lambda  = RcppDeepState_NumericVector();
  std::string lambda_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mixR/inst/testfiles/EXweib_C/libFuzzer_EXweib_C/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_lambda.qs";
  qs::c_qsave(lambda,lambda_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lambda values: "<< lambda << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    EXweib_C(data,k,lambda);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
