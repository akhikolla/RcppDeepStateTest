#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double ForwardValue(double value, double valueLower, double valueUpper);

TEST(RJafroc_deepstate_test,ForwardValue_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector value(1);
  value[0]  = RcppDeepState_double();
  std::string value_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/ForwardValue/AFL_ForwardValue/afl_inputs/" + std::to_string(t) + "_value.qs";
  qs::c_qsave(value,value_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "value values: "<< value << std::endl;
  NumericVector valueLower(1);
  valueLower[0]  = RcppDeepState_double();
  std::string value_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/ForwardValue/AFL_ForwardValue/afl_inputs/" + std::to_string(t) + "_value.qs";
  std::string valueLower_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/ForwardValue/AFL_ForwardValue/afl_inputs/" + std::to_string(t) + "_valueLower.qs";
  qs::c_qsave(valueLower,valueLower_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "valueLower values: "<< valueLower << std::endl;
  NumericVector valueUpper(1);
  valueUpper[0]  = RcppDeepState_double();
  std::string value_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/ForwardValue/AFL_ForwardValue/afl_inputs/" + std::to_string(t) + "_value.qs";
  std::string valueUpper_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/ForwardValue/AFL_ForwardValue/afl_inputs/" + std::to_string(t) + "_valueUpper.qs";
  qs::c_qsave(valueUpper,valueUpper_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "valueUpper values: "<< valueUpper << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    ForwardValue(value[0],valueLower[0],valueUpper[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
