#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector durbin(NumericVector r, int N);

TEST(FastGP_deepstate_test,durbin_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector r  = RcppDeepState_NumericVector();
  std::string r_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/FastGP/inst/testfiles/durbin/AFL_durbin/afl_inputs/" + std::to_string(t) + "_r.qs";
  qs::c_qsave(r,r_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "r values: "<< r << std::endl;
  IntegerVector N(1);
  N[0]  = RcppDeepState_int();
  std::string N_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/FastGP/inst/testfiles/durbin/AFL_durbin/afl_inputs/" + std::to_string(t) + "_N.qs";
  qs::c_qsave(N,N_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "N values: "<< N << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    durbin(r,N[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
