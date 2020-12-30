#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericMatrix ChanVeseInitPhi_Rect(int Width, int Height, Rcpp::IntegerVector rect);

TEST(imagerExtra_deepstate_test,ChanVeseInitPhi_Rect_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector Width(1);
  Width[0]  = RcppDeepState_int();
  qs::c_qsave(Width,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/ChanVeseInitPhi_Rect/inputs/Width.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Width values: "<< Width << std::endl;
  IntegerVector Height(1);
  Height[0]  = RcppDeepState_int();
  qs::c_qsave(Height,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/ChanVeseInitPhi_Rect/inputs/Height.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Height values: "<< Height << std::endl;
  IntegerVector rect  = RcppDeepState_IntegerVector();
  qs::c_qsave(rect,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/ChanVeseInitPhi_Rect/inputs/rect.qs",
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
