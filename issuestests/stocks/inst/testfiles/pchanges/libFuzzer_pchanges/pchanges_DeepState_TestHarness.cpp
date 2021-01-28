#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector pchanges(NumericVector x, int lag);

TEST(stocks_deepstate_test,pchanges_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/stocks/inst/testfiles/pchanges/libFuzzer_pchanges/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  IntegerVector lag(1);
  lag[0]  = RcppDeepState_int();
  std::string lag_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/stocks/inst/testfiles/pchanges/libFuzzer_pchanges/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_lag.qs";
  qs::c_qsave(lag,lag_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lag values: "<< lag << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    pchanges(x,lag[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
