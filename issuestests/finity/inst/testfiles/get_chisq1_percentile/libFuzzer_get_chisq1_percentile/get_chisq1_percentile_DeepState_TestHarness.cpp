#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double get_chisq1_percentile(double value);

TEST(finity_deepstate_test,get_chisq1_percentile_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector value(1);
  value[0]  = RcppDeepState_double();
  std::string value_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/finity/inst/testfiles/get_chisq1_percentile/libFuzzer_get_chisq1_percentile/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_value.qs";
  qs::c_qsave(value,value_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "value values: "<< value << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    get_chisq1_percentile(value[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
