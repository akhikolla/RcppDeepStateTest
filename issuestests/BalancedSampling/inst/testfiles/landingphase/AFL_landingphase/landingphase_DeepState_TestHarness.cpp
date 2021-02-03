#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

IntegerVector landingphase(NumericVector prob, NumericVector probflight, NumericMatrix Xbal);

TEST(BalancedSampling_deepstate_test,landingphase_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector prob  = RcppDeepState_NumericVector();
  std::string prob_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BalancedSampling/inst/testfiles/landingphase/AFL_landingphase/afl_inputs/" + std::to_string(t) + "_prob.qs";
  qs::c_qsave(prob,prob_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "prob values: "<< prob << std::endl;
  NumericVector probflight  = RcppDeepState_NumericVector();
  std::string prob_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BalancedSampling/inst/testfiles/landingphase/AFL_landingphase/afl_inputs/" + std::to_string(t) + "_prob.qs";
  std::string probflight_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BalancedSampling/inst/testfiles/landingphase/AFL_landingphase/afl_inputs/" + std::to_string(t) + "_probflight.qs";
  qs::c_qsave(probflight,probflight_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "probflight values: "<< probflight << std::endl;
  NumericMatrix Xbal  = RcppDeepState_NumericMatrix();
  std::string Xbal_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BalancedSampling/inst/testfiles/landingphase/AFL_landingphase/afl_inputs/" + std::to_string(t) + "_Xbal.qs";
  qs::c_qsave(Xbal,Xbal_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Xbal values: "<< Xbal << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    landingphase(prob,probflight,Xbal);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
