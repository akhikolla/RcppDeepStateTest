#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

void SAMP(NumericMatrix C, NumericVector g, NumericVector r, int N, double Ve);

TEST(NAM_deepstate_test,SAMP_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix C  = RcppDeepState_NumericMatrix();
  std::string C_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/SAMP/AFL_SAMP/afl_inputs/" + std::to_string(t) + "_C.qs";
  qs::c_qsave(C,C_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "C values: "<< C << std::endl;
  NumericVector g  = RcppDeepState_NumericVector();
  std::string g_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/SAMP/AFL_SAMP/afl_inputs/" + std::to_string(t) + "_g.qs";
  qs::c_qsave(g,g_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "g values: "<< g << std::endl;
  NumericVector r  = RcppDeepState_NumericVector();
  std::string r_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/SAMP/AFL_SAMP/afl_inputs/" + std::to_string(t) + "_r.qs";
  qs::c_qsave(r,r_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "r values: "<< r << std::endl;
  IntegerVector N(1);
  N[0]  = RcppDeepState_int();
  std::string N_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/SAMP/AFL_SAMP/afl_inputs/" + std::to_string(t) + "_N.qs";
  qs::c_qsave(N,N_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "N values: "<< N << std::endl;
  NumericVector Ve(1);
  Ve[0]  = RcppDeepState_double();
  std::string Ve_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/SAMP/AFL_SAMP/afl_inputs/" + std::to_string(t) + "_Ve.qs";
  qs::c_qsave(Ve,Ve_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Ve values: "<< Ve << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    SAMP(C,g,r,N[0],Ve[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
