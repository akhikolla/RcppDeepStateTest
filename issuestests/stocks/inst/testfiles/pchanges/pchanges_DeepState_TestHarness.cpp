#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector pchanges(NumericVector x, int lag);

TEST(stocks_deepstate_test,pchanges_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  qs::c_qsave(x,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/stocks/inst/testfiles/pchanges/inputs/x.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  IntegerVector lag(1);
  lag[0]  = RcppDeepState_int();
  qs::c_qsave(lag,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/stocks/inst/testfiles/pchanges/inputs/lag.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lag values: "<< lag << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    pchanges(x,lag[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
