#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double skyLongwaveRadiation(double Tair, double vpa, double c);

TEST(meteoland_deepstate_test,skyLongwaveRadiation_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector Tair(1);
  Tair[0]  = RcppDeepState_double();
  qs::c_qsave(Tair,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/skyLongwaveRadiation/inputs/Tair.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Tair values: "<< Tair << std::endl;
  NumericVector vpa(1);
  vpa[0]  = RcppDeepState_double();
  qs::c_qsave(vpa,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/skyLongwaveRadiation/inputs/vpa.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "vpa values: "<< vpa << std::endl;
  NumericVector c(1);
  c[0]  = RcppDeepState_double();
  qs::c_qsave(c,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/skyLongwaveRadiation/inputs/c.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "c values: "<< c << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    skyLongwaveRadiation(Tair[0],vpa[0],c[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
