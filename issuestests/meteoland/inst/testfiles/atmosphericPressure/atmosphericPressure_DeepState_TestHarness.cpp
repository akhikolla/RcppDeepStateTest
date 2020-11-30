#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double atmosphericPressure(double elevation);

TEST(meteoland_deepstate_test,atmosphericPressure_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector elevation(1);
  elevation[0]  = RcppDeepState_double();
  qs::c_qsave(elevation,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/atmosphericPressure/inputs/elevation.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "elevation values: "<< elevation << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    atmosphericPressure(elevation[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
