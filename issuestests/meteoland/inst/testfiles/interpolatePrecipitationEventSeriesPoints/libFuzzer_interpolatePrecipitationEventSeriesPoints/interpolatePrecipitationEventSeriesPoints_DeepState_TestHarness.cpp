#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix interpolatePrecipitationEventSeriesPoints(NumericVector Xp, NumericVector Yp, NumericVector Zp, NumericVector X, NumericVector Y, NumericVector Z, NumericMatrix Pevent, double iniRp, double alpha, int N, int iterations, double popcrit);

TEST(meteoland_deepstate_test,interpolatePrecipitationEventSeriesPoints_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector Xp  = RcppDeepState_NumericVector();
  std::string Xp_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolatePrecipitationEventSeriesPoints/libFuzzer_interpolatePrecipitationEventSeriesPoints/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Xp.qs";
  std::string X_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolatePrecipitationEventSeriesPoints/libFuzzer_interpolatePrecipitationEventSeriesPoints/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_X.qs";
  qs::c_qsave(Xp,Xp_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Xp values: "<< Xp << std::endl;
  NumericVector Yp  = RcppDeepState_NumericVector();
  std::string Yp_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolatePrecipitationEventSeriesPoints/libFuzzer_interpolatePrecipitationEventSeriesPoints/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Yp.qs";
  std::string Y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolatePrecipitationEventSeriesPoints/libFuzzer_interpolatePrecipitationEventSeriesPoints/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Y.qs";
  qs::c_qsave(Yp,Yp_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Yp values: "<< Yp << std::endl;
  NumericVector Zp  = RcppDeepState_NumericVector();
  std::string Zp_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolatePrecipitationEventSeriesPoints/libFuzzer_interpolatePrecipitationEventSeriesPoints/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Zp.qs";
  std::string Z_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolatePrecipitationEventSeriesPoints/libFuzzer_interpolatePrecipitationEventSeriesPoints/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Z.qs";
  qs::c_qsave(Zp,Zp_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Zp values: "<< Zp << std::endl;
  NumericVector X  = RcppDeepState_NumericVector();
  std::string X_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolatePrecipitationEventSeriesPoints/libFuzzer_interpolatePrecipitationEventSeriesPoints/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_X.qs";
  qs::c_qsave(X,X_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "X values: "<< X << std::endl;
  NumericVector Y  = RcppDeepState_NumericVector();
  std::string Y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolatePrecipitationEventSeriesPoints/libFuzzer_interpolatePrecipitationEventSeriesPoints/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Y.qs";
  qs::c_qsave(Y,Y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Y values: "<< Y << std::endl;
  NumericVector Z  = RcppDeepState_NumericVector();
  std::string Z_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolatePrecipitationEventSeriesPoints/libFuzzer_interpolatePrecipitationEventSeriesPoints/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Z.qs";
  qs::c_qsave(Z,Z_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Z values: "<< Z << std::endl;
  NumericMatrix Pevent  = RcppDeepState_NumericMatrix();
  std::string Pevent_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolatePrecipitationEventSeriesPoints/libFuzzer_interpolatePrecipitationEventSeriesPoints/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Pevent.qs";
  qs::c_qsave(Pevent,Pevent_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Pevent values: "<< Pevent << std::endl;
  NumericVector iniRp(1);
  iniRp[0]  = RcppDeepState_double();
  std::string iniRp_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolatePrecipitationEventSeriesPoints/libFuzzer_interpolatePrecipitationEventSeriesPoints/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_iniRp.qs";
  qs::c_qsave(iniRp,iniRp_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "iniRp values: "<< iniRp << std::endl;
  NumericVector alpha(1);
  alpha[0]  = RcppDeepState_double();
  std::string alpha_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolatePrecipitationEventSeriesPoints/libFuzzer_interpolatePrecipitationEventSeriesPoints/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_alpha.qs";
  qs::c_qsave(alpha,alpha_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "alpha values: "<< alpha << std::endl;
  IntegerVector N(1);
  N[0]  = RcppDeepState_int();
  std::string N_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolatePrecipitationEventSeriesPoints/libFuzzer_interpolatePrecipitationEventSeriesPoints/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_N.qs";
  qs::c_qsave(N,N_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "N values: "<< N << std::endl;
  IntegerVector iterations(1);
  iterations[0]  = RcppDeepState_int();
  std::string iterations_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolatePrecipitationEventSeriesPoints/libFuzzer_interpolatePrecipitationEventSeriesPoints/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_iterations.qs";
  qs::c_qsave(iterations,iterations_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "iterations values: "<< iterations << std::endl;
  NumericVector popcrit(1);
  popcrit[0]  = RcppDeepState_double();
  std::string popcrit_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolatePrecipitationEventSeriesPoints/libFuzzer_interpolatePrecipitationEventSeriesPoints/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_popcrit.qs";
  qs::c_qsave(popcrit,popcrit_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "popcrit values: "<< popcrit << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    interpolatePrecipitationEventSeriesPoints(Xp,Yp,Zp,X,Y,Z,Pevent,iniRp[0],alpha[0],N[0],iterations[0],popcrit[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
