#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List add_roc_points(NumericVector tpr, NumericVector fpr);

TEST(fbroc_deepstate_test,add_roc_points_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector tpr  = RcppDeepState_NumericVector();
  qs::c_qsave(tpr,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fbroc/inst/testfiles/add_roc_points/inputs/tpr.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tpr values: "<< tpr << std::endl;
  NumericVector fpr  = RcppDeepState_NumericVector();
  qs::c_qsave(fpr,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fbroc/inst/testfiles/add_roc_points/inputs/fpr.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "fpr values: "<< fpr << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    add_roc_points(tpr,fpr);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
