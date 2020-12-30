#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::IntegerMatrix markovChains(int nchains, NumericMatrix P, int chainLen, IntegerVector state0);

TEST(simstudy_deepstate_test,markovChains_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector nchains(1);
  nchains[0]  = RcppDeepState_int();
  qs::c_qsave(nchains,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simstudy/inst/testfiles/markovChains/inputs/nchains.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nchains values: "<< nchains << std::endl;
  NumericMatrix P  = RcppDeepState_NumericMatrix();
  qs::c_qsave(P,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simstudy/inst/testfiles/markovChains/inputs/P.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "P values: "<< P << std::endl;
  IntegerVector chainLen(1);
  chainLen[0]  = RcppDeepState_int();
  qs::c_qsave(chainLen,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simstudy/inst/testfiles/markovChains/inputs/chainLen.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "chainLen values: "<< chainLen << std::endl;
  IntegerVector state0  = RcppDeepState_IntegerVector();
  qs::c_qsave(state0,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simstudy/inst/testfiles/markovChains/inputs/state0.qs",
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
