#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double mid_round(double input, int digits);

TEST(AGread_deepstate_test,mid_round_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector input(1);
  input[0]  = RcppDeepState_double();
  std::string input_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/AGread/inst/testfiles/mid_round/AFL_mid_round/afl_inputs/" + std::to_string(t) + "_input.qs";
  qs::c_qsave(input,input_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "input values: "<< input << std::endl;
  IntegerVector digits(1);
  digits[0]  = RcppDeepState_int();
  std::string digits_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/AGread/inst/testfiles/mid_round/AFL_mid_round/afl_inputs/" + std::to_string(t) + "_digits.qs";
  qs::c_qsave(digits,digits_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "digits values: "<< digits << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    mid_round(input[0],digits[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
