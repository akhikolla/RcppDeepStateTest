#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

SEXP mkr2X(NumericMatrix Y, NumericMatrix K1, NumericMatrix K2);

TEST(NAM_deepstate_test,mkr2X_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix Y  = RcppDeepState_NumericMatrix();
  qs::c_qsave(Y,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/mkr2X/inputs/Y.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Y values: "<< Y << std::endl;
  NumericMatrix K1  = RcppDeepState_NumericMatrix();
  qs::c_qsave(K1,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/mkr2X/inputs/K1.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "K1 values: "<< K1 << std::endl;
  NumericMatrix K2  = RcppDeepState_NumericMatrix();
  qs::c_qsave(K2,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/mkr2X/inputs/K2.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "K2 values: "<< K2 << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    mkr2X(Y,K1,K2);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
