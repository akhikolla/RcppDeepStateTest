#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List StdVar_C_NA(NumericMatrix MyMat);

TEST(BoostMLR_deepstate_test,StdVar_C_NA_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix MyMat  = RcppDeepState_NumericMatrix();
  qs::c_qsave(MyMat,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BoostMLR/inst/testfiles/StdVar_C_NA/inputs/MyMat.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "MyMat values: "<< MyMat << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    StdVar_C_NA(MyMat);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
