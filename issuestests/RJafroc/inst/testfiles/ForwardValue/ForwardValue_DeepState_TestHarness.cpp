#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double ForwardValue(double value, double valueLower, double valueUpper);

TEST(RJafroc_deepstate_test,ForwardValue_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector value(1);
  value[0]  = RcppDeepState_double();
  qs::c_qsave(value,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/ForwardValue/inputs/value.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "value values: "<< value << std::endl;
  NumericVector valueLower(1);
  valueLower[0]  = RcppDeepState_double();
  qs::c_qsave(valueLower,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/ForwardValue/inputs/valueLower.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "valueLower values: "<< valueLower << std::endl;
  NumericVector valueUpper(1);
  valueUpper[0]  = RcppDeepState_double();
  qs::c_qsave(valueUpper,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/ForwardValue/inputs/valueUpper.qs",
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
