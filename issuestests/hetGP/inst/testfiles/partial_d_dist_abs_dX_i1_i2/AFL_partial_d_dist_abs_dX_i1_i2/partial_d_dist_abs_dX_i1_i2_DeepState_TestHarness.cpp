#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix partial_d_dist_abs_dX_i1_i2(NumericMatrix X1, int i1, int i2);

TEST(hetGP_deepstate_test,partial_d_dist_abs_dX_i1_i2_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix X1  = RcppDeepState_NumericMatrix();
  std::string X1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/hetGP/inst/testfiles/partial_d_dist_abs_dX_i1_i2/AFL_partial_d_dist_abs_dX_i1_i2/afl_inputs/" + std::to_string(t) + "_X1.qs";
  qs::c_qsave(X1,X1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "X1 values: "<< X1 << std::endl;
  IntegerVector i1(1);
  i1[0]  = RcppDeepState_int();
  std::string i1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/hetGP/inst/testfiles/partial_d_dist_abs_dX_i1_i2/AFL_partial_d_dist_abs_dX_i1_i2/afl_inputs/" + std::to_string(t) + "_i1.qs";
  qs::c_qsave(i1,i1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "i1 values: "<< i1 << std::endl;
  IntegerVector i2(1);
  i2[0]  = RcppDeepState_int();
  std::string i2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/hetGP/inst/testfiles/partial_d_dist_abs_dX_i1_i2/AFL_partial_d_dist_abs_dX_i1_i2/afl_inputs/" + std::to_string(t) + "_i2.qs";
  qs::c_qsave(i2,i2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "i2 values: "<< i2 << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    partial_d_dist_abs_dX_i1_i2(X1,i1[0],i2[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
