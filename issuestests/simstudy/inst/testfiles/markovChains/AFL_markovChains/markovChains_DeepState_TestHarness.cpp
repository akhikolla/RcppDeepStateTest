#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::IntegerMatrix markovChains(int nchains, NumericMatrix P, int chainLen, IntegerVector state0);

TEST(simstudy_deepstate_test,markovChains_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector nchains(1);
  nchains[0]  = RcppDeepState_int();
  std::string nchains_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simstudy/inst/testfiles/markovChains/AFL_markovChains/afl_inputs/" + std::to_string(t) + "_nchains.qs";
  qs::c_qsave(nchains,nchains_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nchains values: "<< nchains << std::endl;
  NumericMatrix P  = RcppDeepState_NumericMatrix();
  std::string P_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simstudy/inst/testfiles/markovChains/AFL_markovChains/afl_inputs/" + std::to_string(t) + "_P.qs";
  qs::c_qsave(P,P_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "P values: "<< P << std::endl;
  IntegerVector chainLen(1);
  chainLen[0]  = RcppDeepState_int();
  std::string chainLen_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simstudy/inst/testfiles/markovChains/AFL_markovChains/afl_inputs/" + std::to_string(t) + "_chainLen.qs";
  qs::c_qsave(chainLen,chainLen_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "chainLen values: "<< chainLen << std::endl;
  IntegerVector state0  = RcppDeepState_IntegerVector();
  std::string state0_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simstudy/inst/testfiles/markovChains/AFL_markovChains/afl_inputs/" + std::to_string(t) + "_state0.qs";
  qs::c_qsave(state0,state0_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "state0 values: "<< state0 << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    markovChains(nchains[0],P,chainLen[0],state0);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
