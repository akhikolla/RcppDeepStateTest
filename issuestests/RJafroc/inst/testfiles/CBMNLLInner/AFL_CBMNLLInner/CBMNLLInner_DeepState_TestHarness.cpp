#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double CBMNLLInner(double mu, double alpha, NumericVector zetas, NumericVector fi, NumericVector ti);

TEST(RJafroc_deepstate_test,CBMNLLInner_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector mu(1);
  mu[0]  = RcppDeepState_double();
  std::string mu_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/CBMNLLInner/AFL_CBMNLLInner/afl_inputs/" + std::to_string(t) + "_mu.qs";
  qs::c_qsave(mu,mu_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "mu values: "<< mu << std::endl;
  NumericVector alpha(1);
  alpha[0]  = RcppDeepState_double();
  std::string alpha_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/CBMNLLInner/AFL_CBMNLLInner/afl_inputs/" + std::to_string(t) + "_alpha.qs";
  qs::c_qsave(alpha,alpha_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "alpha values: "<< alpha << std::endl;
  NumericVector zetas  = RcppDeepState_NumericVector();
  std::string zetas_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/CBMNLLInner/AFL_CBMNLLInner/afl_inputs/" + std::to_string(t) + "_zetas.qs";
  qs::c_qsave(zetas,zetas_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "zetas values: "<< zetas << std::endl;
  NumericVector fi  = RcppDeepState_NumericVector();
  std::string fi_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/CBMNLLInner/AFL_CBMNLLInner/afl_inputs/" + std::to_string(t) + "_fi.qs";
  qs::c_qsave(fi,fi_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "fi values: "<< fi << std::endl;
  NumericVector ti  = RcppDeepState_NumericVector();
  std::string ti_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/CBMNLLInner/AFL_CBMNLLInner/afl_inputs/" + std::to_string(t) + "_ti.qs";
  qs::c_qsave(ti,ti_t,
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
