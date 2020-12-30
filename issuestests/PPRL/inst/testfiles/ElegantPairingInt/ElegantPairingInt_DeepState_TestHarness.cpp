#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

SEXP ElegantPairingInt(int int1, int int2);

TEST(PPRL_deepstate_test,ElegantPairingInt_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector int1(1);
  int1[0]  = RcppDeepState_int();
  qs::c_qsave(int1,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PPRL/inst/testfiles/ElegantPairingInt/inputs/int1.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "int1 values: "<< int1 << std::endl;
  IntegerVector int2(1);
  int2[0]  = RcppDeepState_int();
  qs::c_qsave(int2,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PPRL/inst/testfiles/ElegantPairingInt/inputs/int2.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "int2 values: "<< int2 << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    ElegantPairingInt(int1[0],int2[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
