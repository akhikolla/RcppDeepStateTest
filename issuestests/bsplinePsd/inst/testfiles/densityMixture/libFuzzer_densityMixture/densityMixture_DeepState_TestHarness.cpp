#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector densityMixture(NumericVector weights, NumericMatrix densities);

TEST(bsplinePsd_deepstate_test,densityMixture_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector weights  = RcppDeepState_NumericVector();
  std::string weights_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/bsplinePsd/inst/testfiles/densityMixture/libFuzzer_densityMixture/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_weights.qs";
  qs::c_qsave(weights,weights_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "weights values: "<< weights << std::endl;
  NumericMatrix densities  = RcppDeepState_NumericMatrix();
  std::string densities_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/bsplinePsd/inst/testfiles/densityMixture/libFuzzer_densityMixture/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_densities.qs";
  qs::c_qsave(densities,densities_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "densities values: "<< densities << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    densityMixture(weights,densities);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
