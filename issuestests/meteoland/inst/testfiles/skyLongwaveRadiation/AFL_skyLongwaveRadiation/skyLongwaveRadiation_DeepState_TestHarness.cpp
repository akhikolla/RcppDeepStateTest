#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double skyLongwaveRadiation(double Tair, double vpa, double c);

TEST(meteoland_deepstate_test,skyLongwaveRadiation_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector Tair(1);
  Tair[0]  = RcppDeepState_double();
  std::string Tair_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/skyLongwaveRadiation/AFL_skyLongwaveRadiation/afl_inputs/" + std::to_string(t) + "_Tair.qs";
  qs::c_qsave(Tair,Tair_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Tair values: "<< Tair << std::endl;
  NumericVector vpa(1);
  vpa[0]  = RcppDeepState_double();
  std::string vpa_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/skyLongwaveRadiation/AFL_skyLongwaveRadiation/afl_inputs/" + std::to_string(t) + "_vpa.qs";
  qs::c_qsave(vpa,vpa_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "vpa values: "<< vpa << std::endl;
  NumericVector c(1);
  c[0]  = RcppDeepState_double();
  std::string c_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/skyLongwaveRadiation/AFL_skyLongwaveRadiation/afl_inputs/" + std::to_string(t) + "_c.qs";
  qs::c_qsave(c,c_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "c values: "<< c << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    skyLongwaveRadiation(Tair[0],vpa[0],c[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
