#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix lr2vlr(NumericMatrix lr);

TEST(propr_deepstate_test,lr2vlr_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix lr  = RcppDeepState_NumericMatrix();
  std::string lr_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/propr/inst/testfiles/lr2vlr/AFL_lr2vlr/afl_inputs/" + std::to_string(t) + "_lr.qs";
  qs::c_qsave(lr,lr_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lr values: "<< lr << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    lr2vlr(lr);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
