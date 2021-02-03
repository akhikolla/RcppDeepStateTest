#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double outgoingLongwaveRadiation(double solarConstant, double latrad, double elevation, double slorad, double asprad, double delta, double vpa, double tmin, double tmax, double R_s);

TEST(meteoland_deepstate_test,outgoingLongwaveRadiation_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector solarConstant(1);
  solarConstant[0]  = RcppDeepState_double();
  std::string solarConstant_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/outgoingLongwaveRadiation/AFL_outgoingLongwaveRadiation/afl_inputs/" + std::to_string(t) + "_solarConstant.qs";
  qs::c_qsave(solarConstant,solarConstant_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "solarConstant values: "<< solarConstant << std::endl;
  NumericVector latrad(1);
  latrad[0]  = RcppDeepState_double();
  std::string latrad_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/outgoingLongwaveRadiation/AFL_outgoingLongwaveRadiation/afl_inputs/" + std::to_string(t) + "_latrad.qs";
  qs::c_qsave(latrad,latrad_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "latrad values: "<< latrad << std::endl;
  NumericVector elevation(1);
  elevation[0]  = RcppDeepState_double();
  std::string elevation_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/outgoingLongwaveRadiation/AFL_outgoingLongwaveRadiation/afl_inputs/" + std::to_string(t) + "_elevation.qs";
  qs::c_qsave(elevation,elevation_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "elevation values: "<< elevation << std::endl;
  NumericVector slorad(1);
  slorad[0]  = RcppDeepState_double();
  std::string slorad_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/outgoingLongwaveRadiation/AFL_outgoingLongwaveRadiation/afl_inputs/" + std::to_string(t) + "_slorad.qs";
  qs::c_qsave(slorad,slorad_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "slorad values: "<< slorad << std::endl;
  NumericVector asprad(1);
  asprad[0]  = RcppDeepState_double();
  std::string asprad_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/outgoingLongwaveRadiation/AFL_outgoingLongwaveRadiation/afl_inputs/" + std::to_string(t) + "_asprad.qs";
  qs::c_qsave(asprad,asprad_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "asprad values: "<< asprad << std::endl;
  NumericVector delta(1);
  delta[0]  = RcppDeepState_double();
  std::string delta_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/outgoingLongwaveRadiation/AFL_outgoingLongwaveRadiation/afl_inputs/" + std::to_string(t) + "_delta.qs";
  qs::c_qsave(delta,delta_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "delta values: "<< delta << std::endl;
  NumericVector vpa(1);
  vpa[0]  = RcppDeepState_double();
  std::string vpa_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/outgoingLongwaveRadiation/AFL_outgoingLongwaveRadiation/afl_inputs/" + std::to_string(t) + "_vpa.qs";
  qs::c_qsave(vpa,vpa_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "vpa values: "<< vpa << std::endl;
  NumericVector tmin(1);
  tmin[0]  = RcppDeepState_double();
  std::string tmin_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/outgoingLongwaveRadiation/AFL_outgoingLongwaveRadiation/afl_inputs/" + std::to_string(t) + "_tmin.qs";
  qs::c_qsave(tmin,tmin_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tmin values: "<< tmin << std::endl;
  NumericVector tmax(1);
  tmax[0]  = RcppDeepState_double();
  std::string tmax_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/outgoingLongwaveRadiation/AFL_outgoingLongwaveRadiation/afl_inputs/" + std::to_string(t) + "_tmax.qs";
  qs::c_qsave(tmax,tmax_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tmax values: "<< tmax << std::endl;
  NumericVector R_s(1);
  R_s[0]  = RcppDeepState_double();
  std::string R_s_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/outgoingLongwaveRadiation/AFL_outgoingLongwaveRadiation/afl_inputs/" + std::to_string(t) + "_R_s.qs";
  qs::c_qsave(R_s,R_s_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "R_s values: "<< R_s << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    outgoingLongwaveRadiation(solarConstant[0],latrad[0],elevation[0],slorad[0],asprad[0],delta[0],vpa[0],tmin[0],tmax[0],R_s[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
