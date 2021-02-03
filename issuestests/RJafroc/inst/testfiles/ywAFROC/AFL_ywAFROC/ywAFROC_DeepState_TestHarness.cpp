#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double ywAFROC(double zeta, double mu, double nuP, NumericMatrix lesDistr, NumericMatrix lesWghtDistr);

TEST(RJafroc_deepstate_test,ywAFROC_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector zeta(1);
  zeta[0]  = RcppDeepState_double();
  std::string zeta_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/ywAFROC/AFL_ywAFROC/afl_inputs/" + std::to_string(t) + "_zeta.qs";
  qs::c_qsave(zeta,zeta_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "zeta values: "<< zeta << std::endl;
  NumericVector mu(1);
  mu[0]  = RcppDeepState_double();
  std::string mu_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/ywAFROC/AFL_ywAFROC/afl_inputs/" + std::to_string(t) + "_mu.qs";
  qs::c_qsave(mu,mu_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "mu values: "<< mu << std::endl;
  NumericVector nuP(1);
  nuP[0]  = RcppDeepState_double();
  std::string nuP_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/ywAFROC/AFL_ywAFROC/afl_inputs/" + std::to_string(t) + "_nuP.qs";
  qs::c_qsave(nuP,nuP_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nuP values: "<< nuP << std::endl;
  NumericMatrix lesDistr  = RcppDeepState_NumericMatrix();
  std::string lesDistr_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/ywAFROC/AFL_ywAFROC/afl_inputs/" + std::to_string(t) + "_lesDistr.qs";
  qs::c_qsave(lesDistr,lesDistr_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lesDistr values: "<< lesDistr << std::endl;
  NumericMatrix lesWghtDistr  = RcppDeepState_NumericMatrix();
  std::string lesWghtDistr_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/ywAFROC/AFL_ywAFROC/afl_inputs/" + std::to_string(t) + "_lesWghtDistr.qs";
  qs::c_qsave(lesWghtDistr,lesWghtDistr_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lesWghtDistr values: "<< lesWghtDistr << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    ywAFROC(zeta[0],mu[0],nuP[0],lesDistr,lesWghtDistr);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
