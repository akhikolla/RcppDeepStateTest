#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector rsplitn(int n, NumericVector mu, NumericVector sigma, NumericVector lmd);

TEST(dng_deepstate_test,rsplitn_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector n(1);
  n[0]  = RcppDeepState_int();
  qs::c_qsave(n,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/dng/inst/testfiles/rsplitn/inputs/n.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n values: "<< n << std::endl;
  NumericVector mu  = RcppDeepState_NumericVector();
  qs::c_qsave(mu,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/dng/inst/testfiles/rsplitn/inputs/mu.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "mu values: "<< mu << std::endl;
  NumericVector sigma  = RcppDeepState_NumericVector();
  qs::c_qsave(sigma,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/dng/inst/testfiles/rsplitn/inputs/sigma.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "sigma values: "<< sigma << std::endl;
  NumericVector lmd  = RcppDeepState_NumericVector();
  qs::c_qsave(lmd,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/dng/inst/testfiles/rsplitn/inputs/lmd.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lmd values: "<< lmd << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    rsplitn(n[0],mu,sigma,lmd);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
