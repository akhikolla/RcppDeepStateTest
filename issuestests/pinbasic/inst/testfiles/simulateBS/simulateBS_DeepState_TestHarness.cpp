#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix simulateBS(NumericVector param, int ndays);

TEST(pinbasic_deepstate_test,simulateBS_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector param  = RcppDeepState_NumericVector();
  qs::c_qsave(param,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/pinbasic/inst/testfiles/simulateBS/inputs/param.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "param values: "<< param << std::endl;
  IntegerVector ndays(1);
  ndays[0]  = RcppDeepState_int();
  qs::c_qsave(ndays,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/pinbasic/inst/testfiles/simulateBS/inputs/ndays.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ndays values: "<< ndays << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    simulateBS(param,ndays[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
