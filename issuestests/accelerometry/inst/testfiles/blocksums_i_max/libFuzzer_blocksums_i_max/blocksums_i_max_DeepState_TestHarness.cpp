#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector blocksums_i_max(IntegerVector x, int window);

TEST(accelerometry_deepstate_test,blocksums_i_max_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector x  = RcppDeepState_IntegerVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/accelerometry/inst/testfiles/blocksums_i_max/libFuzzer_blocksums_i_max/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  IntegerVector window(1);
  window[0]  = RcppDeepState_int();
  std::string window_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/accelerometry/inst/testfiles/blocksums_i_max/libFuzzer_blocksums_i_max/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_window.qs";
  qs::c_qsave(window,window_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "window values: "<< window << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    blocksums_i_max(x,window[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
