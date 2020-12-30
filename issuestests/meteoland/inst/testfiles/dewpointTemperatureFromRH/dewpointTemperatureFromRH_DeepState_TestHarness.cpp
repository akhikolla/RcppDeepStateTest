#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix dewpointTemperatureFromRH(NumericMatrix T, NumericMatrix RH);

TEST(meteoland_deepstate_test,dewpointTemperatureFromRH_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix T  = RcppDeepState_NumericMatrix();
  qs::c_qsave(T,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/dewpointTemperatureFromRH/inputs/T.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "T values: "<< T << std::endl;
  NumericMatrix RH  = RcppDeepState_NumericMatrix();
  qs::c_qsave(RH,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/dewpointTemperatureFromRH/inputs/RH.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "RH values: "<< RH << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    dewpointTemperatureFromRH(T,RH);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
