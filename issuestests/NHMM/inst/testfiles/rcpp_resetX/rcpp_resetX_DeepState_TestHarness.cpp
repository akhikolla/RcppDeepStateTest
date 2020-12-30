#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericMatrix rcpp_resetX(Rcpp::NumericMatrix XXf, Rcpp::NumericMatrix zbinf);

TEST(NHMM_deepstate_test,rcpp_resetX_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix XXf  = RcppDeepState_NumericMatrix();
  qs::c_qsave(XXf,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_resetX/inputs/XXf.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "XXf values: "<< XXf << std::endl;
  NumericMatrix zbinf  = RcppDeepState_NumericMatrix();
  qs::c_qsave(zbinf,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_resetX/inputs/zbinf.qs",
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
