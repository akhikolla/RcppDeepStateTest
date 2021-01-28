#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix UserSimil(NumericMatrix x, int damp);

TEST(rrecsys_deepstate_test,UserSimil_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix x  = RcppDeepState_NumericMatrix();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rrecsys/inst/testfiles/UserSimil/libFuzzer_UserSimil/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  IntegerVector damp(1);
  damp[0]  = RcppDeepState_int();
  std::string damp_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rrecsys/inst/testfiles/UserSimil/libFuzzer_UserSimil/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_damp.qs";
  qs::c_qsave(damp,damp_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "damp values: "<< damp << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    UserSimil(x,damp[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
