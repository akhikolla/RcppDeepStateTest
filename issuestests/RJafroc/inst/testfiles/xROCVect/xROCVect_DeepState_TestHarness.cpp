#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector xROCVect(NumericVector zeta, double lambdaP);

TEST(RJafroc_deepstate_test,xROCVect_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector zeta  = RcppDeepState_NumericVector();
  qs::c_qsave(zeta,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/xROCVect/inputs/zeta.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "zeta values: "<< zeta << std::endl;
  NumericVector lambdaP(1);
  lambdaP[0]  = RcppDeepState_double();
  qs::c_qsave(lambdaP,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/xROCVect/inputs/lambdaP.qs",
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
