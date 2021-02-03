#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

long Stirling2C(int n, int k);

TEST(multicool_deepstate_test,Stirling2C_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector n(1);
  n[0]  = RcppDeepState_int();
  std::string n_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/multicool/inst/testfiles/Stirling2C/AFL_Stirling2C/afl_inputs/" + std::to_string(t) + "_n.qs";
  qs::c_qsave(n,n_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n values: "<< n << std::endl;
  IntegerVector k(1);
  k[0]  = RcppDeepState_int();
  std::string k_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/multicool/inst/testfiles/Stirling2C/AFL_Stirling2C/afl_inputs/" + std::to_string(t) + "_k.qs";
  qs::c_qsave(k,k_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "k values: "<< k << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    Stirling2C(n[0],k[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
