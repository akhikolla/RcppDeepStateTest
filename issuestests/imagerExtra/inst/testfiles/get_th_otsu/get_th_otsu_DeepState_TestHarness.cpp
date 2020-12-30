#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double get_th_otsu(Rcpp::NumericVector prob_otsu, Rcpp::NumericVector bins);

TEST(imagerExtra_deepstate_test,get_th_otsu_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector prob_otsu  = RcppDeepState_NumericVector();
  qs::c_qsave(prob_otsu,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/get_th_otsu/inputs/prob_otsu.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "prob_otsu values: "<< prob_otsu << std::endl;
  NumericVector bins  = RcppDeepState_NumericVector();
  qs::c_qsave(bins,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/get_th_otsu/inputs/bins.qs",
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
