#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector densityMixture(NumericVector weights, NumericMatrix densities);

TEST(bsplinePsd_deepstate_test,densityMixture_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector weights  = RcppDeepState_NumericVector();
  qs::c_qsave(weights,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/bsplinePsd/inst/testfiles/densityMixture/inputs/weights.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "weights values: "<< weights << std::endl;
  NumericMatrix densities  = RcppDeepState_NumericMatrix();
  qs::c_qsave(densities,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/bsplinePsd/inst/testfiles/densityMixture/inputs/densities.qs",
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
