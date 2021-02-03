#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector persamplegrad(NumericVector fx, NumericVector y, int n, NumericVector group);

TEST(clogitboost_deepstate_test,persamplegrad_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector fx  = RcppDeepState_NumericVector();
  std::string fx_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/clogitboost/inst/testfiles/persamplegrad/libFuzzer_persamplegrad/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_fx.qs";
  qs::c_qsave(fx,fx_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "fx values: "<< fx << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  std::string y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/clogitboost/inst/testfiles/persamplegrad/libFuzzer_persamplegrad/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_y.qs";
  qs::c_qsave(y,y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  IntegerVector n(1);
  n[0]  = RcppDeepState_int();
  std::string n_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/clogitboost/inst/testfiles/persamplegrad/libFuzzer_persamplegrad/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_n.qs";
  qs::c_qsave(n,n_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n values: "<< n << std::endl;
  NumericVector group  = RcppDeepState_NumericVector();
  std::string group_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/clogitboost/inst/testfiles/persamplegrad/libFuzzer_persamplegrad/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_group.qs";
  qs::c_qsave(group,group_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "group values: "<< group << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    persamplegrad(fx,y,n[0],group);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
