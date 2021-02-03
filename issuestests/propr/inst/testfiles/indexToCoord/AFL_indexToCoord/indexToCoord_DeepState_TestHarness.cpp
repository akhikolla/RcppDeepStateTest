#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List indexToCoord(IntegerVector V, const int N);

TEST(propr_deepstate_test,indexToCoord_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector V  = RcppDeepState_IntegerVector();
  std::string V_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/propr/inst/testfiles/indexToCoord/AFL_indexToCoord/afl_inputs/" + std::to_string(t) + "_V.qs";
  qs::c_qsave(V,V_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "V values: "<< V << std::endl;
  IntegerVector N(1);
  N[0]  = RcppDeepState_int();
  std::string N_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/propr/inst/testfiles/indexToCoord/AFL_indexToCoord/afl_inputs/" + std::to_string(t) + "_N.qs";
  qs::c_qsave(N,N_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "N values: "<< N << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    indexToCoord(V,N[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
