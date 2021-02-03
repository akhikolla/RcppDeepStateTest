#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector anti_transformation(NumericVector x, NumericVector lb, NumericVector ub);

TEST(RMPSH_deepstate_test,anti_transformation_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RMPSH/inst/testfiles/anti_transformation/AFL_anti_transformation/afl_inputs/" + std::to_string(t) + "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector lb  = RcppDeepState_NumericVector();
  std::string lb_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RMPSH/inst/testfiles/anti_transformation/AFL_anti_transformation/afl_inputs/" + std::to_string(t) + "_lb.qs";
  qs::c_qsave(lb,lb_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lb values: "<< lb << std::endl;
  NumericVector ub  = RcppDeepState_NumericVector();
  std::string ub_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RMPSH/inst/testfiles/anti_transformation/AFL_anti_transformation/afl_inputs/" + std::to_string(t) + "_ub.qs";
  qs::c_qsave(ub,ub_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ub values: "<< ub << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    anti_transformation(x,lb,ub);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
