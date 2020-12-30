#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

IntegerVector scps_coord(NumericVector prob, NumericMatrix x, NumericVector rand);

TEST(BalancedSampling_deepstate_test,scps_coord_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector prob  = RcppDeepState_NumericVector();
  qs::c_qsave(prob,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BalancedSampling/inst/testfiles/scps_coord/inputs/prob.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "prob values: "<< prob << std::endl;
  NumericMatrix x  = RcppDeepState_NumericMatrix();
  qs::c_qsave(x,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BalancedSampling/inst/testfiles/scps_coord/inputs/x.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector rand  = RcppDeepState_NumericVector();
  qs::c_qsave(rand,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BalancedSampling/inst/testfiles/scps_coord/inputs/rand.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "rand values: "<< rand << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    scps_coord(prob,x,rand);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
