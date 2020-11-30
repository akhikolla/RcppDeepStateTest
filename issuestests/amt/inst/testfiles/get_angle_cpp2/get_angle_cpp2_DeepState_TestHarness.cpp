#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector get_angle_cpp2(NumericMatrix xy, double dir);

TEST(amt_deepstate_test,get_angle_cpp2_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix xy  = RcppDeepState_NumericMatrix();
  qs::c_qsave(xy,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/get_angle_cpp2/inputs/xy.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "xy values: "<< xy << std::endl;
  NumericVector dir(1);
  dir[0]  = RcppDeepState_double();
  qs::c_qsave(dir,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/get_angle_cpp2/inputs/dir.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "dir values: "<< dir << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    get_angle_cpp2(xy,dir[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
