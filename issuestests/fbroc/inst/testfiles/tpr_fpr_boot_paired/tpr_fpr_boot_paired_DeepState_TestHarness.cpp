#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List tpr_fpr_boot_paired(NumericVector pred1, NumericVector pred2, IntegerVector true_class, int n_boot);

TEST(fbroc_deepstate_test,tpr_fpr_boot_paired_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector pred1  = RcppDeepState_NumericVector();
  qs::c_qsave(pred1,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fbroc/inst/testfiles/tpr_fpr_boot_paired/inputs/pred1.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pred1 values: "<< pred1 << std::endl;
  NumericVector pred2  = RcppDeepState_NumericVector();
  qs::c_qsave(pred2,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fbroc/inst/testfiles/tpr_fpr_boot_paired/inputs/pred2.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pred2 values: "<< pred2 << std::endl;
  IntegerVector true_class  = RcppDeepState_IntegerVector();
  qs::c_qsave(true_class,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fbroc/inst/testfiles/tpr_fpr_boot_paired/inputs/true_class.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "true_class values: "<< true_class << std::endl;
  IntegerVector n_boot(1);
  n_boot[0]  = RcppDeepState_int();
  qs::c_qsave(n_boot,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fbroc/inst/testfiles/tpr_fpr_boot_paired/inputs/n_boot.qs",
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
