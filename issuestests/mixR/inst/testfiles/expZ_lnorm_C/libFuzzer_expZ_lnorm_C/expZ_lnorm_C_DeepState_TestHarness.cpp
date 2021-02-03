#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix expZ_lnorm_C(NumericVector x, NumericVector pi, NumericVector mulog, NumericVector sdlog);

TEST(mixR_deepstate_test,expZ_lnorm_C_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mixR/inst/testfiles/expZ_lnorm_C/libFuzzer_expZ_lnorm_C/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector pi  = RcppDeepState_NumericVector();
  std::string pi_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mixR/inst/testfiles/expZ_lnorm_C/libFuzzer_expZ_lnorm_C/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_pi.qs";
  qs::c_qsave(pi,pi_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pi values: "<< pi << std::endl;
  NumericVector mulog  = RcppDeepState_NumericVector();
  std::string mulog_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mixR/inst/testfiles/expZ_lnorm_C/libFuzzer_expZ_lnorm_C/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_mulog.qs";
  qs::c_qsave(mulog,mulog_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "mulog values: "<< mulog << std::endl;
  NumericVector sdlog  = RcppDeepState_NumericVector();
  std::string sdlog_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mixR/inst/testfiles/expZ_lnorm_C/libFuzzer_expZ_lnorm_C/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_sdlog.qs";
  qs::c_qsave(sdlog,sdlog_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "sdlog values: "<< sdlog << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    expZ_lnorm_C(x,pi,mulog,sdlog);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
