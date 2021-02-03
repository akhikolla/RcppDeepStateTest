#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector CapplyB(NumericVector us, NumericMatrix X, NumericVector mu);

TEST(robFitConGraph_deepstate_test,CapplyB_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector us  = RcppDeepState_NumericVector();
  std::string us_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/robFitConGraph/inst/testfiles/CapplyB/AFL_CapplyB/afl_inputs/" + std::to_string(t) + "_us.qs";
  qs::c_qsave(us,us_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "us values: "<< us << std::endl;
  NumericMatrix X  = RcppDeepState_NumericMatrix();
  std::string X_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/robFitConGraph/inst/testfiles/CapplyB/AFL_CapplyB/afl_inputs/" + std::to_string(t) + "_X.qs";
  qs::c_qsave(X,X_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "X values: "<< X << std::endl;
  NumericVector mu  = RcppDeepState_NumericVector();
  std::string mu_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/robFitConGraph/inst/testfiles/CapplyB/AFL_CapplyB/afl_inputs/" + std::to_string(t) + "_mu.qs";
  qs::c_qsave(mu,mu_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "mu values: "<< mu << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    CapplyB(us,X,mu);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
