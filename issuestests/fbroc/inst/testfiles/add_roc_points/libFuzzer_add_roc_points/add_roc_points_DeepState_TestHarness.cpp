#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List add_roc_points(NumericVector tpr, NumericVector fpr);

TEST(fbroc_deepstate_test,add_roc_points_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector tpr  = RcppDeepState_NumericVector();
  std::string tpr_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fbroc/inst/testfiles/add_roc_points/libFuzzer_add_roc_points/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_tpr.qs";
  qs::c_qsave(tpr,tpr_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tpr values: "<< tpr << std::endl;
  NumericVector fpr  = RcppDeepState_NumericVector();
  std::string fpr_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fbroc/inst/testfiles/add_roc_points/libFuzzer_add_roc_points/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_fpr.qs";
  qs::c_qsave(fpr,fpr_t,
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
