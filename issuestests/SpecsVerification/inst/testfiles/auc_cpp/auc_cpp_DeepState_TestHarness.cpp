#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector auc_cpp(NumericVector fcst, NumericVector obs);

TEST(SpecsVerification_deepstate_test,auc_cpp_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector fcst  = RcppDeepState_NumericVector();
  qs::c_qsave(fcst,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/SpecsVerification/inst/testfiles/auc_cpp/inputs/fcst.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "fcst values: "<< fcst << std::endl;
  NumericVector obs  = RcppDeepState_NumericVector();
  qs::c_qsave(obs,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/SpecsVerification/inst/testfiles/auc_cpp/inputs/obs.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "obs values: "<< obs << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    auc_cpp(fcst,obs);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
