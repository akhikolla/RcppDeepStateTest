#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double PenmanMonteithPET(double rc, double elevation, double Tmin, double Tmax, double RHmin, double RHmax, double Rn, double u);

TEST(meteoland_deepstate_test,PenmanMonteithPET_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector rc(1);
  rc[0]  = RcppDeepState_double();
  qs::c_qsave(rc,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/PenmanMonteithPET/inputs/rc.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "rc values: "<< rc << std::endl;
  NumericVector elevation(1);
  elevation[0]  = RcppDeepState_double();
  qs::c_qsave(elevation,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/PenmanMonteithPET/inputs/elevation.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "elevation values: "<< elevation << std::endl;
  NumericVector Tmin(1);
  Tmin[0]  = RcppDeepState_double();
  qs::c_qsave(Tmin,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/PenmanMonteithPET/inputs/Tmin.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Tmin values: "<< Tmin << std::endl;
  NumericVector Tmax(1);
  Tmax[0]  = RcppDeepState_double();
  qs::c_qsave(Tmax,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/PenmanMonteithPET/inputs/Tmax.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Tmax values: "<< Tmax << std::endl;
  NumericVector RHmin(1);
  RHmin[0]  = RcppDeepState_double();
  qs::c_qsave(RHmin,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/PenmanMonteithPET/inputs/RHmin.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "RHmin values: "<< RHmin << std::endl;
  NumericVector RHmax(1);
  RHmax[0]  = RcppDeepState_double();
  qs::c_qsave(RHmax,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/PenmanMonteithPET/inputs/RHmax.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "RHmax values: "<< RHmax << std::endl;
  NumericVector Rn(1);
  Rn[0]  = RcppDeepState_double();
  qs::c_qsave(Rn,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/PenmanMonteithPET/inputs/Rn.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Rn values: "<< Rn << std::endl;
  NumericVector u(1);
  u[0]  = RcppDeepState_double();
  qs::c_qsave(u,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/PenmanMonteithPET/inputs/u.qs",
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
