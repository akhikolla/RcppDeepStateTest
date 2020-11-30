#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List credsetmat(NumericMatrix pp, NumericVector iCV, double threshold);

TEST(corrcoverage_deepstate_test,credsetmat_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix pp  = RcppDeepState_NumericMatrix();
  std::string pp_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/corrcoverage/inst/testfiles/credsetmat/AFL_credsetmat/afl_inputs/" + std::to_string(t) + "_pp.qs";
  qs::c_qsave(pp,pp_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pp values: "<< pp << std::endl;
  NumericVector iCV  = RcppDeepState_NumericVector();
  std::string iCV_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/corrcoverage/inst/testfiles/credsetmat/AFL_credsetmat/afl_inputs/" + std::to_string(t) + "_iCV.qs";
  qs::c_qsave(iCV,iCV_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "iCV values: "<< iCV << std::endl;
  NumericVector threshold(1);
  threshold[0]  = RcppDeepState_double();
  std::string threshold_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/corrcoverage/inst/testfiles/credsetmat/AFL_credsetmat/afl_inputs/" + std::to_string(t) + "_threshold.qs";
  qs::c_qsave(threshold,threshold_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "threshold values: "<< threshold << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    credsetmat(pp,iCV,threshold[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
