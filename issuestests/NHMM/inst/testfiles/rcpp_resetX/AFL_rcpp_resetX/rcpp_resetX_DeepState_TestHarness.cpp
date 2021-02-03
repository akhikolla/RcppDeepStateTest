#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericMatrix rcpp_resetX(Rcpp::NumericMatrix XXf, Rcpp::NumericMatrix zbinf);

TEST(NHMM_deepstate_test,rcpp_resetX_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix XXf  = RcppDeepState_NumericMatrix();
  std::string XXf_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_resetX/AFL_rcpp_resetX/afl_inputs/" + std::to_string(t) + "_XXf.qs";
  qs::c_qsave(XXf,XXf_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "XXf values: "<< XXf << std::endl;
  NumericMatrix zbinf  = RcppDeepState_NumericMatrix();
  std::string zbinf_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_resetX/AFL_rcpp_resetX/afl_inputs/" + std::to_string(t) + "_zbinf.qs";
  qs::c_qsave(zbinf,zbinf_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "zbinf values: "<< zbinf << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    rcpp_resetX(XXf,zbinf);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
