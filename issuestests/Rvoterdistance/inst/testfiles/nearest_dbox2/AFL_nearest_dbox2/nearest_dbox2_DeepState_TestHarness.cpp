#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List nearest_dbox2(NumericMatrix lat_lon1d, NumericMatrix lat_lon2d);

TEST(Rvoterdistance_deepstate_test,nearest_dbox2_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix lat_lon1d  = RcppDeepState_NumericMatrix();
  std::string lat_lon1d_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rvoterdistance/inst/testfiles/nearest_dbox2/AFL_nearest_dbox2/afl_inputs/" + std::to_string(t) + "_lat_lon1d.qs";
  qs::c_qsave(lat_lon1d,lat_lon1d_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lat_lon1d values: "<< lat_lon1d << std::endl;
  NumericMatrix lat_lon2d  = RcppDeepState_NumericMatrix();
  std::string lat_lon2d_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rvoterdistance/inst/testfiles/nearest_dbox2/AFL_nearest_dbox2/afl_inputs/" + std::to_string(t) + "_lat_lon2d.qs";
  qs::c_qsave(lat_lon2d,lat_lon2d_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lat_lon2d values: "<< lat_lon2d << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    nearest_dbox2(lat_lon1d,lat_lon2d);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
