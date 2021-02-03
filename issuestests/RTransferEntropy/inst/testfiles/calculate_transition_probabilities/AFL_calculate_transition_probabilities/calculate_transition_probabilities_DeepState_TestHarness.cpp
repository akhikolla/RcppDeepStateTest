#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List calculate_transition_probabilities(IntegerVector x, int lx);

TEST(RTransferEntropy_deepstate_test,calculate_transition_probabilities_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector x  = RcppDeepState_IntegerVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RTransferEntropy/inst/testfiles/calculate_transition_probabilities/AFL_calculate_transition_probabilities/afl_inputs/" + std::to_string(t) + "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  IntegerVector lx(1);
  lx[0]  = RcppDeepState_int();
  std::string lx_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RTransferEntropy/inst/testfiles/calculate_transition_probabilities/AFL_calculate_transition_probabilities/afl_inputs/" + std::to_string(t) + "_lx.qs";
  qs::c_qsave(lx,lx_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lx values: "<< lx << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    calculate_transition_probabilities(x,lx[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
