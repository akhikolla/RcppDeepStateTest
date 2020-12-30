#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double CBMNLLInner(double mu, double alpha, NumericVector zetas, NumericVector fi, NumericVector ti);

TEST(RJafroc_deepstate_test,CBMNLLInner_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector mu(1);
  mu[0]  = RcppDeepState_double();
  qs::c_qsave(mu,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/CBMNLLInner/inputs/mu.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "mu values: "<< mu << std::endl;
  NumericVector alpha(1);
  alpha[0]  = RcppDeepState_double();
  qs::c_qsave(alpha,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/CBMNLLInner/inputs/alpha.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "alpha values: "<< alpha << std::endl;
  NumericVector zetas  = RcppDeepState_NumericVector();
  qs::c_qsave(zetas,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/CBMNLLInner/inputs/zetas.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "zetas values: "<< zetas << std::endl;
  NumericVector fi  = RcppDeepState_NumericVector();
  qs::c_qsave(fi,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/CBMNLLInner/inputs/fi.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "fi values: "<< fi << std::endl;
  NumericVector ti  = RcppDeepState_NumericVector();
  qs::c_qsave(ti,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/CBMNLLInner/inputs/ti.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ti values: "<< ti << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    CBMNLLInner(mu[0],alpha[0],zetas,fi,ti);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
