#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double calcRho_c(double x, double OcSBaserate, int testSetLength, double testSetBaserateInflation, int OcSLength, int replicates, double ScSKappaThreshold, double ScSKappaMin, double ScSPrecisionMin, double ScSPrecisionMax, NumericMatrix KPs);

TEST(rhoR_deepstate_test,calcRho_c_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector x(1);
  x[0]  = RcppDeepState_double();
  qs::c_qsave(x,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rhoR/inst/testfiles/calcRho_c/inputs/x.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector OcSBaserate(1);
  OcSBaserate[0]  = RcppDeepState_double();
  qs::c_qsave(OcSBaserate,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rhoR/inst/testfiles/calcRho_c/inputs/OcSBaserate.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "OcSBaserate values: "<< OcSBaserate << std::endl;
  IntegerVector testSetLength(1);
  testSetLength[0]  = RcppDeepState_int();
  qs::c_qsave(testSetLength,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rhoR/inst/testfiles/calcRho_c/inputs/testSetLength.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "testSetLength values: "<< testSetLength << std::endl;
  NumericVector testSetBaserateInflation(1);
  testSetBaserateInflation[0]  = RcppDeepState_double();
  qs::c_qsave(testSetBaserateInflation,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rhoR/inst/testfiles/calcRho_c/inputs/testSetBaserateInflation.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "testSetBaserateInflation values: "<< testSetBaserateInflation << std::endl;
  IntegerVector OcSLength(1);
  OcSLength[0]  = RcppDeepState_int();
  qs::c_qsave(OcSLength,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rhoR/inst/testfiles/calcRho_c/inputs/OcSLength.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "OcSLength values: "<< OcSLength << std::endl;
  IntegerVector replicates(1);
  replicates[0]  = RcppDeepState_int();
  qs::c_qsave(replicates,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rhoR/inst/testfiles/calcRho_c/inputs/replicates.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "replicates values: "<< replicates << std::endl;
  NumericVector ScSKappaThreshold(1);
  ScSKappaThreshold[0]  = RcppDeepState_double();
  qs::c_qsave(ScSKappaThreshold,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rhoR/inst/testfiles/calcRho_c/inputs/ScSKappaThreshold.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ScSKappaThreshold values: "<< ScSKappaThreshold << std::endl;
  NumericVector ScSKappaMin(1);
  ScSKappaMin[0]  = RcppDeepState_double();
  qs::c_qsave(ScSKappaMin,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rhoR/inst/testfiles/calcRho_c/inputs/ScSKappaMin.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ScSKappaMin values: "<< ScSKappaMin << std::endl;
  NumericVector ScSPrecisionMin(1);
  ScSPrecisionMin[0]  = RcppDeepState_double();
  qs::c_qsave(ScSPrecisionMin,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rhoR/inst/testfiles/calcRho_c/inputs/ScSPrecisionMin.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ScSPrecisionMin values: "<< ScSPrecisionMin << std::endl;
  NumericVector ScSPrecisionMax(1);
  ScSPrecisionMax[0]  = RcppDeepState_double();
  qs::c_qsave(ScSPrecisionMax,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rhoR/inst/testfiles/calcRho_c/inputs/ScSPrecisionMax.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ScSPrecisionMax values: "<< ScSPrecisionMax << std::endl;
  NumericMatrix KPs  = RcppDeepState_NumericMatrix();
  qs::c_qsave(KPs,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rhoR/inst/testfiles/calcRho_c/inputs/KPs.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "KPs values: "<< KPs << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    calcRho_c(x[0],OcSBaserate[0],testSetLength[0],testSetBaserateInflation[0],OcSLength[0],replicates[0],ScSKappaThreshold[0],ScSKappaMin[0],ScSPrecisionMin[0],ScSPrecisionMax[0],KPs);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
