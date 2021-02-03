#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

IntegerVector find_corres(NumericMatrix X0, NumericMatrix X);

TEST(hetGP_deepstate_test,find_corres_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix X0  = RcppDeepState_NumericMatrix();
  std::string X0_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/hetGP/inst/testfiles/find_corres/libFuzzer_find_corres/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_X0.qs";
  std::string X_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/hetGP/inst/testfiles/find_corres/libFuzzer_find_corres/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_X.qs";
  qs::c_qsave(X0,X0_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "X0 values: "<< X0 << std::endl;
  NumericMatrix X  = RcppDeepState_NumericMatrix();
  std::string X_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/hetGP/inst/testfiles/find_corres/libFuzzer_find_corres/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_X.qs";
  qs::c_qsave(X,X_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "X values: "<< X << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    find_corres(X0,X);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
