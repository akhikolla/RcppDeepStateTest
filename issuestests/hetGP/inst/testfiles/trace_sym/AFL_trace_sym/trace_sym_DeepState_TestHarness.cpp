#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double trace_sym(NumericMatrix A, NumericMatrix B);

TEST(hetGP_deepstate_test,trace_sym_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix A  = RcppDeepState_NumericMatrix();
  std::string A_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/hetGP/inst/testfiles/trace_sym/AFL_trace_sym/afl_inputs/" + std::to_string(t) + "_A.qs";
  qs::c_qsave(A,A_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "A values: "<< A << std::endl;
  NumericMatrix B  = RcppDeepState_NumericMatrix();
  std::string B_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/hetGP/inst/testfiles/trace_sym/AFL_trace_sym/afl_inputs/" + std::to_string(t) + "_B.qs";
  qs::c_qsave(B,B_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "B values: "<< B << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    trace_sym(A,B);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
