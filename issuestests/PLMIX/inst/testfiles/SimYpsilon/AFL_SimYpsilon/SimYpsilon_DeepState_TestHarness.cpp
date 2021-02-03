#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix SimYpsilon(NumericMatrix rate, NumericVector n_rank);

TEST(PLMIX_deepstate_test,SimYpsilon_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix rate  = RcppDeepState_NumericMatrix();
  std::string rate_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/SimYpsilon/AFL_SimYpsilon/afl_inputs/" + std::to_string(t) + "_rate.qs";
  qs::c_qsave(rate,rate_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "rate values: "<< rate << std::endl;
  NumericVector n_rank  = RcppDeepState_NumericVector();
  std::string n_rank_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/SimYpsilon/AFL_SimYpsilon/afl_inputs/" + std::to_string(t) + "_n_rank.qs";
  qs::c_qsave(n_rank,n_rank_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n_rank values: "<< n_rank << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    SimYpsilon(rate,n_rank);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
