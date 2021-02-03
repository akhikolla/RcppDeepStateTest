#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix rhoRcpp(NumericMatrix X, NumericMatrix lr, const int ivar);

TEST(propr_deepstate_test,rhoRcpp_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix X  = RcppDeepState_NumericMatrix();
  std::string X_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/propr/inst/testfiles/rhoRcpp/AFL_rhoRcpp/afl_inputs/" + std::to_string(t) + "_X.qs";
  qs::c_qsave(X,X_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "X values: "<< X << std::endl;
  NumericMatrix lr  = RcppDeepState_NumericMatrix();
  std::string lr_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/propr/inst/testfiles/rhoRcpp/AFL_rhoRcpp/afl_inputs/" + std::to_string(t) + "_lr.qs";
  qs::c_qsave(lr,lr_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lr values: "<< lr << std::endl;
  IntegerVector ivar(1);
  ivar[0]  = RcppDeepState_int();
  std::string ivar_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/propr/inst/testfiles/rhoRcpp/AFL_rhoRcpp/afl_inputs/" + std::to_string(t) + "_ivar.qs";
  qs::c_qsave(ivar,ivar_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ivar values: "<< ivar << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    rhoRcpp(X,lr,ivar[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
