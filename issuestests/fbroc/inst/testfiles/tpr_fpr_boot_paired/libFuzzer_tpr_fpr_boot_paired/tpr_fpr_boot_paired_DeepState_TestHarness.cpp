#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List tpr_fpr_boot_paired(NumericVector pred1, NumericVector pred2, IntegerVector true_class, int n_boot);

TEST(fbroc_deepstate_test,tpr_fpr_boot_paired_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector pred1  = RcppDeepState_NumericVector();
  std::string pred1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fbroc/inst/testfiles/tpr_fpr_boot_paired/libFuzzer_tpr_fpr_boot_paired/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_pred1.qs";
  qs::c_qsave(pred1,pred1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pred1 values: "<< pred1 << std::endl;
  NumericVector pred2  = RcppDeepState_NumericVector();
  std::string pred2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fbroc/inst/testfiles/tpr_fpr_boot_paired/libFuzzer_tpr_fpr_boot_paired/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_pred2.qs";
  qs::c_qsave(pred2,pred2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pred2 values: "<< pred2 << std::endl;
  IntegerVector true_class  = RcppDeepState_IntegerVector();
  std::string true_class_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fbroc/inst/testfiles/tpr_fpr_boot_paired/libFuzzer_tpr_fpr_boot_paired/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_true_class.qs";
  qs::c_qsave(true_class,true_class_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "true_class values: "<< true_class << std::endl;
  IntegerVector n_boot(1);
  n_boot[0]  = RcppDeepState_int();
  std::string n_boot_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fbroc/inst/testfiles/tpr_fpr_boot_paired/libFuzzer_tpr_fpr_boot_paired/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_n_boot.qs";
  qs::c_qsave(n_boot,n_boot_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n_boot values: "<< n_boot << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    tpr_fpr_boot_paired(pred1,pred2,true_class,n_boot[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
