#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double solarElevation(double latrad, double delta, double hrad);

TEST(meteoland_deepstate_test,solarElevation_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector latrad(1);
  latrad[0]  = RcppDeepState_double();
  std::string latrad_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/solarElevation/libFuzzer_solarElevation/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_latrad.qs";
  qs::c_qsave(latrad,latrad_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "latrad values: "<< latrad << std::endl;
  NumericVector delta(1);
  delta[0]  = RcppDeepState_double();
  std::string delta_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/solarElevation/libFuzzer_solarElevation/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_delta.qs";
  qs::c_qsave(delta,delta_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "delta values: "<< delta << std::endl;
  NumericVector hrad(1);
  hrad[0]  = RcppDeepState_double();
  std::string hrad_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/solarElevation/libFuzzer_solarElevation/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_hrad.qs";
  qs::c_qsave(hrad,hrad_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "hrad values: "<< hrad << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    solarElevation(latrad[0],delta[0],hrad[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
