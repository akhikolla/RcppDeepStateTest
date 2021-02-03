#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix ryser_cpp(NumericMatrix A);

TEST(expperm_deepstate_test,ryser_cpp_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix A  = RcppDeepState_NumericMatrix();
  std::string A_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/expperm/inst/testfiles/ryser_cpp/AFL_ryser_cpp/afl_inputs/" + std::to_string(t) + "_A.qs";
  qs::c_qsave(A,A_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "A values: "<< A << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    ryser_cpp(A);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
