#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double scorefun0(NumericVector x, NumericVector parm, NumericMatrix Dmat);

TEST(icRSF_deepstate_test,scorefun0_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icRSF/inst/testfiles/scorefun0/AFL_scorefun0/afl_inputs/" + std::to_string(t) + "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector parm  = RcppDeepState_NumericVector();
  std::string parm_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icRSF/inst/testfiles/scorefun0/AFL_scorefun0/afl_inputs/" + std::to_string(t) + "_parm.qs";
  qs::c_qsave(parm,parm_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "parm values: "<< parm << std::endl;
  NumericMatrix Dmat  = RcppDeepState_NumericMatrix();
  std::string Dmat_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icRSF/inst/testfiles/scorefun0/AFL_scorefun0/afl_inputs/" + std::to_string(t) + "_Dmat.qs";
  qs::c_qsave(Dmat,Dmat_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Dmat values: "<< Dmat << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    scorefun0(x,parm,Dmat);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
