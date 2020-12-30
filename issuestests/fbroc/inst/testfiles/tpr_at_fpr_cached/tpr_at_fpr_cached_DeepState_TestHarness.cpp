#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix tpr_at_fpr_cached(NumericMatrix tpr, NumericMatrix fpr, int n_steps);

TEST(fbroc_deepstate_test,tpr_at_fpr_cached_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix tpr  = RcppDeepState_NumericMatrix();
  qs::c_qsave(tpr,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fbroc/inst/testfiles/tpr_at_fpr_cached/inputs/tpr.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tpr values: "<< tpr << std::endl;
  NumericMatrix fpr  = RcppDeepState_NumericMatrix();
  qs::c_qsave(fpr,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fbroc/inst/testfiles/tpr_at_fpr_cached/inputs/fpr.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "fpr values: "<< fpr << std::endl;
  IntegerVector n_steps(1);
  n_steps[0]  = RcppDeepState_int();
  qs::c_qsave(n_steps,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fbroc/inst/testfiles/tpr_at_fpr_cached/inputs/n_steps.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n_steps values: "<< n_steps << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    tpr_at_fpr_cached(tpr,fpr,n_steps[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
