#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericMatrix IDCT2D_retrievex(Rcpp::NumericMatrix mat);

TEST(imagerExtra_deepstate_test,IDCT2D_retrievex_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix mat  = RcppDeepState_NumericMatrix();
  std::string mat_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/IDCT2D_retrievex/AFL_IDCT2D_retrievex/afl_inputs/" + std::to_string(t) + "_mat.qs";
  qs::c_qsave(mat,mat_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "mat values: "<< mat << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    IDCT2D_retrievex(mat);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
