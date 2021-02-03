#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

IntegerVector Which_C_NA(double x, NumericVector x_set);

TEST(BoostMLR_deepstate_test,Which_C_NA_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector x(1);
  x[0]  = RcppDeepState_double();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BoostMLR/inst/testfiles/Which_C_NA/AFL_Which_C_NA/afl_inputs/" + std::to_string(t) + "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector x_set  = RcppDeepState_NumericVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BoostMLR/inst/testfiles/Which_C_NA/AFL_Which_C_NA/afl_inputs/" + std::to_string(t) + "_x.qs";
  std::string x_set_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BoostMLR/inst/testfiles/Which_C_NA/AFL_Which_C_NA/afl_inputs/" + std::to_string(t) + "_x_set.qs";
  qs::c_qsave(x_set,x_set_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x_set values: "<< x_set << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    Which_C_NA(x[0],x_set);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
