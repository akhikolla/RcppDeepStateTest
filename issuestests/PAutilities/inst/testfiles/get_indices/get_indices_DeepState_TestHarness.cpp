#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List get_indices(NumericVector y_var, int window_size);

TEST(PAutilities_deepstate_test,get_indices_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector y_var  = RcppDeepState_NumericVector();
  qs::c_qsave(y_var,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PAutilities/inst/testfiles/get_indices/inputs/y_var.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y_var values: "<< y_var << std::endl;
  IntegerVector window_size(1);
  window_size[0]  = RcppDeepState_int();
  qs::c_qsave(window_size,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PAutilities/inst/testfiles/get_indices/inputs/window_size.qs",
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
