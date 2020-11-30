#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector interpolatePrecipitationPoints(NumericVector Xp, NumericVector Yp, NumericVector Zp, NumericVector X, NumericVector Y, NumericVector Z, NumericVector P, NumericVector Psmooth, double iniRp, double alpha_event, double alpha_amount, int N_event, int N_amount, int iterations, double popcrit, double fmax);

TEST(meteoland_deepstate_test,interpolatePrecipitationPoints_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector Xp  = RcppDeepState_NumericVector();
  qs::c_qsave(Xp,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolatePrecipitationPoints/inputs/Xp.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Xp values: "<< Xp << std::endl;
  NumericVector Yp  = RcppDeepState_NumericVector();
  qs::c_qsave(Yp,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolatePrecipitationPoints/inputs/Yp.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Yp values: "<< Yp << std::endl;
  NumericVector Zp  = RcppDeepState_NumericVector();
  qs::c_qsave(Zp,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolatePrecipitationPoints/inputs/Zp.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Zp values: "<< Zp << std::endl;
  NumericVector X  = RcppDeepState_NumericVector();
  qs::c_qsave(X,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolatePrecipitationPoints/inputs/X.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "X values: "<< X << std::endl;
  NumericVector Y  = RcppDeepState_NumericVector();
  qs::c_qsave(Y,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolatePrecipitationPoints/inputs/Y.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Y values: "<< Y << std::endl;
  NumericVector Z  = RcppDeepState_NumericVector();
  qs::c_qsave(Z,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolatePrecipitationPoints/inputs/Z.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Z values: "<< Z << std::endl;
  NumericVector P  = RcppDeepState_NumericVector();
  qs::c_qsave(P,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolatePrecipitationPoints/inputs/P.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "P values: "<< P << std::endl;
  NumericVector Psmooth  = RcppDeepState_NumericVector();
  qs::c_qsave(Psmooth,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolatePrecipitationPoints/inputs/Psmooth.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Psmooth values: "<< Psmooth << std::endl;
  NumericVector iniRp(1);
  iniRp[0]  = RcppDeepState_double();
  qs::c_qsave(iniRp,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolatePrecipitationPoints/inputs/iniRp.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "iniRp values: "<< iniRp << std::endl;
  NumericVector alpha_event(1);
  alpha_event[0]  = RcppDeepState_double();
  qs::c_qsave(alpha_event,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolatePrecipitationPoints/inputs/alpha_event.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "alpha_event values: "<< alpha_event << std::endl;
  NumericVector alpha_amount(1);
  alpha_amount[0]  = RcppDeepState_double();
  qs::c_qsave(alpha_amount,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolatePrecipitationPoints/inputs/alpha_amount.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "alpha_amount values: "<< alpha_amount << std::endl;
  IntegerVector N_event(1);
  N_event[0]  = RcppDeepState_int();
  qs::c_qsave(N_event,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolatePrecipitationPoints/inputs/N_event.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "N_event values: "<< N_event << std::endl;
  IntegerVector N_amount(1);
  N_amount[0]  = RcppDeepState_int();
  qs::c_qsave(N_amount,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolatePrecipitationPoints/inputs/N_amount.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "N_amount values: "<< N_amount << std::endl;
  IntegerVector iterations(1);
  iterations[0]  = RcppDeepState_int();
  qs::c_qsave(iterations,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolatePrecipitationPoints/inputs/iterations.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "iterations values: "<< iterations << std::endl;
  NumericVector popcrit(1);
  popcrit[0]  = RcppDeepState_double();
  qs::c_qsave(popcrit,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolatePrecipitationPoints/inputs/popcrit.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "popcrit values: "<< popcrit << std::endl;
  NumericVector fmax(1);
  fmax[0]  = RcppDeepState_double();
  qs::c_qsave(fmax,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/interpolatePrecipitationPoints/inputs/fmax.qs",
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
