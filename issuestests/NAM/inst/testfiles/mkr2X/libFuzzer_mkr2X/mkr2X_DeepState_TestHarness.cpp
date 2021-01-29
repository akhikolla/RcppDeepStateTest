#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

SEXP mkr2X(NumericMatrix Y, NumericMatrix K1, NumericMatrix K2);

TEST(NAM_deepstate_test,mkr2X_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix Y  = RcppDeepState_NumericMatrix();
  std::string Y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/mkr2X/libFuzzer_mkr2X/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Y.qs";
  qs::c_qsave(Y,Y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Y values: "<< Y << std::endl;
  NumericMatrix K1  = RcppDeepState_NumericMatrix();
  std::string K1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/mkr2X/libFuzzer_mkr2X/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_K1.qs";
  qs::c_qsave(K1,K1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "K1 values: "<< K1 << std::endl;
  NumericMatrix K2  = RcppDeepState_NumericMatrix();
  std::string K2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/mkr2X/libFuzzer_mkr2X/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_K2.qs";
  qs::c_qsave(K2,K2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "K2 values: "<< K2 << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    mkr2X(Y,K1,K2);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
