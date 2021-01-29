#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List trim_ts(NumericVector x, NumericVector xlim, NumericVector extra);

TEST(oce_deepstate_test,trim_ts_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/trim_ts/libFuzzer_trim_ts/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector xlim  = RcppDeepState_NumericVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/trim_ts/libFuzzer_trim_ts/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_x.qs";
  std::string xlim_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/trim_ts/libFuzzer_trim_ts/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_xlim.qs";
  qs::c_qsave(xlim,xlim_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "xlim values: "<< xlim << std::endl;
  NumericVector extra  = RcppDeepState_NumericVector();
  std::string extra_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/trim_ts/libFuzzer_trim_ts/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_extra.qs";
  qs::c_qsave(extra,extra_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "extra values: "<< extra << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    trim_ts(x,xlim,extra);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
