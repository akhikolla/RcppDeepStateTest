#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double log_sum_exp_vec(NumericVector w);

TEST(TransPhylo_deepstate_test,log_sum_exp_vec_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector w  = RcppDeepState_NumericVector();
  std::string w_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/TransPhylo/inst/testfiles/log_sum_exp_vec/libFuzzer_log_sum_exp_vec/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_w.qs";
  qs::c_qsave(w,w_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "w values: "<< w << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    log_sum_exp_vec(w);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
