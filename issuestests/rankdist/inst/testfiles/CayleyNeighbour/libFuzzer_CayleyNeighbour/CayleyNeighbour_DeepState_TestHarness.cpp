#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix CayleyNeighbour(NumericVector rank);

TEST(rankdist_deepstate_test,CayleyNeighbour_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector rank  = RcppDeepState_NumericVector();
  std::string rank_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rankdist/inst/testfiles/CayleyNeighbour/libFuzzer_CayleyNeighbour/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_rank.qs";
  qs::c_qsave(rank,rank_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "rank values: "<< rank << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    CayleyNeighbour(rank);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
