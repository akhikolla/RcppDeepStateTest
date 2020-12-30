#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double averageDailyVapourPressure(double Tmin, double Tmax, double RHmin, double RHmax);

TEST(meteoland_deepstate_test,averageDailyVapourPressure_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector Tmin(1);
  Tmin[0]  = RcppDeepState_double();
  qs::c_qsave(Tmin,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/averageDailyVapourPressure/inputs/Tmin.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Tmin values: "<< Tmin << std::endl;
  NumericVector Tmax(1);
  Tmax[0]  = RcppDeepState_double();
  qs::c_qsave(Tmax,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/averageDailyVapourPressure/inputs/Tmax.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Tmax values: "<< Tmax << std::endl;
  NumericVector RHmin(1);
  RHmin[0]  = RcppDeepState_double();
  qs::c_qsave(RHmin,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/averageDailyVapourPressure/inputs/RHmin.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "RHmin values: "<< RHmin << std::endl;
  NumericVector RHmax(1);
  RHmax[0]  = RcppDeepState_double();
  qs::c_qsave(RHmax,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/averageDailyVapourPressure/inputs/RHmax.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "RHmax values: "<< RHmax << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    averageDailyVapourPressure(Tmin[0],Tmax[0],RHmin[0],RHmax[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
