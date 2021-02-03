#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix sink_cpp(NumericMatrix A, int maxit);

TEST(expperm_deepstate_test,sink_cpp_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix A  = RcppDeepState_NumericMatrix();
  std::string A_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/expperm/inst/testfiles/sink_cpp/libFuzzer_sink_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_A.qs";
  qs::c_qsave(A,A_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "A values: "<< A << std::endl;
  IntegerVector maxit(1);
  maxit[0]  = RcppDeepState_int();
  std::string maxit_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/expperm/inst/testfiles/sink_cpp/libFuzzer_sink_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_maxit.qs";
  qs::c_qsave(maxit,maxit_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "maxit values: "<< maxit << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    sink_cpp(A,maxit[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
