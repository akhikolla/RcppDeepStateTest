#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

IntegerMatrix kruskal(NumericMatrix W);

TEST(BNSL_deepstate_test,kruskal_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix W  = RcppDeepState_NumericMatrix();
  qs::c_qsave(W,"/home/akhila/RcppDeepStateTest/BNSL/inst/testfiles/kruskal/inputs/W.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "W values: "<< W << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    kruskal(W);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
