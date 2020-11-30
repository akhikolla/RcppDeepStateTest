#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::List cpp_detectFFFMeanSinglePrechange(Rcpp::NumericVector x, double lambda, double alpha, double prechangeMean, double prechangeSigma);

TEST(ffstream_deepstate_test,cpp_detectFFFMeanSinglePrechange_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  qs::c_qsave(x,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ffstream/inst/testfiles/cpp_detectFFFMeanSinglePrechange/inputs/x.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector lambda(1);
  lambda[0]  = RcppDeepState_double();
  qs::c_qsave(lambda,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ffstream/inst/testfiles/cpp_detectFFFMeanSinglePrechange/inputs/lambda.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lambda values: "<< lambda << std::endl;
  NumericVector alpha(1);
  alpha[0]  = RcppDeepState_double();
  qs::c_qsave(alpha,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ffstream/inst/testfiles/cpp_detectFFFMeanSinglePrechange/inputs/alpha.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "alpha values: "<< alpha << std::endl;
  NumericVector prechangeMean(1);
  prechangeMean[0]  = RcppDeepState_double();
  qs::c_qsave(prechangeMean,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ffstream/inst/testfiles/cpp_detectFFFMeanSinglePrechange/inputs/prechangeMean.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "prechangeMean values: "<< prechangeMean << std::endl;
  NumericVector prechangeSigma(1);
  prechangeSigma[0]  = RcppDeepState_double();
  qs::c_qsave(prechangeSigma,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ffstream/inst/testfiles/cpp_detectFFFMeanSinglePrechange/inputs/prechangeSigma.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "prechangeSigma values: "<< prechangeSigma << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    cpp_detectFFFMeanSinglePrechange(x,lambda[0],alpha[0],prechangeMean[0],prechangeSigma[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
