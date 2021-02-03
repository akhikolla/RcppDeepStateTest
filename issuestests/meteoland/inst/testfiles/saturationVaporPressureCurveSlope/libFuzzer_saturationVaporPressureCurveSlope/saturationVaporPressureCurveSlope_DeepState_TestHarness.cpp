#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double saturationVaporPressureCurveSlope(double temperature);

TEST(meteoland_deepstate_test,saturationVaporPressureCurveSlope_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector temperature(1);
  temperature[0]  = RcppDeepState_double();
  std::string temperature_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/saturationVaporPressureCurveSlope/libFuzzer_saturationVaporPressureCurveSlope/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_temperature.qs";
  qs::c_qsave(temperature,temperature_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "temperature values: "<< temperature << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    saturationVaporPressureCurveSlope(temperature[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
