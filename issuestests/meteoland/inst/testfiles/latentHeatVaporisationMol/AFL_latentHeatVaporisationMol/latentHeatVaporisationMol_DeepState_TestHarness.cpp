#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double latentHeatVaporisationMol(double temperature);

TEST(meteoland_deepstate_test,latentHeatVaporisationMol_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector temperature(1);
  temperature[0]  = RcppDeepState_double();
  std::string temperature_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/latentHeatVaporisationMol/AFL_latentHeatVaporisationMol/afl_inputs/" + std::to_string(t) + "_temperature.qs";
  qs::c_qsave(temperature,temperature_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "temperature values: "<< temperature << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    latentHeatVaporisationMol(temperature[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
