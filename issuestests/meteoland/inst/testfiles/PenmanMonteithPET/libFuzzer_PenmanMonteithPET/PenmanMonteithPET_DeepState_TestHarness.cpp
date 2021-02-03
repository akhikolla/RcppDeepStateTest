#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double PenmanMonteithPET(double rc, double elevation, double Tmin, double Tmax, double RHmin, double RHmax, double Rn, double u);

TEST(meteoland_deepstate_test,PenmanMonteithPET_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector rc(1);
  rc[0]  = RcppDeepState_double();
  std::string rc_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/PenmanMonteithPET/libFuzzer_PenmanMonteithPET/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_rc.qs";
  qs::c_qsave(rc,rc_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "rc values: "<< rc << std::endl;
  NumericVector elevation(1);
  elevation[0]  = RcppDeepState_double();
  std::string elevation_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/PenmanMonteithPET/libFuzzer_PenmanMonteithPET/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_elevation.qs";
  qs::c_qsave(elevation,elevation_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "elevation values: "<< elevation << std::endl;
  NumericVector Tmin(1);
  Tmin[0]  = RcppDeepState_double();
  std::string Tmin_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/PenmanMonteithPET/libFuzzer_PenmanMonteithPET/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Tmin.qs";
  qs::c_qsave(Tmin,Tmin_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Tmin values: "<< Tmin << std::endl;
  NumericVector Tmax(1);
  Tmax[0]  = RcppDeepState_double();
  std::string Tmax_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/PenmanMonteithPET/libFuzzer_PenmanMonteithPET/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Tmax.qs";
  qs::c_qsave(Tmax,Tmax_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Tmax values: "<< Tmax << std::endl;
  NumericVector RHmin(1);
  RHmin[0]  = RcppDeepState_double();
  std::string RHmin_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/PenmanMonteithPET/libFuzzer_PenmanMonteithPET/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_RHmin.qs";
  qs::c_qsave(RHmin,RHmin_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "RHmin values: "<< RHmin << std::endl;
  NumericVector RHmax(1);
  RHmax[0]  = RcppDeepState_double();
  std::string RHmax_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/PenmanMonteithPET/libFuzzer_PenmanMonteithPET/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_RHmax.qs";
  qs::c_qsave(RHmax,RHmax_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "RHmax values: "<< RHmax << std::endl;
  NumericVector Rn(1);
  Rn[0]  = RcppDeepState_double();
  std::string Rn_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/PenmanMonteithPET/libFuzzer_PenmanMonteithPET/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Rn.qs";
  qs::c_qsave(Rn,Rn_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Rn values: "<< Rn << std::endl;
  NumericVector u(1);
  u[0]  = RcppDeepState_double();
  std::string u_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/PenmanMonteithPET/libFuzzer_PenmanMonteithPET/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_u.qs";
  qs::c_qsave(u,u_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "u values: "<< u << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    PenmanMonteithPET(rc[0],elevation[0],Tmin[0],Tmax[0],RHmin[0],RHmax[0],Rn[0],u[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
