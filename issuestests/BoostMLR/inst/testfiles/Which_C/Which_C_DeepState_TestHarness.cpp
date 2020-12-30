#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

IntegerVector Which_C(double x, NumericVector x_set);

TEST(BoostMLR_deepstate_test,Which_C_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector x(1);
  x[0]  = RcppDeepState_double();
  qs::c_qsave(x,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BoostMLR/inst/testfiles/Which_C/inputs/x.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector x_set  = RcppDeepState_NumericVector();
  qs::c_qsave(x_set,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BoostMLR/inst/testfiles/Which_C/inputs/x_set.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x_set values: "<< x_set << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    Which_C(x[0],x_set);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
