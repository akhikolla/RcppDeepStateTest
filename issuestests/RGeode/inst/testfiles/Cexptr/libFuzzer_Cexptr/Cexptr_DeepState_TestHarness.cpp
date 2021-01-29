#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector Cexptr(int n, double lambda, NumericVector range);

TEST(RGeode_deepstate_test,Cexptr_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector n(1);
  n[0]  = RcppDeepState_int();
  std::string n_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RGeode/inst/testfiles/Cexptr/libFuzzer_Cexptr/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_n.qs";
  qs::c_qsave(n,n_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n values: "<< n << std::endl;
  NumericVector lambda(1);
  lambda[0]  = RcppDeepState_double();
  std::string lambda_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RGeode/inst/testfiles/Cexptr/libFuzzer_Cexptr/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_lambda.qs";
  qs::c_qsave(lambda,lambda_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lambda values: "<< lambda << std::endl;
  NumericVector range  = RcppDeepState_NumericVector();
  std::string range_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RGeode/inst/testfiles/Cexptr/libFuzzer_Cexptr/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_range.qs";
  qs::c_qsave(range,range_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "range values: "<< range << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    Cexptr(n[0],lambda[0],range);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
