#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double TrapezoidalArea(NumericVector noise, int n_noise, NumericVector signal, int n_signal);

TEST(RJafroc_deepstate_test,TrapezoidalArea_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector noise  = RcppDeepState_NumericVector();
  qs::c_qsave(noise,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/TrapezoidalArea/inputs/noise.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "noise values: "<< noise << std::endl;
  IntegerVector n_noise(1);
  n_noise[0]  = RcppDeepState_int();
  qs::c_qsave(n_noise,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/TrapezoidalArea/inputs/n_noise.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n_noise values: "<< n_noise << std::endl;
  NumericVector signal  = RcppDeepState_NumericVector();
  qs::c_qsave(signal,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/TrapezoidalArea/inputs/signal.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "signal values: "<< signal << std::endl;
  IntegerVector n_signal(1);
  n_signal[0]  = RcppDeepState_int();
  qs::c_qsave(n_signal,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/TrapezoidalArea/inputs/n_signal.qs",
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
