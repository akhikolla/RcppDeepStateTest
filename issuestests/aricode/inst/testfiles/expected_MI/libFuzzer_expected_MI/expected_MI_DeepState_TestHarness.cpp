#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double expected_MI(IntegerVector ni_, IntegerVector n_j);

TEST(aricode_deepstate_test,expected_MI_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector ni_  = RcppDeepState_IntegerVector();
  std::string ni__t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aricode/inst/testfiles/expected_MI/libFuzzer_expected_MI/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_ni_.qs";
  qs::c_qsave(ni_,ni__t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ni_ values: "<< ni_ << std::endl;
  IntegerVector n_j  = RcppDeepState_IntegerVector();
  std::string n_j_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aricode/inst/testfiles/expected_MI/libFuzzer_expected_MI/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_n_j.qs";
  qs::c_qsave(n_j,n_j_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n_j values: "<< n_j << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    expected_MI(ni_,n_j);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
