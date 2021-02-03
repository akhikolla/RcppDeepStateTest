#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericMatrix threshold_multilevel(Rcpp::NumericMatrix im, Rcpp::NumericVector thresvals);

TEST(imagerExtra_deepstate_test,threshold_multilevel_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix im  = RcppDeepState_NumericMatrix();
  std::string im_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/threshold_multilevel/libFuzzer_threshold_multilevel/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_im.qs";
  qs::c_qsave(im,im_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "im values: "<< im << std::endl;
  NumericVector thresvals  = RcppDeepState_NumericVector();
  std::string thresvals_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/threshold_multilevel/libFuzzer_threshold_multilevel/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_thresvals.qs";
  qs::c_qsave(thresvals,thresvals_t,
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
