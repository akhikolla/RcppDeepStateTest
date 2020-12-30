#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector radiationSeries(double latrad, double elevation, double slorad, double asprad, NumericVector J, NumericVector diffTemp, NumericVector diffTempMonth, NumericVector VP, NumericVector P);

TEST(meteoland_deepstate_test,radiationSeries_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector latrad(1);
  latrad[0]  = RcppDeepState_double();
  qs::c_qsave(latrad,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/radiationSeries/inputs/latrad.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "latrad values: "<< latrad << std::endl;
  NumericVector elevation(1);
  elevation[0]  = RcppDeepState_double();
  qs::c_qsave(elevation,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/radiationSeries/inputs/elevation.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "elevation values: "<< elevation << std::endl;
  NumericVector slorad(1);
  slorad[0]  = RcppDeepState_double();
  qs::c_qsave(slorad,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/radiationSeries/inputs/slorad.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "slorad values: "<< slorad << std::endl;
  NumericVector asprad(1);
  asprad[0]  = RcppDeepState_double();
  qs::c_qsave(asprad,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/radiationSeries/inputs/asprad.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "asprad values: "<< asprad << std::endl;
  NumericVector J  = RcppDeepState_NumericVector();
  qs::c_qsave(J,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/radiationSeries/inputs/J.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "J values: "<< J << std::endl;
  NumericVector diffTemp  = RcppDeepState_NumericVector();
  qs::c_qsave(diffTemp,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/radiationSeries/inputs/diffTemp.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "diffTemp values: "<< diffTemp << std::endl;
  NumericVector diffTempMonth  = RcppDeepState_NumericVector();
  qs::c_qsave(diffTempMonth,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/radiationSeries/inputs/diffTempMonth.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "diffTempMonth values: "<< diffTempMonth << std::endl;
  NumericVector VP  = RcppDeepState_NumericVector();
  qs::c_qsave(VP,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/radiationSeries/inputs/VP.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "VP values: "<< VP << std::endl;
  NumericVector P  = RcppDeepState_NumericVector();
  qs::c_qsave(P,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/radiationSeries/inputs/P.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "P values: "<< P << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    radiationSeries(latrad[0],elevation[0],slorad[0],asprad[0],J,diffTemp,diffTempMonth,VP,P);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
