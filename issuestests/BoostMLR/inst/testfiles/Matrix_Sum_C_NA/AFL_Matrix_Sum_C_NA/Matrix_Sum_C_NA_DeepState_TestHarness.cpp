#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix Matrix_Sum_C_NA(NumericMatrix x, NumericMatrix y);

TEST(BoostMLR_deepstate_test,Matrix_Sum_C_NA_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix x  = RcppDeepState_NumericMatrix();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BoostMLR/inst/testfiles/Matrix_Sum_C_NA/AFL_Matrix_Sum_C_NA/afl_inputs/" + std::to_string(t) + "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericMatrix y  = RcppDeepState_NumericMatrix();
  std::string y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BoostMLR/inst/testfiles/Matrix_Sum_C_NA/AFL_Matrix_Sum_C_NA/afl_inputs/" + std::to_string(t) + "_y.qs";
  qs::c_qsave(y,y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    Matrix_Sum_C_NA(x,y);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
