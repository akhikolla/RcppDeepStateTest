#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector mdd_hl_indices(NumericVector highs, NumericVector lows);

TEST(stocks_deepstate_test,mdd_hl_indices_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector highs  = RcppDeepState_NumericVector();
  std::string highs_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/stocks/inst/testfiles/mdd_hl_indices/libFuzzer_mdd_hl_indices/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_highs.qs";
  qs::c_qsave(highs,highs_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "highs values: "<< highs << std::endl;
  NumericVector lows  = RcppDeepState_NumericVector();
  std::string lows_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/stocks/inst/testfiles/mdd_hl_indices/libFuzzer_mdd_hl_indices/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_lows.qs";
  qs::c_qsave(lows,lows_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lows values: "<< lows << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    mdd_hl_indices(highs,lows);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
