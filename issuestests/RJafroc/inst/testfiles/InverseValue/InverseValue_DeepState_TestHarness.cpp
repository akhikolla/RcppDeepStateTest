#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double InverseValue(double valueFwd, double valueLower, double valueUpper);

TEST(RJafroc_deepstate_test,InverseValue_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector valueFwd(1);
  valueFwd[0]  = RcppDeepState_double();
  qs::c_qsave(valueFwd,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/InverseValue/inputs/valueFwd.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "valueFwd values: "<< valueFwd << std::endl;
  NumericVector valueLower(1);
  valueLower[0]  = RcppDeepState_double();
  qs::c_qsave(valueLower,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/InverseValue/inputs/valueLower.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "valueLower values: "<< valueLower << std::endl;
  NumericVector valueUpper(1);
  valueUpper[0]  = RcppDeepState_double();
  qs::c_qsave(valueUpper,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/InverseValue/inputs/valueUpper.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "valueUpper values: "<< valueUpper << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    InverseValue(valueFwd[0],valueLower[0],valueUpper[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
