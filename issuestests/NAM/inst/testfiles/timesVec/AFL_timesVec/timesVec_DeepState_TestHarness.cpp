#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix timesVec(NumericVector aa, NumericVector h, NumericMatrix bb, int q);

TEST(NAM_deepstate_test,timesVec_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector aa  = RcppDeepState_NumericVector();
  std::string aa_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/timesVec/AFL_timesVec/afl_inputs/" + std::to_string(t) + "_aa.qs";
  qs::c_qsave(aa,aa_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "aa values: "<< aa << std::endl;
  NumericVector h  = RcppDeepState_NumericVector();
  std::string h_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/timesVec/AFL_timesVec/afl_inputs/" + std::to_string(t) + "_h.qs";
  qs::c_qsave(h,h_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "h values: "<< h << std::endl;
  NumericMatrix bb  = RcppDeepState_NumericMatrix();
  std::string bb_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/timesVec/AFL_timesVec/afl_inputs/" + std::to_string(t) + "_bb.qs";
  qs::c_qsave(bb,bb_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "bb values: "<< bb << std::endl;
  IntegerVector q(1);
  q[0]  = RcppDeepState_int();
  std::string q_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/timesVec/AFL_timesVec/afl_inputs/" + std::to_string(t) + "_q.qs";
  qs::c_qsave(q,q_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "q values: "<< q << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    timesVec(aa,h,bb,q[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
