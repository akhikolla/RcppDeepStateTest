#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector interpolatePrecipitationPoints(NumericVector Xp, NumericVector Yp, NumericVector Zp, NumericVector X, NumericVector Y, NumericVector Z, NumericVector P, NumericVector Psmooth, double iniRp, double alpha_event, double alpha_amount, int N_event, int N_amount, int iterations, double popcrit, double fmax);

TEST(meteoland_deepstate_test,interpolatePrecipitationPoints_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector Xp  = RcppDeepState_NumericVector();
  std::string Xp_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolatePrecipitationPoints/libFuzzer_interpolatePrecipitationPoints/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Xp.qs";
  std::string X_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolatePrecipitationPoints/libFuzzer_interpolatePrecipitationPoints/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_X.qs";
  qs::c_qsave(Xp,Xp_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Xp values: "<< Xp << std::endl;
  NumericVector Yp  = RcppDeepState_NumericVector();
  std::string Yp_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolatePrecipitationPoints/libFuzzer_interpolatePrecipitationPoints/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Yp.qs";
  std::string Y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolatePrecipitationPoints/libFuzzer_interpolatePrecipitationPoints/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Y.qs";
  qs::c_qsave(Yp,Yp_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Yp values: "<< Yp << std::endl;
  NumericVector Zp  = RcppDeepState_NumericVector();
  std::string Zp_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolatePrecipitationPoints/libFuzzer_interpolatePrecipitationPoints/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Zp.qs";
  std::string Z_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolatePrecipitationPoints/libFuzzer_interpolatePrecipitationPoints/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Z.qs";
  qs::c_qsave(Zp,Zp_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Zp values: "<< Zp << std::endl;
  NumericVector X  = RcppDeepState_NumericVector();
  std::string X_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolatePrecipitationPoints/libFuzzer_interpolatePrecipitationPoints/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_X.qs";
  qs::c_qsave(X,X_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "X values: "<< X << std::endl;
  NumericVector Y  = RcppDeepState_NumericVector();
  std::string Y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolatePrecipitationPoints/libFuzzer_interpolatePrecipitationPoints/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Y.qs";
  qs::c_qsave(Y,Y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Y values: "<< Y << std::endl;
  NumericVector Z  = RcppDeepState_NumericVector();
  std::string Z_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolatePrecipitationPoints/libFuzzer_interpolatePrecipitationPoints/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Z.qs";
  qs::c_qsave(Z,Z_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Z values: "<< Z << std::endl;
  NumericVector P  = RcppDeepState_NumericVector();
  std::string P_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolatePrecipitationPoints/libFuzzer_interpolatePrecipitationPoints/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_P.qs";
  qs::c_qsave(P,P_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "P values: "<< P << std::endl;
  NumericVector Psmooth  = RcppDeepState_NumericVector();
  std::string P_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolatePrecipitationPoints/libFuzzer_interpolatePrecipitationPoints/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_P.qs";
  std::string Psmooth_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolatePrecipitationPoints/libFuzzer_interpolatePrecipitationPoints/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Psmooth.qs";
  qs::c_qsave(Psmooth,Psmooth_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Psmooth values: "<< Psmooth << std::endl;
  NumericVector iniRp(1);
  iniRp[0]  = RcppDeepState_double();
  std::string iniRp_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolatePrecipitationPoints/libFuzzer_interpolatePrecipitationPoints/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_iniRp.qs";
  qs::c_qsave(iniRp,iniRp_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "iniRp values: "<< iniRp << std::endl;
  NumericVector alpha_event(1);
  alpha_event[0]  = RcppDeepState_double();
  std::string alpha_event_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolatePrecipitationPoints/libFuzzer_interpolatePrecipitationPoints/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_alpha_event.qs";
  qs::c_qsave(alpha_event,alpha_event_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "alpha_event values: "<< alpha_event << std::endl;
  NumericVector alpha_amount(1);
  alpha_amount[0]  = RcppDeepState_double();
  std::string alpha_amount_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolatePrecipitationPoints/libFuzzer_interpolatePrecipitationPoints/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_alpha_amount.qs";
  qs::c_qsave(alpha_amount,alpha_amount_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "alpha_amount values: "<< alpha_amount << std::endl;
  IntegerVector N_event(1);
  N_event[0]  = RcppDeepState_int();
  std::string N_event_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolatePrecipitationPoints/libFuzzer_interpolatePrecipitationPoints/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_N_event.qs";
  qs::c_qsave(N_event,N_event_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "N_event values: "<< N_event << std::endl;
  IntegerVector N_amount(1);
  N_amount[0]  = RcppDeepState_int();
  std::string N_amount_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolatePrecipitationPoints/libFuzzer_interpolatePrecipitationPoints/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_N_amount.qs";
  qs::c_qsave(N_amount,N_amount_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "N_amount values: "<< N_amount << std::endl;
  IntegerVector iterations(1);
  iterations[0]  = RcppDeepState_int();
  std::string iterations_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolatePrecipitationPoints/libFuzzer_interpolatePrecipitationPoints/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_iterations.qs";
  qs::c_qsave(iterations,iterations_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "iterations values: "<< iterations << std::endl;
  NumericVector popcrit(1);
  popcrit[0]  = RcppDeepState_double();
  std::string popcrit_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolatePrecipitationPoints/libFuzzer_interpolatePrecipitationPoints/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_popcrit.qs";
  qs::c_qsave(popcrit,popcrit_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "popcrit values: "<< popcrit << std::endl;
  NumericVector fmax(1);
  fmax[0]  = RcppDeepState_double();
  std::string fmax_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolatePrecipitationPoints/libFuzzer_interpolatePrecipitationPoints/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_fmax.qs";
  qs::c_qsave(fmax,fmax_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "fmax values: "<< fmax << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    interpolatePrecipitationPoints(Xp,Yp,Zp,X,Y,Z,P,Psmooth,iniRp[0],alpha_event[0],alpha_amount[0],N_event[0],N_amount[0],iterations[0],popcrit[0],fmax[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
