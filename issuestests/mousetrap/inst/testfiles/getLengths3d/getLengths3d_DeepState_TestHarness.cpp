#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector getLengths3d(NumericMatrix xs, NumericMatrix ys, NumericMatrix zs);

TEST(mousetrap_deepstate_test,getLengths3d_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix xs  = RcppDeepState_NumericMatrix();
  qs::c_qsave(xs,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mousetrap/inst/testfiles/getLengths3d/inputs/xs.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "xs values: "<< xs << std::endl;
  NumericMatrix ys  = RcppDeepState_NumericMatrix();
  qs::c_qsave(ys,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mousetrap/inst/testfiles/getLengths3d/inputs/ys.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ys values: "<< ys << std::endl;
  NumericMatrix zs  = RcppDeepState_NumericMatrix();
  qs::c_qsave(zs,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mousetrap/inst/testfiles/getLengths3d/inputs/zs.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "zs values: "<< zs << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    getLengths3d(xs,ys,zs);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
