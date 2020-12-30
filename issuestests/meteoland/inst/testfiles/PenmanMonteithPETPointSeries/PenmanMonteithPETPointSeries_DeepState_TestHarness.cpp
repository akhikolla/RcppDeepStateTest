#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector PenmanMonteithPETPointSeries(double rc, double elevation, NumericVector Tmin, NumericVector Tmax, NumericVector RHmin, NumericVector RHmax, NumericVector Rn, NumericVector u);

TEST(meteoland_deepstate_test,PenmanMonteithPETPointSeries_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector rc(1);
  rc[0]  = RcppDeepState_double();
  qs::c_qsave(rc,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/PenmanMonteithPETPointSeries/inputs/rc.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "rc values: "<< rc << std::endl;
  NumericVector elevation(1);
  elevation[0]  = RcppDeepState_double();
  qs::c_qsave(elevation,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/PenmanMonteithPETPointSeries/inputs/elevation.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "elevation values: "<< elevation << std::endl;
  NumericVector Tmin  = RcppDeepState_NumericVector();
  qs::c_qsave(Tmin,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/PenmanMonteithPETPointSeries/inputs/Tmin.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Tmin values: "<< Tmin << std::endl;
  NumericVector Tmax  = RcppDeepState_NumericVector();
  qs::c_qsave(Tmax,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/PenmanMonteithPETPointSeries/inputs/Tmax.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Tmax values: "<< Tmax << std::endl;
  NumericVector RHmin  = RcppDeepState_NumericVector();
  qs::c_qsave(RHmin,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/PenmanMonteithPETPointSeries/inputs/RHmin.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "RHmin values: "<< RHmin << std::endl;
  NumericVector RHmax  = RcppDeepState_NumericVector();
  qs::c_qsave(RHmax,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/PenmanMonteithPETPointSeries/inputs/RHmax.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "RHmax values: "<< RHmax << std::endl;
  NumericVector Rn  = RcppDeepState_NumericVector();
  qs::c_qsave(Rn,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/PenmanMonteithPETPointSeries/inputs/Rn.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Rn values: "<< Rn << std::endl;
  NumericVector u  = RcppDeepState_NumericVector();
  qs::c_qsave(u,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/PenmanMonteithPETPointSeries/inputs/u.qs",
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
