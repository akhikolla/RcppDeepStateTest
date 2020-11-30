#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

IntegerVector find_corres(NumericMatrix X0, NumericMatrix X);

TEST(hetGP_deepstate_test,find_corres_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix X0  = RcppDeepState_NumericMatrix();
  qs::c_qsave(X0,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/hetGP/inst/testfiles/find_corres/inputs/X0.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "X0 values: "<< X0 << std::endl;
  NumericMatrix X  = RcppDeepState_NumericMatrix();
  qs::c_qsave(X,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/hetGP/inst/testfiles/find_corres/inputs/X.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "X values: "<< X << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    find_corres(X0,X);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
