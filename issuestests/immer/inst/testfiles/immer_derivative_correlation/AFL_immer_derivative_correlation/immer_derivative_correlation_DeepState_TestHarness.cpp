#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double immer_derivative_correlation(double cov12, double var1, double var2, double cov12_der, double var1_der, double var2_der);

TEST(immer_deepstate_test,immer_derivative_correlation_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector cov12(1);
  cov12[0]  = RcppDeepState_double();
  std::string cov12_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_derivative_correlation/AFL_immer_derivative_correlation/afl_inputs/" + std::to_string(t) + "_cov12.qs";
  qs::c_qsave(cov12,cov12_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "cov12 values: "<< cov12 << std::endl;
  NumericVector var1(1);
  var1[0]  = RcppDeepState_double();
  std::string var1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_derivative_correlation/AFL_immer_derivative_correlation/afl_inputs/" + std::to_string(t) + "_var1.qs";
  qs::c_qsave(var1,var1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "var1 values: "<< var1 << std::endl;
  NumericVector var2(1);
  var2[0]  = RcppDeepState_double();
  std::string var2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_derivative_correlation/AFL_immer_derivative_correlation/afl_inputs/" + std::to_string(t) + "_var2.qs";
  qs::c_qsave(var2,var2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "var2 values: "<< var2 << std::endl;
  NumericVector cov12_der(1);
  cov12_der[0]  = RcppDeepState_double();
  std::string cov12_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_derivative_correlation/AFL_immer_derivative_correlation/afl_inputs/" + std::to_string(t) + "_cov12.qs";
  std::string cov12_der_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_derivative_correlation/AFL_immer_derivative_correlation/afl_inputs/" + std::to_string(t) + "_cov12_der.qs";
  qs::c_qsave(cov12_der,cov12_der_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "cov12_der values: "<< cov12_der << std::endl;
  NumericVector var1_der(1);
  var1_der[0]  = RcppDeepState_double();
  std::string var1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_derivative_correlation/AFL_immer_derivative_correlation/afl_inputs/" + std::to_string(t) + "_var1.qs";
  std::string var1_der_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_derivative_correlation/AFL_immer_derivative_correlation/afl_inputs/" + std::to_string(t) + "_var1_der.qs";
  qs::c_qsave(var1_der,var1_der_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "var1_der values: "<< var1_der << std::endl;
  NumericVector var2_der(1);
  var2_der[0]  = RcppDeepState_double();
  std::string var2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_derivative_correlation/AFL_immer_derivative_correlation/afl_inputs/" + std::to_string(t) + "_var2.qs";
  std::string var2_der_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_derivative_correlation/AFL_immer_derivative_correlation/afl_inputs/" + std::to_string(t) + "_var2_der.qs";
  qs::c_qsave(var2_der,var2_der_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "var2_der values: "<< var2_der << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    immer_derivative_correlation(cov12[0],var1[0],var2[0],cov12_der[0],var1_der[0],var2_der[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
