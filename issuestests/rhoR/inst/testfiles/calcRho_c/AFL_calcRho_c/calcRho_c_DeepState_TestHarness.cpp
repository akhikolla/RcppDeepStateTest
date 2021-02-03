#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double calcRho_c(double x, double OcSBaserate, int testSetLength, double testSetBaserateInflation, int OcSLength, int replicates, double ScSKappaThreshold, double ScSKappaMin, double ScSPrecisionMin, double ScSPrecisionMax, NumericMatrix KPs);

TEST(rhoR_deepstate_test,calcRho_c_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector x(1);
  x[0]  = RcppDeepState_double();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rhoR/inst/testfiles/calcRho_c/AFL_calcRho_c/afl_inputs/" + std::to_string(t) + "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector OcSBaserate(1);
  OcSBaserate[0]  = RcppDeepState_double();
  std::string OcSBaserate_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rhoR/inst/testfiles/calcRho_c/AFL_calcRho_c/afl_inputs/" + std::to_string(t) + "_OcSBaserate.qs";
  qs::c_qsave(OcSBaserate,OcSBaserate_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "OcSBaserate values: "<< OcSBaserate << std::endl;
  IntegerVector testSetLength(1);
  testSetLength[0]  = RcppDeepState_int();
  std::string testSetLength_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rhoR/inst/testfiles/calcRho_c/AFL_calcRho_c/afl_inputs/" + std::to_string(t) + "_testSetLength.qs";
  qs::c_qsave(testSetLength,testSetLength_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "testSetLength values: "<< testSetLength << std::endl;
  NumericVector testSetBaserateInflation(1);
  testSetBaserateInflation[0]  = RcppDeepState_double();
  std::string testSetBaserateInflation_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rhoR/inst/testfiles/calcRho_c/AFL_calcRho_c/afl_inputs/" + std::to_string(t) + "_testSetBaserateInflation.qs";
  qs::c_qsave(testSetBaserateInflation,testSetBaserateInflation_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "testSetBaserateInflation values: "<< testSetBaserateInflation << std::endl;
  IntegerVector OcSLength(1);
  OcSLength[0]  = RcppDeepState_int();
  std::string OcSLength_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rhoR/inst/testfiles/calcRho_c/AFL_calcRho_c/afl_inputs/" + std::to_string(t) + "_OcSLength.qs";
  qs::c_qsave(OcSLength,OcSLength_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "OcSLength values: "<< OcSLength << std::endl;
  IntegerVector replicates(1);
  replicates[0]  = RcppDeepState_int();
  std::string replicates_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rhoR/inst/testfiles/calcRho_c/AFL_calcRho_c/afl_inputs/" + std::to_string(t) + "_replicates.qs";
  qs::c_qsave(replicates,replicates_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "replicates values: "<< replicates << std::endl;
  NumericVector ScSKappaThreshold(1);
  ScSKappaThreshold[0]  = RcppDeepState_double();
  std::string ScSKappaThreshold_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rhoR/inst/testfiles/calcRho_c/AFL_calcRho_c/afl_inputs/" + std::to_string(t) + "_ScSKappaThreshold.qs";
  qs::c_qsave(ScSKappaThreshold,ScSKappaThreshold_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ScSKappaThreshold values: "<< ScSKappaThreshold << std::endl;
  NumericVector ScSKappaMin(1);
  ScSKappaMin[0]  = RcppDeepState_double();
  std::string ScSKappaMin_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rhoR/inst/testfiles/calcRho_c/AFL_calcRho_c/afl_inputs/" + std::to_string(t) + "_ScSKappaMin.qs";
  qs::c_qsave(ScSKappaMin,ScSKappaMin_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ScSKappaMin values: "<< ScSKappaMin << std::endl;
  NumericVector ScSPrecisionMin(1);
  ScSPrecisionMin[0]  = RcppDeepState_double();
  std::string ScSPrecisionMin_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rhoR/inst/testfiles/calcRho_c/AFL_calcRho_c/afl_inputs/" + std::to_string(t) + "_ScSPrecisionMin.qs";
  qs::c_qsave(ScSPrecisionMin,ScSPrecisionMin_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ScSPrecisionMin values: "<< ScSPrecisionMin << std::endl;
  NumericVector ScSPrecisionMax(1);
  ScSPrecisionMax[0]  = RcppDeepState_double();
  std::string ScSPrecisionMax_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rhoR/inst/testfiles/calcRho_c/AFL_calcRho_c/afl_inputs/" + std::to_string(t) + "_ScSPrecisionMax.qs";
  qs::c_qsave(ScSPrecisionMax,ScSPrecisionMax_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ScSPrecisionMax values: "<< ScSPrecisionMax << std::endl;
  NumericMatrix KPs  = RcppDeepState_NumericMatrix();
  std::string KPs_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rhoR/inst/testfiles/calcRho_c/AFL_calcRho_c/afl_inputs/" + std::to_string(t) + "_KPs.qs";
  qs::c_qsave(KPs,KPs_t,
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
