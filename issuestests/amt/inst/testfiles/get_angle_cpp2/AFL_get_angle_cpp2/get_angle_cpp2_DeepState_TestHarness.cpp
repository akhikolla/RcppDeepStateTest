#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector get_angle_cpp2(NumericMatrix xy, double dir);

TEST(amt_deepstate_test,get_angle_cpp2_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix xy  = RcppDeepState_NumericMatrix();
  std::string xy_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/get_angle_cpp2/AFL_get_angle_cpp2/afl_inputs/" + std::to_string(t) + "_xy.qs";
  qs::c_qsave(xy,xy_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "xy values: "<< xy << std::endl;
  NumericVector dir(1);
  dir[0]  = RcppDeepState_double();
  std::string dir_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/get_angle_cpp2/AFL_get_angle_cpp2/afl_inputs/" + std::to_string(t) + "_dir.qs";
  qs::c_qsave(dir,dir_t,
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
