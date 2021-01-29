#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector transformation(NumericVector x, NumericVector lb, NumericVector ub);

TEST(RMPSH_deepstate_test,transformation_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RMPSH/inst/testfiles/transformation/libFuzzer_transformation/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector lb  = RcppDeepState_NumericVector();
  std::string lb_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RMPSH/inst/testfiles/transformation/libFuzzer_transformation/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_lb.qs";
  qs::c_qsave(lb,lb_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lb values: "<< lb << std::endl;
  NumericVector ub  = RcppDeepState_NumericVector();
  std::string ub_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RMPSH/inst/testfiles/transformation/libFuzzer_transformation/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_ub.qs";
  qs::c_qsave(ub,ub_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ub values: "<< ub << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    transformation(x,lb,ub);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
