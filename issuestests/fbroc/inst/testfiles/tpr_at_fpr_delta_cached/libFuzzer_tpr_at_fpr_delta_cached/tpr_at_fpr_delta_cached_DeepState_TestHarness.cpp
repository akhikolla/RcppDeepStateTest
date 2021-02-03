#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix tpr_at_fpr_delta_cached(NumericMatrix tpr1, NumericMatrix fpr1, NumericMatrix tpr2, NumericMatrix fpr2, int n_steps);

TEST(fbroc_deepstate_test,tpr_at_fpr_delta_cached_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix tpr1  = RcppDeepState_NumericMatrix();
  std::string tpr1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fbroc/inst/testfiles/tpr_at_fpr_delta_cached/libFuzzer_tpr_at_fpr_delta_cached/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_tpr1.qs";
  qs::c_qsave(tpr1,tpr1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tpr1 values: "<< tpr1 << std::endl;
  NumericMatrix fpr1  = RcppDeepState_NumericMatrix();
  std::string fpr1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fbroc/inst/testfiles/tpr_at_fpr_delta_cached/libFuzzer_tpr_at_fpr_delta_cached/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_fpr1.qs";
  qs::c_qsave(fpr1,fpr1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "fpr1 values: "<< fpr1 << std::endl;
  NumericMatrix tpr2  = RcppDeepState_NumericMatrix();
  std::string tpr2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fbroc/inst/testfiles/tpr_at_fpr_delta_cached/libFuzzer_tpr_at_fpr_delta_cached/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_tpr2.qs";
  qs::c_qsave(tpr2,tpr2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tpr2 values: "<< tpr2 << std::endl;
  NumericMatrix fpr2  = RcppDeepState_NumericMatrix();
  std::string fpr2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fbroc/inst/testfiles/tpr_at_fpr_delta_cached/libFuzzer_tpr_at_fpr_delta_cached/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_fpr2.qs";
  qs::c_qsave(fpr2,fpr2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "fpr2 values: "<< fpr2 << std::endl;
  IntegerVector n_steps(1);
  n_steps[0]  = RcppDeepState_int();
  std::string n_steps_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fbroc/inst/testfiles/tpr_at_fpr_delta_cached/libFuzzer_tpr_at_fpr_delta_cached/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_n_steps.qs";
  qs::c_qsave(n_steps,n_steps_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n_steps values: "<< n_steps << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    tpr_at_fpr_delta_cached(tpr1,fpr1,tpr2,fpr2,n_steps[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
