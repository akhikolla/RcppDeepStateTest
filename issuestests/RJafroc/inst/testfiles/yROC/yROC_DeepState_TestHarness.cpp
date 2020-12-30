#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double yROC(double zeta, double mu, double lambdaP, double nuP, NumericMatrix lesDistr);

TEST(RJafroc_deepstate_test,yROC_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector zeta(1);
  zeta[0]  = RcppDeepState_double();
  qs::c_qsave(zeta,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/yROC/inputs/zeta.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "zeta values: "<< zeta << std::endl;
  NumericVector mu(1);
  mu[0]  = RcppDeepState_double();
  qs::c_qsave(mu,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/yROC/inputs/mu.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "mu values: "<< mu << std::endl;
  NumericVector lambdaP(1);
  lambdaP[0]  = RcppDeepState_double();
  qs::c_qsave(lambdaP,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/yROC/inputs/lambdaP.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lambdaP values: "<< lambdaP << std::endl;
  NumericVector nuP(1);
  nuP[0]  = RcppDeepState_double();
  qs::c_qsave(nuP,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/yROC/inputs/nuP.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nuP values: "<< nuP << std::endl;
  NumericMatrix lesDistr  = RcppDeepState_NumericMatrix();
  qs::c_qsave(lesDistr,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/yROC/inputs/lesDistr.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lesDistr values: "<< lesDistr << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    yROC(zeta[0],mu[0],lambdaP[0],nuP[0],lesDistr);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
