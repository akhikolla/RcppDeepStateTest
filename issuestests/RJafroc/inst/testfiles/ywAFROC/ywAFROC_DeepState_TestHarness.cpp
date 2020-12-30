#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double ywAFROC(double zeta, double mu, double nuP, NumericMatrix lesDistr, NumericMatrix lesWghtDistr);

TEST(RJafroc_deepstate_test,ywAFROC_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector zeta(1);
  zeta[0]  = RcppDeepState_double();
  qs::c_qsave(zeta,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/ywAFROC/inputs/zeta.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "zeta values: "<< zeta << std::endl;
  NumericVector mu(1);
  mu[0]  = RcppDeepState_double();
  qs::c_qsave(mu,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/ywAFROC/inputs/mu.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "mu values: "<< mu << std::endl;
  NumericVector nuP(1);
  nuP[0]  = RcppDeepState_double();
  qs::c_qsave(nuP,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/ywAFROC/inputs/nuP.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nuP values: "<< nuP << std::endl;
  NumericMatrix lesDistr  = RcppDeepState_NumericMatrix();
  qs::c_qsave(lesDistr,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/ywAFROC/inputs/lesDistr.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lesDistr values: "<< lesDistr << std::endl;
  NumericMatrix lesWghtDistr  = RcppDeepState_NumericMatrix();
  qs::c_qsave(lesWghtDistr,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/ywAFROC/inputs/lesWghtDistr.qs",
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
