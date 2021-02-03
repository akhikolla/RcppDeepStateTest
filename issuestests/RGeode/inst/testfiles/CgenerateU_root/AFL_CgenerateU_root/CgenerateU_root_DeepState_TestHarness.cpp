#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector CgenerateU_root(NumericVector prodTau, int N, double SIGMAS, NumericMatrix Z);

TEST(RGeode_deepstate_test,CgenerateU_root_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector prodTau  = RcppDeepState_NumericVector();
  std::string prodTau_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RGeode/inst/testfiles/CgenerateU_root/AFL_CgenerateU_root/afl_inputs/" + std::to_string(t) + "_prodTau.qs";
  qs::c_qsave(prodTau,prodTau_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "prodTau values: "<< prodTau << std::endl;
  IntegerVector N(1);
  N[0]  = RcppDeepState_int();
  std::string N_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RGeode/inst/testfiles/CgenerateU_root/AFL_CgenerateU_root/afl_inputs/" + std::to_string(t) + "_N.qs";
  qs::c_qsave(N,N_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "N values: "<< N << std::endl;
  NumericVector SIGMAS(1);
  SIGMAS[0]  = RcppDeepState_double();
  std::string SIGMAS_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RGeode/inst/testfiles/CgenerateU_root/AFL_CgenerateU_root/afl_inputs/" + std::to_string(t) + "_SIGMAS.qs";
  qs::c_qsave(SIGMAS,SIGMAS_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "SIGMAS values: "<< SIGMAS << std::endl;
  NumericMatrix Z  = RcppDeepState_NumericMatrix();
  std::string Z_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RGeode/inst/testfiles/CgenerateU_root/AFL_CgenerateU_root/afl_inputs/" + std::to_string(t) + "_Z.qs";
  qs::c_qsave(Z,Z_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Z values: "<< Z << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    CgenerateU_root(prodTau,N[0],SIGMAS[0],Z);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
