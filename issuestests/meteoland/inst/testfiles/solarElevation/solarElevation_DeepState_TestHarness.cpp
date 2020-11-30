#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double solarElevation(double latrad, double delta, double hrad);

TEST(meteoland_deepstate_test,solarElevation_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector latrad(1);
  latrad[0]  = RcppDeepState_double();
  qs::c_qsave(latrad,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/solarElevation/inputs/latrad.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "latrad values: "<< latrad << std::endl;
  NumericVector delta(1);
  delta[0]  = RcppDeepState_double();
  qs::c_qsave(delta,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/solarElevation/inputs/delta.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "delta values: "<< delta << std::endl;
  NumericVector hrad(1);
  hrad[0]  = RcppDeepState_double();
  qs::c_qsave(hrad,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/solarElevation/inputs/hrad.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "hrad values: "<< hrad << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    solarElevation(latrad[0],delta[0],hrad[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
