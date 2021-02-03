#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix KendallNeighbour(NumericVector rank);

TEST(rankdist_deepstate_test,KendallNeighbour_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector rank  = RcppDeepState_NumericVector();
  std::string rank_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rankdist/inst/testfiles/KendallNeighbour/AFL_KendallNeighbour/afl_inputs/" + std::to_string(t) + "_rank.qs";
  qs::c_qsave(rank,rank_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "rank values: "<< rank << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    KendallNeighbour(rank);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
