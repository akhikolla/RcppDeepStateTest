#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double RDay(double solarConstant, double latrad, double elevation, double slorad, double asprad, double delta, double diffTemp, double diffTempMonth, double vpa, double precipitation);

TEST(meteoland_deepstate_test,RDay_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector solarConstant(1);
  solarConstant[0]  = RcppDeepState_double();
  qs::c_qsave(solarConstant,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/RDay/inputs/solarConstant.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "solarConstant values: "<< solarConstant << std::endl;
  NumericVector latrad(1);
  latrad[0]  = RcppDeepState_double();
  qs::c_qsave(latrad,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/RDay/inputs/latrad.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "latrad values: "<< latrad << std::endl;
  NumericVector elevation(1);
  elevation[0]  = RcppDeepState_double();
  qs::c_qsave(elevation,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/RDay/inputs/elevation.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "elevation values: "<< elevation << std::endl;
  NumericVector slorad(1);
  slorad[0]  = RcppDeepState_double();
  qs::c_qsave(slorad,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/RDay/inputs/slorad.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "slorad values: "<< slorad << std::endl;
  NumericVector asprad(1);
  asprad[0]  = RcppDeepState_double();
  qs::c_qsave(asprad,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/RDay/inputs/asprad.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "asprad values: "<< asprad << std::endl;
  NumericVector delta(1);
  delta[0]  = RcppDeepState_double();
  qs::c_qsave(delta,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/RDay/inputs/delta.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "delta values: "<< delta << std::endl;
  NumericVector diffTemp(1);
  diffTemp[0]  = RcppDeepState_double();
  qs::c_qsave(diffTemp,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/RDay/inputs/diffTemp.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "diffTemp values: "<< diffTemp << std::endl;
  NumericVector diffTempMonth(1);
  diffTempMonth[0]  = RcppDeepState_double();
  qs::c_qsave(diffTempMonth,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/RDay/inputs/diffTempMonth.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "diffTempMonth values: "<< diffTempMonth << std::endl;
  NumericVector vpa(1);
  vpa[0]  = RcppDeepState_double();
  qs::c_qsave(vpa,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/RDay/inputs/vpa.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "vpa values: "<< vpa << std::endl;
  NumericVector precipitation(1);
  precipitation[0]  = RcppDeepState_double();
  qs::c_qsave(precipitation,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/RDay/inputs/precipitation.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "precipitation values: "<< precipitation << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    RDay(solarConstant[0],latrad[0],elevation[0],slorad[0],asprad[0],delta[0],diffTemp[0],diffTempMonth[0],vpa[0],precipitation[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
