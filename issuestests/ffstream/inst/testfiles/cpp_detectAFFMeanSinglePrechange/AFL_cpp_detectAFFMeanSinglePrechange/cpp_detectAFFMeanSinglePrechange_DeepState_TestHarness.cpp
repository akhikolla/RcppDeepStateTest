#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::List cpp_detectAFFMeanSinglePrechange(Rcpp::NumericVector x, double alpha, double eta, double prechangeMean, double prechangeSigma);

TEST(ffstream_deepstate_test,cpp_detectAFFMeanSinglePrechange_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ffstream/inst/testfiles/cpp_detectAFFMeanSinglePrechange/AFL_cpp_detectAFFMeanSinglePrechange/afl_inputs/" + std::to_string(t) + "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector alpha(1);
  alpha[0]  = RcppDeepState_double();
  std::string alpha_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ffstream/inst/testfiles/cpp_detectAFFMeanSinglePrechange/AFL_cpp_detectAFFMeanSinglePrechange/afl_inputs/" + std::to_string(t) + "_alpha.qs";
  qs::c_qsave(alpha,alpha_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "alpha values: "<< alpha << std::endl;
  NumericVector eta(1);
  eta[0]  = RcppDeepState_double();
  std::string eta_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ffstream/inst/testfiles/cpp_detectAFFMeanSinglePrechange/AFL_cpp_detectAFFMeanSinglePrechange/afl_inputs/" + std::to_string(t) + "_eta.qs";
  qs::c_qsave(eta,eta_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "eta values: "<< eta << std::endl;
  NumericVector prechangeMean(1);
  prechangeMean[0]  = RcppDeepState_double();
  std::string prechangeMean_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ffstream/inst/testfiles/cpp_detectAFFMeanSinglePrechange/AFL_cpp_detectAFFMeanSinglePrechange/afl_inputs/" + std::to_string(t) + "_prechangeMean.qs";
  qs::c_qsave(prechangeMean,prechangeMean_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "prechangeMean values: "<< prechangeMean << std::endl;
  NumericVector prechangeSigma(1);
  prechangeSigma[0]  = RcppDeepState_double();
  std::string prechangeSigma_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ffstream/inst/testfiles/cpp_detectAFFMeanSinglePrechange/AFL_cpp_detectAFFMeanSinglePrechange/afl_inputs/" + std::to_string(t) + "_prechangeSigma.qs";
  qs::c_qsave(prechangeSigma,prechangeSigma_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "prechangeSigma values: "<< prechangeSigma << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    cpp_detectAFFMeanSinglePrechange(x,alpha[0],eta[0],prechangeMean[0],prechangeSigma[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
