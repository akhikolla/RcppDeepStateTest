#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector lcubeflightphase(NumericVector prob, NumericMatrix Xspread, NumericMatrix Xbal);

TEST(BalancedSampling_deepstate_test,lcubeflightphase_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector prob  = RcppDeepState_NumericVector();
  std::string prob_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BalancedSampling/inst/testfiles/lcubeflightphase/AFL_lcubeflightphase/afl_inputs/" + std::to_string(t) + "_prob.qs";
  qs::c_qsave(prob,prob_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "prob values: "<< prob << std::endl;
  NumericMatrix Xspread  = RcppDeepState_NumericMatrix();
  std::string Xspread_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BalancedSampling/inst/testfiles/lcubeflightphase/AFL_lcubeflightphase/afl_inputs/" + std::to_string(t) + "_Xspread.qs";
  qs::c_qsave(Xspread,Xspread_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Xspread values: "<< Xspread << std::endl;
  NumericMatrix Xbal  = RcppDeepState_NumericMatrix();
  std::string Xbal_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BalancedSampling/inst/testfiles/lcubeflightphase/AFL_lcubeflightphase/afl_inputs/" + std::to_string(t) + "_Xbal.qs";
  qs::c_qsave(Xbal,Xbal_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Xbal values: "<< Xbal << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    lcubeflightphase(prob,Xspread,Xbal);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
