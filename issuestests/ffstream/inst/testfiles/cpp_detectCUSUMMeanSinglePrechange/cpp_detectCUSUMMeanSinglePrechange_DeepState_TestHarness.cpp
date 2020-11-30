#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::List cpp_detectCUSUMMeanSinglePrechange(Rcpp::NumericVector x, double k, double h, double prechangeMean, double prechangeSigma);

TEST(ffstream_deepstate_test,cpp_detectCUSUMMeanSinglePrechange_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  qs::c_qsave(x,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ffstream/inst/testfiles/cpp_detectCUSUMMeanSinglePrechange/inputs/x.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector k(1);
  k[0]  = RcppDeepState_double();
  qs::c_qsave(k,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ffstream/inst/testfiles/cpp_detectCUSUMMeanSinglePrechange/inputs/k.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "k values: "<< k << std::endl;
  NumericVector h(1);
  h[0]  = RcppDeepState_double();
  qs::c_qsave(h,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ffstream/inst/testfiles/cpp_detectCUSUMMeanSinglePrechange/inputs/h.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "h values: "<< h << std::endl;
  NumericVector prechangeMean(1);
  prechangeMean[0]  = RcppDeepState_double();
  qs::c_qsave(prechangeMean,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ffstream/inst/testfiles/cpp_detectCUSUMMeanSinglePrechange/inputs/prechangeMean.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "prechangeMean values: "<< prechangeMean << std::endl;
  NumericVector prechangeSigma(1);
  prechangeSigma[0]  = RcppDeepState_double();
  qs::c_qsave(prechangeSigma,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ffstream/inst/testfiles/cpp_detectCUSUMMeanSinglePrechange/inputs/prechangeSigma.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "prechangeSigma values: "<< prechangeSigma << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    cpp_detectCUSUMMeanSinglePrechange(x,k[0],h[0],prechangeMean[0],prechangeSigma[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
