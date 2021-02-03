#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix fpr_at_tpr_cached(NumericMatrix tpr, NumericMatrix fpr, int n_steps);

TEST(fbroc_deepstate_test,fpr_at_tpr_cached_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix tpr  = RcppDeepState_NumericMatrix();
  std::string tpr_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fbroc/inst/testfiles/fpr_at_tpr_cached/libFuzzer_fpr_at_tpr_cached/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_tpr.qs";
  qs::c_qsave(tpr,tpr_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tpr values: "<< tpr << std::endl;
  NumericMatrix fpr  = RcppDeepState_NumericMatrix();
  std::string fpr_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fbroc/inst/testfiles/fpr_at_tpr_cached/libFuzzer_fpr_at_tpr_cached/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_fpr.qs";
  qs::c_qsave(fpr,fpr_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "fpr values: "<< fpr << std::endl;
  IntegerVector n_steps(1);
  n_steps[0]  = RcppDeepState_int();
  std::string n_steps_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fbroc/inst/testfiles/fpr_at_tpr_cached/libFuzzer_fpr_at_tpr_cached/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_n_steps.qs";
  qs::c_qsave(n_steps,n_steps_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n_steps values: "<< n_steps << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    fpr_at_tpr_cached(tpr,fpr,n_steps[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
