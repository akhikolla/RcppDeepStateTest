#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix fpr_at_tpr_uncached(NumericVector pred, IntegerVector true_class, int n_boot, int n_steps);

TEST(fbroc_deepstate_test,fpr_at_tpr_uncached_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector pred  = RcppDeepState_NumericVector();
  qs::c_qsave(pred,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fbroc/inst/testfiles/fpr_at_tpr_uncached/inputs/pred.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pred values: "<< pred << std::endl;
  IntegerVector true_class  = RcppDeepState_IntegerVector();
  qs::c_qsave(true_class,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fbroc/inst/testfiles/fpr_at_tpr_uncached/inputs/true_class.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "true_class values: "<< true_class << std::endl;
  IntegerVector n_boot(1);
  n_boot[0]  = RcppDeepState_int();
  qs::c_qsave(n_boot,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fbroc/inst/testfiles/fpr_at_tpr_uncached/inputs/n_boot.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n_boot values: "<< n_boot << std::endl;
  IntegerVector n_steps(1);
  n_steps[0]  = RcppDeepState_int();
  qs::c_qsave(n_steps,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fbroc/inst/testfiles/fpr_at_tpr_uncached/inputs/n_steps.qs",
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
