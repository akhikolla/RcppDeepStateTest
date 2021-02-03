#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector xROCVect(NumericVector zeta, double lambdaP);

TEST(RJafroc_deepstate_test,xROCVect_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector zeta  = RcppDeepState_NumericVector();
  std::string zeta_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/xROCVect/AFL_xROCVect/afl_inputs/" + std::to_string(t) + "_zeta.qs";
  qs::c_qsave(zeta,zeta_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "zeta values: "<< zeta << std::endl;
  NumericVector lambdaP(1);
  lambdaP[0]  = RcppDeepState_double();
  std::string lambdaP_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/xROCVect/AFL_xROCVect/afl_inputs/" + std::to_string(t) + "_lambdaP.qs";
  qs::c_qsave(lambdaP,lambdaP_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lambdaP values: "<< lambdaP << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    xROCVect(zeta,lambdaP[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
