#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List indexToCoord(IntegerVector V, const int N);

TEST(propr_deepstate_test,indexToCoord_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector V  = RcppDeepState_IntegerVector();
  qs::c_qsave(V,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/propr/inst/testfiles/indexToCoord/inputs/V.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "V values: "<< V << std::endl;
  IntegerVector N(1);
  N[0]  = RcppDeepState_int();
  qs::c_qsave(N,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/propr/inst/testfiles/indexToCoord/inputs/N.qs",
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
