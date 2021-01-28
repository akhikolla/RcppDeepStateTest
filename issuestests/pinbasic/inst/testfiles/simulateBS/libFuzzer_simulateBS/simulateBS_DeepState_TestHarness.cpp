#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix simulateBS(NumericVector param, int ndays);

TEST(pinbasic_deepstate_test,simulateBS_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector param  = RcppDeepState_NumericVector();
  std::string param_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/pinbasic/inst/testfiles/simulateBS/libFuzzer_simulateBS/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_param.qs";
  qs::c_qsave(param,param_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "param values: "<< param << std::endl;
  IntegerVector ndays(1);
  ndays[0]  = RcppDeepState_int();
  std::string ndays_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/pinbasic/inst/testfiles/simulateBS/libFuzzer_simulateBS/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_ndays.qs";
  qs::c_qsave(ndays,ndays_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ndays values: "<< ndays << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    simulateBS(param,ndays[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
