#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector relativeHumidityFromDewpointTemp(NumericVector T, NumericVector TD);

TEST(meteoland_deepstate_test,relativeHumidityFromDewpointTemp_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector T  = RcppDeepState_NumericVector();
  qs::c_qsave(T,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/relativeHumidityFromDewpointTemp/inputs/T.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "T values: "<< T << std::endl;
  NumericVector TD  = RcppDeepState_NumericVector();
  qs::c_qsave(TD,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/relativeHumidityFromDewpointTemp/inputs/TD.qs",
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
