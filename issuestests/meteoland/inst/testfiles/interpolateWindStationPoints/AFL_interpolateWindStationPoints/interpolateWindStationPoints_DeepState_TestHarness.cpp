#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix interpolateWindStationPoints(NumericVector Xp, NumericVector Yp, NumericVector WS, NumericVector WD, NumericVector X, NumericVector Y, double iniRp, double alpha, int N, int iterations, double directionsAvailable);

TEST(meteoland_deepstate_test,interpolateWindStationPoints_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector Xp  = RcppDeepState_NumericVector();
  std::string Xp_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolateWindStationPoints/AFL_interpolateWindStationPoints/afl_inputs/" + std::to_string(t) + "_Xp.qs";
  std::string X_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolateWindStationPoints/AFL_interpolateWindStationPoints/afl_inputs/" + std::to_string(t) + "_X.qs";
  qs::c_qsave(Xp,Xp_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Xp values: "<< Xp << std::endl;
  NumericVector Yp  = RcppDeepState_NumericVector();
  std::string Yp_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolateWindStationPoints/AFL_interpolateWindStationPoints/afl_inputs/" + std::to_string(t) + "_Yp.qs";
  std::string Y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolateWindStationPoints/AFL_interpolateWindStationPoints/afl_inputs/" + std::to_string(t) + "_Y.qs";
  qs::c_qsave(Yp,Yp_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Yp values: "<< Yp << std::endl;
  NumericVector WS  = RcppDeepState_NumericVector();
  std::string WS_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolateWindStationPoints/AFL_interpolateWindStationPoints/afl_inputs/" + std::to_string(t) + "_WS.qs";
  qs::c_qsave(WS,WS_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "WS values: "<< WS << std::endl;
  NumericVector WD  = RcppDeepState_NumericVector();
  std::string WD_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolateWindStationPoints/AFL_interpolateWindStationPoints/afl_inputs/" + std::to_string(t) + "_WD.qs";
  qs::c_qsave(WD,WD_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "WD values: "<< WD << std::endl;
  NumericVector X  = RcppDeepState_NumericVector();
  std::string X_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolateWindStationPoints/AFL_interpolateWindStationPoints/afl_inputs/" + std::to_string(t) + "_X.qs";
  qs::c_qsave(X,X_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "X values: "<< X << std::endl;
  NumericVector Y  = RcppDeepState_NumericVector();
  std::string Y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolateWindStationPoints/AFL_interpolateWindStationPoints/afl_inputs/" + std::to_string(t) + "_Y.qs";
  qs::c_qsave(Y,Y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Y values: "<< Y << std::endl;
  NumericVector iniRp(1);
  iniRp[0]  = RcppDeepState_double();
  std::string iniRp_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolateWindStationPoints/AFL_interpolateWindStationPoints/afl_inputs/" + std::to_string(t) + "_iniRp.qs";
  qs::c_qsave(iniRp,iniRp_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "iniRp values: "<< iniRp << std::endl;
  NumericVector alpha(1);
  alpha[0]  = RcppDeepState_double();
  std::string alpha_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolateWindStationPoints/AFL_interpolateWindStationPoints/afl_inputs/" + std::to_string(t) + "_alpha.qs";
  qs::c_qsave(alpha,alpha_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "alpha values: "<< alpha << std::endl;
  IntegerVector N(1);
  N[0]  = RcppDeepState_int();
  std::string N_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolateWindStationPoints/AFL_interpolateWindStationPoints/afl_inputs/" + std::to_string(t) + "_N.qs";
  qs::c_qsave(N,N_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "N values: "<< N << std::endl;
  IntegerVector iterations(1);
  iterations[0]  = RcppDeepState_int();
  std::string iterations_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolateWindStationPoints/AFL_interpolateWindStationPoints/afl_inputs/" + std::to_string(t) + "_iterations.qs";
  qs::c_qsave(iterations,iterations_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "iterations values: "<< iterations << std::endl;
  NumericVector directionsAvailable(1);
  directionsAvailable[0]  = RcppDeepState_double();
  std::string directionsAvailable_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolateWindStationPoints/AFL_interpolateWindStationPoints/afl_inputs/" + std::to_string(t) + "_directionsAvailable.qs";
  qs::c_qsave(directionsAvailable,directionsAvailable_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "directionsAvailable values: "<< directionsAvailable << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    interpolateWindStationPoints(Xp,Yp,WS,WD,X,Y,iniRp[0],alpha[0],N[0],iterations[0],directionsAvailable[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
