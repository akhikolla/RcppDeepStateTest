#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double TrapezoidalArea(NumericVector noise, int n_noise, NumericVector signal, int n_signal);

TEST(RJafroc_deepstate_test,TrapezoidalArea_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector noise  = RcppDeepState_NumericVector();
  std::string noise_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/TrapezoidalArea/AFL_TrapezoidalArea/afl_inputs/" + std::to_string(t) + "_noise.qs";
  qs::c_qsave(noise,noise_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "noise values: "<< noise << std::endl;
  IntegerVector n_noise(1);
  n_noise[0]  = RcppDeepState_int();
  std::string n_noise_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/TrapezoidalArea/AFL_TrapezoidalArea/afl_inputs/" + std::to_string(t) + "_n_noise.qs";
  qs::c_qsave(n_noise,n_noise_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n_noise values: "<< n_noise << std::endl;
  NumericVector signal  = RcppDeepState_NumericVector();
  std::string signal_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/TrapezoidalArea/AFL_TrapezoidalArea/afl_inputs/" + std::to_string(t) + "_signal.qs";
  qs::c_qsave(signal,signal_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "signal values: "<< signal << std::endl;
  IntegerVector n_signal(1);
  n_signal[0]  = RcppDeepState_int();
  std::string n_signal_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/TrapezoidalArea/AFL_TrapezoidalArea/afl_inputs/" + std::to_string(t) + "_n_signal.qs";
  qs::c_qsave(n_signal,n_signal_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n_signal values: "<< n_signal << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    TrapezoidalArea(noise,n_noise[0],signal,n_signal[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
