#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

IntegerMatrix kruskal(NumericMatrix W);

TEST(BNSL_deepstate_test,kruskal_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix W  = RcppDeepState_NumericMatrix();
  std::string W_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BNSL/inst/testfiles/kruskal/AFL_kruskal/afl_inputs/" + std::to_string(t) + "_W.qs";
  qs::c_qsave(W,W_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "W values: "<< W << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    kruskal(W);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
