#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double rad2deg(double rad);

TEST(Rvoterdistance_deepstate_test,rad2deg_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector rad(1);
  rad[0]  = RcppDeepState_double();
  std::string rad_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rvoterdistance/inst/testfiles/rad2deg/libFuzzer_rad2deg/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_rad.qs";
  qs::c_qsave(rad,rad_t,
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
