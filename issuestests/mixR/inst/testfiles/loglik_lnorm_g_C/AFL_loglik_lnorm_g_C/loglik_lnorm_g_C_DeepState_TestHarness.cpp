#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double loglik_lnorm_g_C(NumericMatrix data, NumericVector pi, NumericVector mulog, NumericVector sdlog);

TEST(mixR_deepstate_test,loglik_lnorm_g_C_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix data  = RcppDeepState_NumericMatrix();
  std::string data_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mixR/inst/testfiles/loglik_lnorm_g_C/AFL_loglik_lnorm_g_C/afl_inputs/" + std::to_string(t) + "_data.qs";
  qs::c_qsave(data,data_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "data values: "<< data << std::endl;
  NumericVector pi  = RcppDeepState_NumericVector();
  std::string pi_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mixR/inst/testfiles/loglik_lnorm_g_C/AFL_loglik_lnorm_g_C/afl_inputs/" + std::to_string(t) + "_pi.qs";
  qs::c_qsave(pi,pi_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pi values: "<< pi << std::endl;
  NumericVector mulog  = RcppDeepState_NumericVector();
  std::string mulog_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mixR/inst/testfiles/loglik_lnorm_g_C/AFL_loglik_lnorm_g_C/afl_inputs/" + std::to_string(t) + "_mulog.qs";
  qs::c_qsave(mulog,mulog_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "mulog values: "<< mulog << std::endl;
  NumericVector sdlog  = RcppDeepState_NumericVector();
  std::string sdlog_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mixR/inst/testfiles/loglik_lnorm_g_C/AFL_loglik_lnorm_g_C/afl_inputs/" + std::to_string(t) + "_sdlog.qs";
  qs::c_qsave(sdlog,sdlog_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "sdlog values: "<< sdlog << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    loglik_lnorm_g_C(data,pi,mulog,sdlog);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
