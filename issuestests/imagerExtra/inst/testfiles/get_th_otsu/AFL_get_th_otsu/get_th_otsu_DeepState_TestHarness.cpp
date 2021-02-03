#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double get_th_otsu(Rcpp::NumericVector prob_otsu, Rcpp::NumericVector bins);

TEST(imagerExtra_deepstate_test,get_th_otsu_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector prob_otsu  = RcppDeepState_NumericVector();
  std::string prob_otsu_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/get_th_otsu/AFL_get_th_otsu/afl_inputs/" + std::to_string(t) + "_prob_otsu.qs";
  qs::c_qsave(prob_otsu,prob_otsu_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "prob_otsu values: "<< prob_otsu << std::endl;
  NumericVector bins  = RcppDeepState_NumericVector();
  std::string bins_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/get_th_otsu/AFL_get_th_otsu/afl_inputs/" + std::to_string(t) + "_bins.qs";
  qs::c_qsave(bins,bins_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "bins values: "<< bins << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    get_th_otsu(prob_otsu,bins);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
