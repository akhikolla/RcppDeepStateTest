#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector PenmanMonteithPETPointSeries(double rc, double elevation, NumericVector Tmin, NumericVector Tmax, NumericVector RHmin, NumericVector RHmax, NumericVector Rn, NumericVector u);

TEST(meteoland_deepstate_test,PenmanMonteithPETPointSeries_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector rc(1);
  rc[0]  = RcppDeepState_double();
  std::string rc_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/PenmanMonteithPETPointSeries/AFL_PenmanMonteithPETPointSeries/afl_inputs/" + std::to_string(t) + "_rc.qs";
  qs::c_qsave(rc,rc_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "rc values: "<< rc << std::endl;
  NumericVector elevation(1);
  elevation[0]  = RcppDeepState_double();
  std::string elevation_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/PenmanMonteithPETPointSeries/AFL_PenmanMonteithPETPointSeries/afl_inputs/" + std::to_string(t) + "_elevation.qs";
  qs::c_qsave(elevation,elevation_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "elevation values: "<< elevation << std::endl;
  NumericVector Tmin  = RcppDeepState_NumericVector();
  std::string Tmin_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/PenmanMonteithPETPointSeries/AFL_PenmanMonteithPETPointSeries/afl_inputs/" + std::to_string(t) + "_Tmin.qs";
  qs::c_qsave(Tmin,Tmin_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Tmin values: "<< Tmin << std::endl;
  NumericVector Tmax  = RcppDeepState_NumericVector();
  std::string Tmax_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/PenmanMonteithPETPointSeries/AFL_PenmanMonteithPETPointSeries/afl_inputs/" + std::to_string(t) + "_Tmax.qs";
  qs::c_qsave(Tmax,Tmax_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Tmax values: "<< Tmax << std::endl;
  NumericVector RHmin  = RcppDeepState_NumericVector();
  std::string RHmin_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/PenmanMonteithPETPointSeries/AFL_PenmanMonteithPETPointSeries/afl_inputs/" + std::to_string(t) + "_RHmin.qs";
  qs::c_qsave(RHmin,RHmin_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "RHmin values: "<< RHmin << std::endl;
  NumericVector RHmax  = RcppDeepState_NumericVector();
  std::string RHmax_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/PenmanMonteithPETPointSeries/AFL_PenmanMonteithPETPointSeries/afl_inputs/" + std::to_string(t) + "_RHmax.qs";
  qs::c_qsave(RHmax,RHmax_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "RHmax values: "<< RHmax << std::endl;
  NumericVector Rn  = RcppDeepState_NumericVector();
  std::string Rn_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/PenmanMonteithPETPointSeries/AFL_PenmanMonteithPETPointSeries/afl_inputs/" + std::to_string(t) + "_Rn.qs";
  qs::c_qsave(Rn,Rn_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Rn values: "<< Rn << std::endl;
  NumericVector u  = RcppDeepState_NumericVector();
  std::string u_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/PenmanMonteithPETPointSeries/AFL_PenmanMonteithPETPointSeries/afl_inputs/" + std::to_string(t) + "_u.qs";
  qs::c_qsave(u,u_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "u values: "<< u << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    PenmanMonteithPETPointSeries(rc[0],elevation[0],Tmin,Tmax,RHmin,RHmax,Rn,u);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
