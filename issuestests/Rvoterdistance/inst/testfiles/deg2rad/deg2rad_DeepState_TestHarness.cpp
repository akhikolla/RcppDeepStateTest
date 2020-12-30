#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double deg2rad(double deg);

TEST(Rvoterdistance_deepstate_test,deg2rad_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector deg(1);
  deg[0]  = RcppDeepState_double();
  qs::c_qsave(deg,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rvoterdistance/inst/testfiles/deg2rad/inputs/deg.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "deg values: "<< deg << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    deg2rad(deg[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
