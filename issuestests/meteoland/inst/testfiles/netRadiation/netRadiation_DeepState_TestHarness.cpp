#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double netRadiation(double solarConstant, double latrad, double elevation, double slorad, double asprad, double delta, double vpa, double tmin, double tmax, double R_s, double alpha);

TEST(meteoland_deepstate_test,netRadiation_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector solarConstant(1);
  solarConstant[0]  = RcppDeepState_double();
  qs::c_qsave(solarConstant,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/netRadiation/inputs/solarConstant.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "solarConstant values: "<< solarConstant << std::endl;
  NumericVector latrad(1);
  latrad[0]  = RcppDeepState_double();
  qs::c_qsave(latrad,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/netRadiation/inputs/latrad.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "latrad values: "<< latrad << std::endl;
  NumericVector elevation(1);
  elevation[0]  = RcppDeepState_double();
  qs::c_qsave(elevation,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/netRadiation/inputs/elevation.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "elevation values: "<< elevation << std::endl;
  NumericVector slorad(1);
  slorad[0]  = RcppDeepState_double();
  qs::c_qsave(slorad,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/netRadiation/inputs/slorad.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "slorad values: "<< slorad << std::endl;
  NumericVector asprad(1);
  asprad[0]  = RcppDeepState_double();
  qs::c_qsave(asprad,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/netRadiation/inputs/asprad.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "asprad values: "<< asprad << std::endl;
  NumericVector delta(1);
  delta[0]  = RcppDeepState_double();
  qs::c_qsave(delta,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/netRadiation/inputs/delta.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "delta values: "<< delta << std::endl;
  NumericVector vpa(1);
  vpa[0]  = RcppDeepState_double();
  qs::c_qsave(vpa,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/netRadiation/inputs/vpa.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "vpa values: "<< vpa << std::endl;
  NumericVector tmin(1);
  tmin[0]  = RcppDeepState_double();
  qs::c_qsave(tmin,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/netRadiation/inputs/tmin.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tmin values: "<< tmin << std::endl;
  NumericVector tmax(1);
  tmax[0]  = RcppDeepState_double();
  qs::c_qsave(tmax,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/netRadiation/inputs/tmax.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tmax values: "<< tmax << std::endl;
  NumericVector R_s(1);
  R_s[0]  = RcppDeepState_double();
  qs::c_qsave(R_s,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/netRadiation/inputs/R_s.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "R_s values: "<< R_s << std::endl;
  NumericVector alpha(1);
  alpha[0]  = RcppDeepState_double();
  qs::c_qsave(alpha,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/netRadiation/inputs/alpha.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "alpha values: "<< alpha << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    netRadiation(solarConstant[0],latrad[0],elevation[0],slorad[0],asprad[0],delta[0],vpa[0],tmin[0],tmax[0],R_s[0],alpha[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
