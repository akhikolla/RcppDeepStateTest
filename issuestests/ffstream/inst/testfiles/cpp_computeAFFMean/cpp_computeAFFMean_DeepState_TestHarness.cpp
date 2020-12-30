#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double cpp_computeAFFMean(Rcpp::NumericVector x, double eta);

TEST(ffstream_deepstate_test,cpp_computeAFFMean_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  qs::c_qsave(x,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ffstream/inst/testfiles/cpp_computeAFFMean/inputs/x.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector eta(1);
  eta[0]  = RcppDeepState_double();
  qs::c_qsave(eta,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ffstream/inst/testfiles/cpp_computeAFFMean/inputs/eta.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "eta values: "<< eta << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    cpp_computeAFFMean(x,eta[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
