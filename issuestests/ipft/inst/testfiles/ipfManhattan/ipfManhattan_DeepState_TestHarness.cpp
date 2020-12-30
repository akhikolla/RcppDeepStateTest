#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix ipfManhattan(NumericMatrix train, NumericMatrix test);

TEST(ipft_deepstate_test,ipfManhattan_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix train  = RcppDeepState_NumericMatrix();
  qs::c_qsave(train,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ipft/inst/testfiles/ipfManhattan/inputs/train.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "train values: "<< train << std::endl;
  NumericMatrix test  = RcppDeepState_NumericMatrix();
  qs::c_qsave(test,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ipft/inst/testfiles/ipfManhattan/inputs/test.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "test values: "<< test << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    ipfManhattan(train,test);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
