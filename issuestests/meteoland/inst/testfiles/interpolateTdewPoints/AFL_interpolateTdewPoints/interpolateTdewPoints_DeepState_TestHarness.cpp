#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector interpolateTdewPoints(NumericVector Xp, NumericVector Yp, NumericVector Zp, NumericVector X, NumericVector Y, NumericVector Z, NumericVector T, double iniRp, double alpha, int N, int iterations);

TEST(meteoland_deepstate_test,interpolateTdewPoints_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector Xp  = RcppDeepState_NumericVector();
  std::string Xp_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolateTdewPoints/AFL_interpolateTdewPoints/afl_inputs/" + std::to_string(t) + "_Xp.qs";
  std::string X_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolateTdewPoints/AFL_interpolateTdewPoints/afl_inputs/" + std::to_string(t) + "_X.qs";
  qs::c_qsave(Xp,Xp_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Xp values: "<< Xp << std::endl;
  NumericVector Yp  = RcppDeepState_NumericVector();
  std::string Yp_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolateTdewPoints/AFL_interpolateTdewPoints/afl_inputs/" + std::to_string(t) + "_Yp.qs";
  std::string Y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolateTdewPoints/AFL_interpolateTdewPoints/afl_inputs/" + std::to_string(t) + "_Y.qs";
  qs::c_qsave(Yp,Yp_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Yp values: "<< Yp << std::endl;
  NumericVector Zp  = RcppDeepState_NumericVector();
  std::string Zp_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolateTdewPoints/AFL_interpolateTdewPoints/afl_inputs/" + std::to_string(t) + "_Zp.qs";
  std::string Z_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolateTdewPoints/AFL_interpolateTdewPoints/afl_inputs/" + std::to_string(t) + "_Z.qs";
  qs::c_qsave(Zp,Zp_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Zp values: "<< Zp << std::endl;
  NumericVector X  = RcppDeepState_NumericVector();
  std::string X_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolateTdewPoints/AFL_interpolateTdewPoints/afl_inputs/" + std::to_string(t) + "_X.qs";
  qs::c_qsave(X,X_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "X values: "<< X << std::endl;
  NumericVector Y  = RcppDeepState_NumericVector();
  std::string Y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolateTdewPoints/AFL_interpolateTdewPoints/afl_inputs/" + std::to_string(t) + "_Y.qs";
  qs::c_qsave(Y,Y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Y values: "<< Y << std::endl;
  NumericVector Z  = RcppDeepState_NumericVector();
  std::string Z_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolateTdewPoints/AFL_interpolateTdewPoints/afl_inputs/" + std::to_string(t) + "_Z.qs";
  qs::c_qsave(Z,Z_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Z values: "<< Z << std::endl;
  NumericVector T  = RcppDeepState_NumericVector();
  std::string T_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolateTdewPoints/AFL_interpolateTdewPoints/afl_inputs/" + std::to_string(t) + "_T.qs";
  qs::c_qsave(T,T_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "T values: "<< T << std::endl;
  NumericVector iniRp(1);
  iniRp[0]  = RcppDeepState_double();
  std::string iniRp_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolateTdewPoints/AFL_interpolateTdewPoints/afl_inputs/" + std::to_string(t) + "_iniRp.qs";
  qs::c_qsave(iniRp,iniRp_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "iniRp values: "<< iniRp << std::endl;
  NumericVector alpha(1);
  alpha[0]  = RcppDeepState_double();
  std::string alpha_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolateTdewPoints/AFL_interpolateTdewPoints/afl_inputs/" + std::to_string(t) + "_alpha.qs";
  qs::c_qsave(alpha,alpha_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "alpha values: "<< alpha << std::endl;
  IntegerVector N(1);
  N[0]  = RcppDeepState_int();
  std::string N_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolateTdewPoints/AFL_interpolateTdewPoints/afl_inputs/" + std::to_string(t) + "_N.qs";
  qs::c_qsave(N,N_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "N values: "<< N << std::endl;
  IntegerVector iterations(1);
  iterations[0]  = RcppDeepState_int();
  std::string iterations_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolateTdewPoints/AFL_interpolateTdewPoints/afl_inputs/" + std::to_string(t) + "_iterations.qs";
  qs::c_qsave(iterations,iterations_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "iterations values: "<< iterations << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    interpolateTdewPoints(Xp,Yp,Zp,X,Y,Z,T,iniRp[0],alpha[0],N[0],iterations[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
