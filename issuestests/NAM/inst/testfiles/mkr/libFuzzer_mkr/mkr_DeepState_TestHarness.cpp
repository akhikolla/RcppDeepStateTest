#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

SEXP mkr(NumericMatrix Y, NumericMatrix K);

TEST(NAM_deepstate_test,mkr_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix Y  = RcppDeepState_NumericMatrix();
  std::string Y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/mkr/libFuzzer_mkr/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Y.qs";
  qs::c_qsave(Y,Y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Y values: "<< Y << std::endl;
  NumericMatrix K  = RcppDeepState_NumericMatrix();
  std::string K_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/mkr/libFuzzer_mkr/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_K.qs";
  qs::c_qsave(K,K_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "K values: "<< K << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    mkr(Y,K);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
