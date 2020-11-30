#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector potentialRadiationPoints(double latrad, NumericVector slorad, NumericVector asprad, int J);

TEST(meteoland_deepstate_test,potentialRadiationPoints_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector latrad(1);
  latrad[0]  = RcppDeepState_double();
  qs::c_qsave(latrad,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/potentialRadiationPoints/inputs/latrad.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "latrad values: "<< latrad << std::endl;
  NumericVector slorad  = RcppDeepState_NumericVector();
  qs::c_qsave(slorad,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/potentialRadiationPoints/inputs/slorad.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "slorad values: "<< slorad << std::endl;
  NumericVector asprad  = RcppDeepState_NumericVector();
  qs::c_qsave(asprad,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/potentialRadiationPoints/inputs/asprad.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "asprad values: "<< asprad << std::endl;
  IntegerVector J(1);
  J[0]  = RcppDeepState_int();
  qs::c_qsave(J,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/potentialRadiationPoints/inputs/J.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "J values: "<< J << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    potentialRadiationPoints(latrad[0],slorad,asprad,J[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
