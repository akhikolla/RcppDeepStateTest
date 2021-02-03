#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List getWindFieldIndexAndFactor(NumericMatrix windSpeed, NumericMatrix windDirection, NumericMatrix wfSpeed, NumericMatrix wfDirection);

TEST(meteoland_deepstate_test,getWindFieldIndexAndFactor_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix windSpeed  = RcppDeepState_NumericMatrix();
  std::string windSpeed_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/getWindFieldIndexAndFactor/AFL_getWindFieldIndexAndFactor/afl_inputs/" + std::to_string(t) + "_windSpeed.qs";
  qs::c_qsave(windSpeed,windSpeed_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "windSpeed values: "<< windSpeed << std::endl;
  NumericMatrix windDirection  = RcppDeepState_NumericMatrix();
  std::string windDirection_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/getWindFieldIndexAndFactor/AFL_getWindFieldIndexAndFactor/afl_inputs/" + std::to_string(t) + "_windDirection.qs";
  qs::c_qsave(windDirection,windDirection_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "windDirection values: "<< windDirection << std::endl;
  NumericMatrix wfSpeed  = RcppDeepState_NumericMatrix();
  std::string wfSpeed_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/getWindFieldIndexAndFactor/AFL_getWindFieldIndexAndFactor/afl_inputs/" + std::to_string(t) + "_wfSpeed.qs";
  qs::c_qsave(wfSpeed,wfSpeed_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "wfSpeed values: "<< wfSpeed << std::endl;
  NumericMatrix wfDirection  = RcppDeepState_NumericMatrix();
  std::string wfDirection_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/getWindFieldIndexAndFactor/AFL_getWindFieldIndexAndFactor/afl_inputs/" + std::to_string(t) + "_wfDirection.qs";
  qs::c_qsave(wfDirection,wfDirection_t,
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
