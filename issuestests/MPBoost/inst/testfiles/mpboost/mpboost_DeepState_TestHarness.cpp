#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::IntegerVector mpboost(int N1, int N2, int MTI);

TEST(MPBoost_deepstate_test,mpboost_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector N1(1);
  N1[0]  = RcppDeepState_int();
  qs::c_qsave(N1,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/MPBoost/inst/testfiles/mpboost/inputs/N1.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "N1 values: "<< N1 << std::endl;
  IntegerVector N2(1);
  N2[0]  = RcppDeepState_int();
  qs::c_qsave(N2,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/MPBoost/inst/testfiles/mpboost/inputs/N2.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "N2 values: "<< N2 << std::endl;
  IntegerVector MTI(1);
  MTI[0]  = RcppDeepState_int();
  qs::c_qsave(MTI,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/MPBoost/inst/testfiles/mpboost/inputs/MTI.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "MTI values: "<< MTI << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    mpboost(N1[0],N2[0],MTI[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
