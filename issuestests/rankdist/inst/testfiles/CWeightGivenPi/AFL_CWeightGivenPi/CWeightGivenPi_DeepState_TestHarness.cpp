#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector CWeightGivenPi(NumericVector r1, NumericVector r2);

TEST(rankdist_deepstate_test,CWeightGivenPi_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector r1  = RcppDeepState_NumericVector();
  std::string r1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rankdist/inst/testfiles/CWeightGivenPi/AFL_CWeightGivenPi/afl_inputs/" + std::to_string(t) + "_r1.qs";
  qs::c_qsave(r1,r1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "r1 values: "<< r1 << std::endl;
  NumericVector r2  = RcppDeepState_NumericVector();
  std::string r2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rankdist/inst/testfiles/CWeightGivenPi/AFL_CWeightGivenPi/afl_inputs/" + std::to_string(t) + "_r2.qs";
  qs::c_qsave(r2,r2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "r2 values: "<< r2 << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    CWeightGivenPi(r1,r2);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
