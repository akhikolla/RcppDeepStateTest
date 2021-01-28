#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::IntegerMatrix markovChains(int nchains, NumericMatrix P, int chainLen, IntegerVector state0);

TEST(simstudy_deepstate_test,markovChains_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector nchains(1);
  nchains[0]  = RcppDeepState_int();
  std::string nchains_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simstudy/inst/testfiles/markovChains/libFuzzer_markovChains/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_nchains.qs";
  qs::c_qsave(nchains,nchains_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nchains values: "<< nchains << std::endl;
  NumericMatrix P  = RcppDeepState_NumericMatrix();
  std::string P_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simstudy/inst/testfiles/markovChains/libFuzzer_markovChains/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_P.qs";
  qs::c_qsave(P,P_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "P values: "<< P << std::endl;
  IntegerVector chainLen(1);
  chainLen[0]  = RcppDeepState_int();
  std::string chainLen_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simstudy/inst/testfiles/markovChains/libFuzzer_markovChains/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_chainLen.qs";
  qs::c_qsave(chainLen,chainLen_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "chainLen values: "<< chainLen << std::endl;
  IntegerVector state0  = RcppDeepState_IntegerVector();
  std::string state0_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simstudy/inst/testfiles/markovChains/libFuzzer_markovChains/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_state0.qs";
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
