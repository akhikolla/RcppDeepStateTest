#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List paired_roc_analysis(NumericVector pred1, NumericVector pred2, IntegerVector true_class);

TEST(fbroc_deepstate_test,paired_roc_analysis_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector pred1  = RcppDeepState_NumericVector();
  qs::c_qsave(pred1,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fbroc/inst/testfiles/paired_roc_analysis/inputs/pred1.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pred1 values: "<< pred1 << std::endl;
  NumericVector pred2  = RcppDeepState_NumericVector();
  qs::c_qsave(pred2,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fbroc/inst/testfiles/paired_roc_analysis/inputs/pred2.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pred2 values: "<< pred2 << std::endl;
  IntegerVector true_class  = RcppDeepState_IntegerVector();
  qs::c_qsave(true_class,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fbroc/inst/testfiles/paired_roc_analysis/inputs/true_class.qs",
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
