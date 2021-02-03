#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericMatrix ChanVeseInitPhi_Rect(int Width, int Height, Rcpp::IntegerVector rect);

TEST(imagerExtra_deepstate_test,ChanVeseInitPhi_Rect_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector Width(1);
  Width[0]  = RcppDeepState_int();
  std::string Width_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/ChanVeseInitPhi_Rect/AFL_ChanVeseInitPhi_Rect/afl_inputs/" + std::to_string(t) + "_Width.qs";
  qs::c_qsave(Width,Width_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Width values: "<< Width << std::endl;
  IntegerVector Height(1);
  Height[0]  = RcppDeepState_int();
  std::string Height_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/ChanVeseInitPhi_Rect/AFL_ChanVeseInitPhi_Rect/afl_inputs/" + std::to_string(t) + "_Height.qs";
  qs::c_qsave(Height,Height_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Height values: "<< Height << std::endl;
  IntegerVector rect  = RcppDeepState_IntegerVector();
  std::string rect_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/ChanVeseInitPhi_Rect/AFL_ChanVeseInitPhi_Rect/afl_inputs/" + std::to_string(t) + "_rect.qs";
  qs::c_qsave(rect,rect_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "rect values: "<< rect << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    ChanVeseInitPhi_Rect(Width[0],Height[0],rect);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
