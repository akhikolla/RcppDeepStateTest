#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List get_indices(NumericVector y_var, int window_size);

TEST(PAutilities_deepstate_test,get_indices_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector y_var  = RcppDeepState_NumericVector();
  std::string y_var_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PAutilities/inst/testfiles/get_indices/libFuzzer_get_indices/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_y_var.qs";
  qs::c_qsave(y_var,y_var_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y_var values: "<< y_var << std::endl;
  IntegerVector window_size(1);
  window_size[0]  = RcppDeepState_int();
  std::string window_size_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PAutilities/inst/testfiles/get_indices/libFuzzer_get_indices/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_window_size.qs";
  qs::c_qsave(window_size,window_size_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "window_size values: "<< window_size << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    get_indices(y_var,window_size[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
