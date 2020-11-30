#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List calculate_transition_probabilities(IntegerVector x, int lx);

TEST(RTransferEntropy_deepstate_test,calculate_transition_probabilities_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector x  = RcppDeepState_IntegerVector();
  qs::c_qsave(x,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RTransferEntropy/inst/testfiles/calculate_transition_probabilities/inputs/x.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  IntegerVector lx(1);
  lx[0]  = RcppDeepState_int();
  qs::c_qsave(lx,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RTransferEntropy/inst/testfiles/calculate_transition_probabilities/inputs/lx.qs",
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
