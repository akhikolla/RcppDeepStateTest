#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

SEXP mrr2X(NumericMatrix Y, NumericMatrix X1, NumericMatrix X2);

TEST(NAM_deepstate_test,mrr2X_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix Y  = RcppDeepState_NumericMatrix();
  std::string Y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/mrr2X/libFuzzer_mrr2X/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Y.qs";
  qs::c_qsave(Y,Y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Y values: "<< Y << std::endl;
  NumericMatrix X1  = RcppDeepState_NumericMatrix();
  std::string X1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/mrr2X/libFuzzer_mrr2X/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_X1.qs";
  qs::c_qsave(X1,X1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "X1 values: "<< X1 << std::endl;
  NumericMatrix X2  = RcppDeepState_NumericMatrix();
  std::string X2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/mrr2X/libFuzzer_mrr2X/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_X2.qs";
  qs::c_qsave(X2,X2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "X2 values: "<< X2 << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    mrr2X(Y,X1,X2);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
