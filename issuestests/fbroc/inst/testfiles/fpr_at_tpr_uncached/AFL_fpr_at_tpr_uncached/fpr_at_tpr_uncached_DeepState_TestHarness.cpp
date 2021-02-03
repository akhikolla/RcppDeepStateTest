#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix fpr_at_tpr_uncached(NumericVector pred, IntegerVector true_class, int n_boot, int n_steps);

TEST(fbroc_deepstate_test,fpr_at_tpr_uncached_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector pred  = RcppDeepState_NumericVector();
  std::string pred_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fbroc/inst/testfiles/fpr_at_tpr_uncached/AFL_fpr_at_tpr_uncached/afl_inputs/" + std::to_string(t) + "_pred.qs";
  qs::c_qsave(pred,pred_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pred values: "<< pred << std::endl;
  IntegerVector true_class  = RcppDeepState_IntegerVector();
  std::string true_class_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fbroc/inst/testfiles/fpr_at_tpr_uncached/AFL_fpr_at_tpr_uncached/afl_inputs/" + std::to_string(t) + "_true_class.qs";
  qs::c_qsave(true_class,true_class_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "true_class values: "<< true_class << std::endl;
  IntegerVector n_boot(1);
  n_boot[0]  = RcppDeepState_int();
  std::string n_boot_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fbroc/inst/testfiles/fpr_at_tpr_uncached/AFL_fpr_at_tpr_uncached/afl_inputs/" + std::to_string(t) + "_n_boot.qs";
  qs::c_qsave(n_boot,n_boot_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n_boot values: "<< n_boot << std::endl;
  IntegerVector n_steps(1);
  n_steps[0]  = RcppDeepState_int();
  std::string n_steps_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fbroc/inst/testfiles/fpr_at_tpr_uncached/AFL_fpr_at_tpr_uncached/afl_inputs/" + std::to_string(t) + "_n_steps.qs";
  qs::c_qsave(n_steps,n_steps_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n_steps values: "<< n_steps << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    fpr_at_tpr_uncached(pred,true_class,n_boot[0],n_steps[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
