#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericMatrix threshold_multilevel(Rcpp::NumericMatrix im, Rcpp::NumericVector thresvals);

TEST(imagerExtra_deepstate_test,threshold_multilevel_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix im  = RcppDeepState_NumericMatrix();
  qs::c_qsave(im,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/threshold_multilevel/inputs/im.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "im values: "<< im << std::endl;
  NumericVector thresvals  = RcppDeepState_NumericVector();
  qs::c_qsave(thresvals,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/threshold_multilevel/inputs/thresvals.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "thresvals values: "<< thresvals << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    threshold_multilevel(im,thresvals);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
