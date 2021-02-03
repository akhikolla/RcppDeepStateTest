#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double const_univm(double k);

TEST(BAMBI_deepstate_test,const_univm_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector k(1);
  k[0]  = RcppDeepState_double();
  std::string k_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/const_univm/AFL_const_univm/afl_inputs/" + std::to_string(t) + "_k.qs";
  qs::c_qsave(k,k_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "k values: "<< k << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    const_univm(k[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
