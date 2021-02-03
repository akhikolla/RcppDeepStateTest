#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List vmcos_var_corr_anltc(double k1, double k2, double k3);

TEST(BAMBI_deepstate_test,vmcos_var_corr_anltc_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector k1(1);
  k1[0]  = RcppDeepState_double();
  std::string k1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/vmcos_var_corr_anltc/AFL_vmcos_var_corr_anltc/afl_inputs/" + std::to_string(t) + "_k1.qs";
  qs::c_qsave(k1,k1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "k1 values: "<< k1 << std::endl;
  NumericVector k2(1);
  k2[0]  = RcppDeepState_double();
  std::string k2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/vmcos_var_corr_anltc/AFL_vmcos_var_corr_anltc/afl_inputs/" + std::to_string(t) + "_k2.qs";
  qs::c_qsave(k2,k2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "k2 values: "<< k2 << std::endl;
  NumericVector k3(1);
  k3[0]  = RcppDeepState_double();
  std::string k3_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/vmcos_var_corr_anltc/AFL_vmcos_var_corr_anltc/afl_inputs/" + std::to_string(t) + "_k3.qs";
  qs::c_qsave(k3,k3_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "k3 values: "<< k3 << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    vmcos_var_corr_anltc(k1[0],k2[0],k3[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
