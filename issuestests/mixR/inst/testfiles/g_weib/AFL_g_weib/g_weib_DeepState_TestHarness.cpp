#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double g_weib(double r, NumericVector n, NumericVector ex, NumericVector tx);

TEST(mixR_deepstate_test,g_weib_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector r(1);
  r[0]  = RcppDeepState_double();
  std::string r_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mixR/inst/testfiles/g_weib/AFL_g_weib/afl_inputs/" + std::to_string(t) + "_r.qs";
  qs::c_qsave(r,r_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "r values: "<< r << std::endl;
  NumericVector n  = RcppDeepState_NumericVector();
  std::string n_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mixR/inst/testfiles/g_weib/AFL_g_weib/afl_inputs/" + std::to_string(t) + "_n.qs";
  qs::c_qsave(n,n_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n values: "<< n << std::endl;
  NumericVector ex  = RcppDeepState_NumericVector();
  std::string ex_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mixR/inst/testfiles/g_weib/AFL_g_weib/afl_inputs/" + std::to_string(t) + "_ex.qs";
  qs::c_qsave(ex,ex_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ex values: "<< ex << std::endl;
  NumericVector tx  = RcppDeepState_NumericVector();
  std::string tx_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mixR/inst/testfiles/g_weib/AFL_g_weib/afl_inputs/" + std::to_string(t) + "_tx.qs";
  qs::c_qsave(tx,tx_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tx values: "<< tx << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    g_weib(r[0],n,ex,tx);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
