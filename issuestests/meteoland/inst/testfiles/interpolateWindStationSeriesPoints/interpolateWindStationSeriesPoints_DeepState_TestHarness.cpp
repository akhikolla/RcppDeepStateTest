#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List interpolateWindStationSeriesPoints(NumericVector Xp, NumericVector Yp, NumericMatrix WS, NumericMatrix WD, NumericVector X, NumericVector Y, double iniRp, double alpha, int N, int iterations);

TEST(meteoland_deepstate_test,interpolateWindStationSeriesPoints_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector Xp  = RcppDeepState_NumericVector();
  qs::c_qsave(Xp,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolateWindStationSeriesPoints/inputs/Xp.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Xp values: "<< Xp << std::endl;
  NumericVector Yp  = RcppDeepState_NumericVector();
  qs::c_qsave(Yp,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolateWindStationSeriesPoints/inputs/Yp.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Yp values: "<< Yp << std::endl;
  NumericMatrix WS  = RcppDeepState_NumericMatrix();
  qs::c_qsave(WS,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolateWindStationSeriesPoints/inputs/WS.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "WS values: "<< WS << std::endl;
  NumericMatrix WD  = RcppDeepState_NumericMatrix();
  qs::c_qsave(WD,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolateWindStationSeriesPoints/inputs/WD.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "WD values: "<< WD << std::endl;
  NumericVector X  = RcppDeepState_NumericVector();
  qs::c_qsave(X,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolateWindStationSeriesPoints/inputs/X.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "X values: "<< X << std::endl;
  NumericVector Y  = RcppDeepState_NumericVector();
  qs::c_qsave(Y,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolateWindStationSeriesPoints/inputs/Y.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Y values: "<< Y << std::endl;
  NumericVector iniRp(1);
  iniRp[0]  = RcppDeepState_double();
  qs::c_qsave(iniRp,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolateWindStationSeriesPoints/inputs/iniRp.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "iniRp values: "<< iniRp << std::endl;
  NumericVector alpha(1);
  alpha[0]  = RcppDeepState_double();
  qs::c_qsave(alpha,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolateWindStationSeriesPoints/inputs/alpha.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "alpha values: "<< alpha << std::endl;
  IntegerVector N(1);
  N[0]  = RcppDeepState_int();
  qs::c_qsave(N,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolateWindStationSeriesPoints/inputs/N.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "N values: "<< N << std::endl;
  IntegerVector iterations(1);
  iterations[0]  = RcppDeepState_int();
  qs::c_qsave(iterations,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolateWindStationSeriesPoints/inputs/iterations.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "iterations values: "<< iterations << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    interpolateWindStationSeriesPoints(Xp,Yp,WS,WD,X,Y,iniRp[0],alpha[0],N[0],iterations[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
