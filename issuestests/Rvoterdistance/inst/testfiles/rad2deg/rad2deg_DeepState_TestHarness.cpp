#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double rad2deg(double rad);

TEST(Rvoterdistance_deepstate_test,rad2deg_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector rad(1);
  rad[0]  = RcppDeepState_double();
  qs::c_qsave(rad,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rvoterdistance/inst/testfiles/rad2deg/inputs/rad.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "rad values: "<< rad << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    rad2deg(rad[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
