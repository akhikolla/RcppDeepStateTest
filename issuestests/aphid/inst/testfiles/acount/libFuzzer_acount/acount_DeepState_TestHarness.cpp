#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

IntegerVector acount(IntegerVector x, int arity);

TEST(aphid_deepstate_test,acount_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector x  = RcppDeepState_IntegerVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aphid/inst/testfiles/acount/libFuzzer_acount/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  IntegerVector arity(1);
  arity[0]  = RcppDeepState_int();
  std::string arity_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aphid/inst/testfiles/acount/libFuzzer_acount/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_arity.qs";
  qs::c_qsave(arity,arity_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "arity values: "<< arity << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    acount(x,arity[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
