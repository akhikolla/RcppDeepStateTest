#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector relativeHumidityFromDewpointTemp(NumericVector T, NumericVector TD);

TEST(meteoland_deepstate_test,relativeHumidityFromDewpointTemp_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector T  = RcppDeepState_NumericVector();
  std::string T_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/relativeHumidityFromDewpointTemp/AFL_relativeHumidityFromDewpointTemp/afl_inputs/" + std::to_string(t) + "_T.qs";
  qs::c_qsave(T,T_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "T values: "<< T << std::endl;
  NumericVector TD  = RcppDeepState_NumericVector();
  std::string T_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/relativeHumidityFromDewpointTemp/AFL_relativeHumidityFromDewpointTemp/afl_inputs/" + std::to_string(t) + "_T.qs";
  std::string TD_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/relativeHumidityFromDewpointTemp/AFL_relativeHumidityFromDewpointTemp/afl_inputs/" + std::to_string(t) + "_TD.qs";
  qs::c_qsave(TD,TD_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "TD values: "<< TD << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    relativeHumidityFromDewpointTemp(T,TD);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
