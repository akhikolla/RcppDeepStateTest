#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double xROC(double zeta, double lambdaP);

TEST(RJafroc_deepstate_test,xROC_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector zeta(1);
  zeta[0]  = RcppDeepState_double();
  qs::c_qsave(zeta,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/xROC/inputs/zeta.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "zeta values: "<< zeta << std::endl;
  NumericVector lambdaP(1);
  lambdaP[0]  = RcppDeepState_double();
  qs::c_qsave(lambdaP,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/xROC/inputs/lambdaP.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lambdaP values: "<< lambdaP << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    xROC(zeta[0],lambdaP[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
