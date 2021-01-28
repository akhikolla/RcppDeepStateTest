#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector zero2one(NumericVector samples);

TEST(AGread_deepstate_test,zero2one_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector samples  = RcppDeepState_NumericVector();
  std::string samples_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/AGread/inst/testfiles/zero2one/libFuzzer_zero2one/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_samples.qs";
  qs::c_qsave(samples,samples_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "samples values: "<< samples << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    zero2one(samples);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
