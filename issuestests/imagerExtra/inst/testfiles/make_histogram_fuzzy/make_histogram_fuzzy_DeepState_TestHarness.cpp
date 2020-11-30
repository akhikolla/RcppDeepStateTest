#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericVector make_histogram_fuzzy(Rcpp::NumericVector ordered, Rcpp::NumericVector interval);

TEST(imagerExtra_deepstate_test,make_histogram_fuzzy_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector ordered  = RcppDeepState_NumericVector();
  qs::c_qsave(ordered,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/make_histogram_fuzzy/inputs/ordered.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ordered values: "<< ordered << std::endl;
  NumericVector interval  = RcppDeepState_NumericVector();
  qs::c_qsave(interval,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/make_histogram_fuzzy/inputs/interval.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "interval values: "<< interval << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    make_histogram_fuzzy(ordered,interval);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
