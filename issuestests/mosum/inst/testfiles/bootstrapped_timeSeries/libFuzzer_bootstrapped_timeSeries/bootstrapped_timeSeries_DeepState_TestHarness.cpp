#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector bootstrapped_timeSeries(IntegerVector cpts, NumericVector x);

TEST(mosum_deepstate_test,bootstrapped_timeSeries_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector cpts  = RcppDeepState_IntegerVector();
  std::string cpts_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mosum/inst/testfiles/bootstrapped_timeSeries/libFuzzer_bootstrapped_timeSeries/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_cpts.qs";
  qs::c_qsave(cpts,cpts_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "cpts values: "<< cpts << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mosum/inst/testfiles/bootstrapped_timeSeries/libFuzzer_bootstrapped_timeSeries/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    bootstrapped_timeSeries(cpts,x);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
