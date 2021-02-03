#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector gamma_mean(IntegerVector outgamma, int start);

TEST(icensmis_deepstate_test,gamma_mean_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector outgamma  = RcppDeepState_IntegerVector();
  std::string outgamma_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icensmis/inst/testfiles/gamma_mean/libFuzzer_gamma_mean/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_outgamma.qs";
  qs::c_qsave(outgamma,outgamma_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "outgamma values: "<< outgamma << std::endl;
  IntegerVector start(1);
  start[0]  = RcppDeepState_int();
  std::string start_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icensmis/inst/testfiles/gamma_mean/libFuzzer_gamma_mean/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_start.qs";
  qs::c_qsave(start,start_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "start values: "<< start << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    gamma_mean(outgamma,start[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
