#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix tpr_at_fpr_delta_cached(NumericMatrix tpr1, NumericMatrix fpr1, NumericMatrix tpr2, NumericMatrix fpr2, int n_steps);

TEST(fbroc_deepstate_test,tpr_at_fpr_delta_cached_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix tpr1  = RcppDeepState_NumericMatrix();
  qs::c_qsave(tpr1,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fbroc/inst/testfiles/tpr_at_fpr_delta_cached/inputs/tpr1.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tpr1 values: "<< tpr1 << std::endl;
  NumericMatrix fpr1  = RcppDeepState_NumericMatrix();
  qs::c_qsave(fpr1,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fbroc/inst/testfiles/tpr_at_fpr_delta_cached/inputs/fpr1.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "fpr1 values: "<< fpr1 << std::endl;
  NumericMatrix tpr2  = RcppDeepState_NumericMatrix();
  qs::c_qsave(tpr2,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fbroc/inst/testfiles/tpr_at_fpr_delta_cached/inputs/tpr2.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tpr2 values: "<< tpr2 << std::endl;
  NumericMatrix fpr2  = RcppDeepState_NumericMatrix();
  qs::c_qsave(fpr2,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fbroc/inst/testfiles/tpr_at_fpr_delta_cached/inputs/fpr2.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "fpr2 values: "<< fpr2 << std::endl;
  IntegerVector n_steps(1);
  n_steps[0]  = RcppDeepState_int();
  qs::c_qsave(n_steps,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fbroc/inst/testfiles/tpr_at_fpr_delta_cached/inputs/n_steps.qs",
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
