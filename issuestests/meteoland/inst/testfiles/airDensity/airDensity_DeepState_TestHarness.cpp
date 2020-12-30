#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double airDensity(double temperature, double Patm);

TEST(meteoland_deepstate_test,airDensity_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector temperature(1);
  temperature[0]  = RcppDeepState_double();
  qs::c_qsave(temperature,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/airDensity/inputs/temperature.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "temperature values: "<< temperature << std::endl;
  NumericVector Patm(1);
  Patm[0]  = RcppDeepState_double();
  qs::c_qsave(Patm,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/airDensity/inputs/Patm.qs",
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
