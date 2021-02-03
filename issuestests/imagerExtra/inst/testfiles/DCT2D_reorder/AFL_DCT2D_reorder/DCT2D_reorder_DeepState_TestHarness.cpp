#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericMatrix DCT2D_reorder(Rcpp::NumericMatrix mat);

TEST(imagerExtra_deepstate_test,DCT2D_reorder_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix mat  = RcppDeepState_NumericMatrix();
  std::string mat_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/DCT2D_reorder/AFL_DCT2D_reorder/afl_inputs/" + std::to_string(t) + "_mat.qs";
  qs::c_qsave(mat,mat_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "mat values: "<< mat << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    DCT2D_reorder(mat);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
