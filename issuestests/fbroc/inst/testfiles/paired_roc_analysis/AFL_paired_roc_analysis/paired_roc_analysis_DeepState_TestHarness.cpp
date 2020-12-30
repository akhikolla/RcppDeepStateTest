#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List paired_roc_analysis(NumericVector pred1, NumericVector pred2, IntegerVector true_class);

TEST(fbroc_deepstate_test,paired_roc_analysis_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector pred1  = RcppDeepState_NumericVector();
  std::string pred1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fbroc/inst/testfiles/paired_roc_analysis/AFL_paired_roc_analysis/afl_inputs/" + std::to_string(t) + "_pred1.qs";
  qs::c_qsave(pred1,pred1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pred1 values: "<< pred1 << std::endl;
  NumericVector pred2  = RcppDeepState_NumericVector();
  std::string pred2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fbroc/inst/testfiles/paired_roc_analysis/AFL_paired_roc_analysis/afl_inputs/" + std::to_string(t) + "_pred2.qs";
  qs::c_qsave(pred2,pred2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pred2 values: "<< pred2 << std::endl;
  IntegerVector true_class  = RcppDeepState_IntegerVector();
  std::string true_class_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fbroc/inst/testfiles/paired_roc_analysis/AFL_paired_roc_analysis/afl_inputs/" + std::to_string(t) + "_true_class.qs";
  qs::c_qsave(true_class,true_class_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "true_class values: "<< true_class << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    paired_roc_analysis(pred1,pred2,true_class);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
