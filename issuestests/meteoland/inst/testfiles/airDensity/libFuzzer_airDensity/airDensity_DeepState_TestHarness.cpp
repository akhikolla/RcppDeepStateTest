#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double airDensity(double temperature, double Patm);

TEST(meteoland_deepstate_test,airDensity_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector temperature(1);
  temperature[0]  = RcppDeepState_double();
  std::string temperature_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/airDensity/libFuzzer_airDensity/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_temperature.qs";
  qs::c_qsave(temperature,temperature_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "temperature values: "<< temperature << std::endl;
  NumericVector Patm(1);
  Patm[0]  = RcppDeepState_double();
  std::string Patm_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/airDensity/libFuzzer_airDensity/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Patm.qs";
  qs::c_qsave(Patm,Patm_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Patm values: "<< Patm << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    airDensity(temperature[0],Patm[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
