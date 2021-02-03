#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericVector make_prob_otsu(Rcpp::NumericVector ordered, Rcpp::NumericVector bins, int intervalnumber, int width, int height);

TEST(imagerExtra_deepstate_test,make_prob_otsu_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector ordered  = RcppDeepState_NumericVector();
  std::string ordered_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/make_prob_otsu/AFL_make_prob_otsu/afl_inputs/" + std::to_string(t) + "_ordered.qs";
  qs::c_qsave(ordered,ordered_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ordered values: "<< ordered << std::endl;
  NumericVector bins  = RcppDeepState_NumericVector();
  std::string bins_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/make_prob_otsu/AFL_make_prob_otsu/afl_inputs/" + std::to_string(t) + "_bins.qs";
  qs::c_qsave(bins,bins_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "bins values: "<< bins << std::endl;
  IntegerVector intervalnumber(1);
  intervalnumber[0]  = RcppDeepState_int();
  std::string intervalnumber_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/make_prob_otsu/AFL_make_prob_otsu/afl_inputs/" + std::to_string(t) + "_intervalnumber.qs";
  qs::c_qsave(intervalnumber,intervalnumber_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "intervalnumber values: "<< intervalnumber << std::endl;
  IntegerVector width(1);
  width[0]  = RcppDeepState_int();
  std::string width_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/make_prob_otsu/AFL_make_prob_otsu/afl_inputs/" + std::to_string(t) + "_width.qs";
  qs::c_qsave(width,width_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "width values: "<< width << std::endl;
  IntegerVector height(1);
  height[0]  = RcppDeepState_int();
  std::string height_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/make_prob_otsu/AFL_make_prob_otsu/afl_inputs/" + std::to_string(t) + "_height.qs";
  qs::c_qsave(height,height_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "height values: "<< height << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    make_prob_otsu(ordered,bins,intervalnumber[0],width[0],height[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
