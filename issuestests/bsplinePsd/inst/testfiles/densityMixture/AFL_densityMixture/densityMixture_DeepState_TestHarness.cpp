#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector densityMixture(NumericVector weights, NumericMatrix densities);

TEST(bsplinePsd_deepstate_test,densityMixture_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector weights  = RcppDeepState_NumericVector();
  std::string weights_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/bsplinePsd/inst/testfiles/densityMixture/AFL_densityMixture/afl_inputs/" + std::to_string(t) + "_weights.qs";
  qs::c_qsave(weights,weights_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "weights values: "<< weights << std::endl;
  NumericMatrix densities  = RcppDeepState_NumericMatrix();
  std::string densities_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/bsplinePsd/inst/testfiles/densityMixture/AFL_densityMixture/afl_inputs/" + std::to_string(t) + "_densities.qs";
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
