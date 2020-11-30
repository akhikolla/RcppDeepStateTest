#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List get_cached_perf_paired(NumericMatrix tpr1, NumericMatrix fpr1, NumericMatrix tpr2, NumericMatrix fpr2, NumericVector param, int measure);

TEST(fbroc_deepstate_test,get_cached_perf_paired_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix tpr1  = RcppDeepState_NumericMatrix();
  qs::c_qsave(tpr1,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fbroc/inst/testfiles/get_cached_perf_paired/inputs/tpr1.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tpr1 values: "<< tpr1 << std::endl;
  NumericMatrix fpr1  = RcppDeepState_NumericMatrix();
  qs::c_qsave(fpr1,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fbroc/inst/testfiles/get_cached_perf_paired/inputs/fpr1.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "fpr1 values: "<< fpr1 << std::endl;
  NumericMatrix tpr2  = RcppDeepState_NumericMatrix();
  qs::c_qsave(tpr2,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fbroc/inst/testfiles/get_cached_perf_paired/inputs/tpr2.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tpr2 values: "<< tpr2 << std::endl;
  NumericMatrix fpr2  = RcppDeepState_NumericMatrix();
  qs::c_qsave(fpr2,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fbroc/inst/testfiles/get_cached_perf_paired/inputs/fpr2.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "fpr2 values: "<< fpr2 << std::endl;
  NumericVector param  = RcppDeepState_NumericVector();
  qs::c_qsave(param,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fbroc/inst/testfiles/get_cached_perf_paired/inputs/param.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "param values: "<< param << std::endl;
  IntegerVector measure(1);
  measure[0]  = RcppDeepState_int();
  qs::c_qsave(measure,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fbroc/inst/testfiles/get_cached_perf_paired/inputs/measure.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "measure values: "<< measure << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    get_cached_perf_paired(tpr1,fpr1,tpr2,fpr2,param,measure[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
