#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List getScatterMatrix(NumericMatrix II_, NumericMatrix X_, NumericMatrix H_);

TEST(kcpRS_deepstate_test,getScatterMatrix_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix II_  = RcppDeepState_NumericMatrix();
  std::string II__t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/kcpRS/inst/testfiles/getScatterMatrix/libFuzzer_getScatterMatrix/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_II_.qs";
  qs::c_qsave(II_,II__t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "II_ values: "<< II_ << std::endl;
  NumericMatrix X_  = RcppDeepState_NumericMatrix();
  std::string X__t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/kcpRS/inst/testfiles/getScatterMatrix/libFuzzer_getScatterMatrix/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_X_.qs";
  qs::c_qsave(X_,X__t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "X_ values: "<< X_ << std::endl;
  NumericMatrix H_  = RcppDeepState_NumericMatrix();
  std::string H__t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/kcpRS/inst/testfiles/getScatterMatrix/libFuzzer_getScatterMatrix/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_H_.qs";
  qs::c_qsave(H_,H__t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "H_ values: "<< H_ << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    getScatterMatrix(II_,X_,H_);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
