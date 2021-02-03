#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix d_matern5_2_1args_kthetag(NumericMatrix X1, double kt);

TEST(hetGP_deepstate_test,d_matern5_2_1args_kthetag_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix X1  = RcppDeepState_NumericMatrix();
  std::string X1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/hetGP/inst/testfiles/d_matern5_2_1args_kthetag/AFL_d_matern5_2_1args_kthetag/afl_inputs/" + std::to_string(t) + "_X1.qs";
  qs::c_qsave(X1,X1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "X1 values: "<< X1 << std::endl;
  NumericVector kt(1);
  kt[0]  = RcppDeepState_double();
  std::string kt_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/hetGP/inst/testfiles/d_matern5_2_1args_kthetag/AFL_d_matern5_2_1args_kthetag/afl_inputs/" + std::to_string(t) + "_kt.qs";
  qs::c_qsave(kt,kt_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "kt values: "<< kt << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    d_matern5_2_1args_kthetag(X1,kt[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
