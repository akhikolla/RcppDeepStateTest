#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

IntegerVector scps_coord(NumericVector prob, NumericMatrix x, NumericVector rand);

TEST(BalancedSampling_deepstate_test,scps_coord_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector prob  = RcppDeepState_NumericVector();
  std::string prob_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BalancedSampling/inst/testfiles/scps_coord/AFL_scps_coord/afl_inputs/" + std::to_string(t) + "_prob.qs";
  qs::c_qsave(prob,prob_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "prob values: "<< prob << std::endl;
  NumericMatrix x  = RcppDeepState_NumericMatrix();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BalancedSampling/inst/testfiles/scps_coord/AFL_scps_coord/afl_inputs/" + std::to_string(t) + "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector rand  = RcppDeepState_NumericVector();
  std::string rand_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BalancedSampling/inst/testfiles/scps_coord/AFL_scps_coord/afl_inputs/" + std::to_string(t) + "_rand.qs";
  qs::c_qsave(rand,rand_t,
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
