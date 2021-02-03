#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double RpotDay(double solarConstant, double latrad, double slorad, double asprad, double delta);

TEST(meteoland_deepstate_test,RpotDay_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector solarConstant(1);
  solarConstant[0]  = RcppDeepState_double();
  std::string solarConstant_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/RpotDay/AFL_RpotDay/afl_inputs/" + std::to_string(t) + "_solarConstant.qs";
  qs::c_qsave(solarConstant,solarConstant_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "solarConstant values: "<< solarConstant << std::endl;
  NumericVector latrad(1);
  latrad[0]  = RcppDeepState_double();
  std::string latrad_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/RpotDay/AFL_RpotDay/afl_inputs/" + std::to_string(t) + "_latrad.qs";
  qs::c_qsave(latrad,latrad_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "latrad values: "<< latrad << std::endl;
  NumericVector slorad(1);
  slorad[0]  = RcppDeepState_double();
  std::string slorad_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/RpotDay/AFL_RpotDay/afl_inputs/" + std::to_string(t) + "_slorad.qs";
  qs::c_qsave(slorad,slorad_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "slorad values: "<< slorad << std::endl;
  NumericVector asprad(1);
  asprad[0]  = RcppDeepState_double();
  std::string asprad_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/RpotDay/AFL_RpotDay/afl_inputs/" + std::to_string(t) + "_asprad.qs";
  qs::c_qsave(asprad,asprad_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "asprad values: "<< asprad << std::endl;
  NumericVector delta(1);
  delta[0]  = RcppDeepState_double();
  std::string delta_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/RpotDay/AFL_RpotDay/afl_inputs/" + std::to_string(t) + "_delta.qs";
  qs::c_qsave(delta,delta_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "delta values: "<< delta << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    RpotDay(solarConstant[0],latrad[0],slorad[0],asprad[0],delta[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
