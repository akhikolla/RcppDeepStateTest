#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector yROCVect(NumericVector zeta, double mu, double lambdaP, double nuP, NumericMatrix lesDistr);

TEST(RJafroc_deepstate_test,yROCVect_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector zeta  = RcppDeepState_NumericVector();
  std::string zeta_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/yROCVect/AFL_yROCVect/afl_inputs/" + std::to_string(t) + "_zeta.qs";
  qs::c_qsave(zeta,zeta_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "zeta values: "<< zeta << std::endl;
  NumericVector mu(1);
  mu[0]  = RcppDeepState_double();
  std::string mu_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/yROCVect/AFL_yROCVect/afl_inputs/" + std::to_string(t) + "_mu.qs";
  qs::c_qsave(mu,mu_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "mu values: "<< mu << std::endl;
  NumericVector lambdaP(1);
  lambdaP[0]  = RcppDeepState_double();
  std::string lambdaP_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/yROCVect/AFL_yROCVect/afl_inputs/" + std::to_string(t) + "_lambdaP.qs";
  qs::c_qsave(lambdaP,lambdaP_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lambdaP values: "<< lambdaP << std::endl;
  NumericVector nuP(1);
  nuP[0]  = RcppDeepState_double();
  std::string nuP_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/yROCVect/AFL_yROCVect/afl_inputs/" + std::to_string(t) + "_nuP.qs";
  qs::c_qsave(nuP,nuP_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nuP values: "<< nuP << std::endl;
  NumericMatrix lesDistr  = RcppDeepState_NumericMatrix();
  std::string lesDistr_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/yROCVect/AFL_yROCVect/afl_inputs/" + std::to_string(t) + "_lesDistr.qs";
  qs::c_qsave(lesDistr,lesDistr_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lesDistr values: "<< lesDistr << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    yROCVect(zeta,mu[0],lambdaP[0],nuP[0],lesDistr);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
