#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix pbinsum(NumericMatrix y, NumericVector N, NumericMatrix p);

TEST(nmixgof_deepstate_test,pbinsum_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix y  = RcppDeepState_NumericMatrix();
  qs::c_qsave(y,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/nmixgof/inst/testfiles/pbinsum/inputs/y.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericVector N  = RcppDeepState_NumericVector();
  qs::c_qsave(N,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/nmixgof/inst/testfiles/pbinsum/inputs/N.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "N values: "<< N << std::endl;
  NumericMatrix p  = RcppDeepState_NumericMatrix();
  qs::c_qsave(p,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/nmixgof/inst/testfiles/pbinsum/inputs/p.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "p values: "<< p << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    pbinsum(y,N,p);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
