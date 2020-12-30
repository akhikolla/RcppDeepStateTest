#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double likelihood(NumericVector fx, NumericVector y, int n, NumericVector group);

TEST(clogitboost_deepstate_test,likelihood_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector fx  = RcppDeepState_NumericVector();
  qs::c_qsave(fx,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/clogitboost/inst/testfiles/likelihood/inputs/fx.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "fx values: "<< fx << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  qs::c_qsave(y,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/clogitboost/inst/testfiles/likelihood/inputs/y.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  IntegerVector n(1);
  n[0]  = RcppDeepState_int();
  qs::c_qsave(n,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/clogitboost/inst/testfiles/likelihood/inputs/n.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n values: "<< n << std::endl;
  NumericVector group  = RcppDeepState_NumericVector();
  qs::c_qsave(group,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/clogitboost/inst/testfiles/likelihood/inputs/group.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "group values: "<< group << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    likelihood(fx,y,n[0],group);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
