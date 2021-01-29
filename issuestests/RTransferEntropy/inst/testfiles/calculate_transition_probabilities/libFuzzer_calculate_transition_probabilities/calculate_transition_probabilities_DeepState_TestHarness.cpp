#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List calculate_transition_probabilities(IntegerVector x, int lx);

TEST(RTransferEntropy_deepstate_test,calculate_transition_probabilities_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector x  = RcppDeepState_IntegerVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RTransferEntropy/inst/testfiles/calculate_transition_probabilities/libFuzzer_calculate_transition_probabilities/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  IntegerVector lx(1);
  lx[0]  = RcppDeepState_int();
  std::string lx_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RTransferEntropy/inst/testfiles/calculate_transition_probabilities/libFuzzer_calculate_transition_probabilities/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_lx.qs";
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
