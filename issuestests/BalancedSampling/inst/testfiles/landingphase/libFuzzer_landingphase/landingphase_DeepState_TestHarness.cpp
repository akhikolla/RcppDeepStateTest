#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

IntegerVector landingphase(NumericVector prob, NumericVector probflight, NumericMatrix Xbal);

TEST(BalancedSampling_deepstate_test,landingphase_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector prob  = RcppDeepState_NumericVector();
  std::string prob_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BalancedSampling/inst/testfiles/landingphase/libFuzzer_landingphase/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_prob.qs";
  qs::c_qsave(prob,prob_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "prob values: "<< prob << std::endl;
  NumericVector probflight  = RcppDeepState_NumericVector();
  std::string prob_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BalancedSampling/inst/testfiles/landingphase/libFuzzer_landingphase/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_prob.qs";
  std::string probflight_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BalancedSampling/inst/testfiles/landingphase/libFuzzer_landingphase/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_probflight.qs";
  qs::c_qsave(probflight,probflight_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "probflight values: "<< probflight << std::endl;
  NumericMatrix Xbal  = RcppDeepState_NumericMatrix();
  std::string Xbal_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BalancedSampling/inst/testfiles/landingphase/libFuzzer_landingphase/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Xbal.qs";
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
