#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double RsmInner(double mu, double lambdaP, double nuP, NumericMatrix lesDistr, NumericVector zeta, NumericVector fb, NumericVector tb);

TEST(RJafroc_deepstate_test,RsmInner_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector mu(1);
  mu[0]  = RcppDeepState_double();
  qs::c_qsave(mu,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/RsmInner/inputs/mu.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "mu values: "<< mu << std::endl;
  NumericVector lambdaP(1);
  lambdaP[0]  = RcppDeepState_double();
  qs::c_qsave(lambdaP,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/RsmInner/inputs/lambdaP.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lambdaP values: "<< lambdaP << std::endl;
  NumericVector nuP(1);
  nuP[0]  = RcppDeepState_double();
  qs::c_qsave(nuP,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/RsmInner/inputs/nuP.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nuP values: "<< nuP << std::endl;
  NumericMatrix lesDistr  = RcppDeepState_NumericMatrix();
  qs::c_qsave(lesDistr,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/RsmInner/inputs/lesDistr.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lesDistr values: "<< lesDistr << std::endl;
  NumericVector zeta  = RcppDeepState_NumericVector();
  qs::c_qsave(zeta,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/RsmInner/inputs/zeta.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "zeta values: "<< zeta << std::endl;
  NumericVector fb  = RcppDeepState_NumericVector();
  qs::c_qsave(fb,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/RsmInner/inputs/fb.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "fb values: "<< fb << std::endl;
  NumericVector tb  = RcppDeepState_NumericVector();
  qs::c_qsave(tb,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/RsmInner/inputs/tb.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tb values: "<< tb << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    RsmInner(mu[0],lambdaP[0],nuP[0],lesDistr,zeta,fb,tb);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
