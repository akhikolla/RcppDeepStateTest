#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List getWindFieldIndexAndFactor(NumericMatrix windSpeed, NumericMatrix windDirection, NumericMatrix wfSpeed, NumericMatrix wfDirection);

TEST(meteoland_deepstate_test,getWindFieldIndexAndFactor_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix windSpeed  = RcppDeepState_NumericMatrix();
  qs::c_qsave(windSpeed,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/getWindFieldIndexAndFactor/inputs/windSpeed.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "windSpeed values: "<< windSpeed << std::endl;
  NumericMatrix windDirection  = RcppDeepState_NumericMatrix();
  qs::c_qsave(windDirection,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/getWindFieldIndexAndFactor/inputs/windDirection.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "windDirection values: "<< windDirection << std::endl;
  NumericMatrix wfSpeed  = RcppDeepState_NumericMatrix();
  qs::c_qsave(wfSpeed,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/getWindFieldIndexAndFactor/inputs/wfSpeed.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "wfSpeed values: "<< wfSpeed << std::endl;
  NumericMatrix wfDirection  = RcppDeepState_NumericMatrix();
  qs::c_qsave(wfDirection,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/getWindFieldIndexAndFactor/inputs/wfDirection.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "wfDirection values: "<< wfDirection << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    getWindFieldIndexAndFactor(windSpeed,windDirection,wfSpeed,wfDirection);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
