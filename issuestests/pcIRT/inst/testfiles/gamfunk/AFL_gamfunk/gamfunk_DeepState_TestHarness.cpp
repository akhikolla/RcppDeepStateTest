#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector gamfunk(NumericVector epsmat, NumericMatrix gammat);

TEST(pcIRT_deepstate_test,gamfunk_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector epsmat  = RcppDeepState_NumericVector();
  std::string epsmat_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/pcIRT/inst/testfiles/gamfunk/AFL_gamfunk/afl_inputs/" + std::to_string(t) + "_epsmat.qs";
  qs::c_qsave(epsmat,epsmat_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "epsmat values: "<< epsmat << std::endl;
  NumericMatrix gammat  = RcppDeepState_NumericMatrix();
  std::string gammat_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/pcIRT/inst/testfiles/gamfunk/AFL_gamfunk/afl_inputs/" + std::to_string(t) + "_gammat.qs";
  qs::c_qsave(gammat,gammat_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "gammat values: "<< gammat << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    gamfunk(epsmat,gammat);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
