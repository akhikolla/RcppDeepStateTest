#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector Cgammatr(int n, double A, double B, NumericVector range);

TEST(RGeode_deepstate_test,Cgammatr_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector n(1);
  n[0]  = RcppDeepState_int();
  std::string n_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RGeode/inst/testfiles/Cgammatr/AFL_Cgammatr/afl_inputs/" + std::to_string(t) + "_n.qs";
  qs::c_qsave(n,n_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n values: "<< n << std::endl;
  NumericVector A(1);
  A[0]  = RcppDeepState_double();
  std::string A_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RGeode/inst/testfiles/Cgammatr/AFL_Cgammatr/afl_inputs/" + std::to_string(t) + "_A.qs";
  qs::c_qsave(A,A_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "A values: "<< A << std::endl;
  NumericVector B(1);
  B[0]  = RcppDeepState_double();
  std::string B_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RGeode/inst/testfiles/Cgammatr/AFL_Cgammatr/afl_inputs/" + std::to_string(t) + "_B.qs";
  qs::c_qsave(B,B_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "B values: "<< B << std::endl;
  NumericVector range  = RcppDeepState_NumericVector();
  std::string range_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RGeode/inst/testfiles/Cgammatr/AFL_Cgammatr/afl_inputs/" + std::to_string(t) + "_range.qs";
  qs::c_qsave(range,range_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "range values: "<< range << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    Cgammatr(n[0],A[0],B[0],range);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
