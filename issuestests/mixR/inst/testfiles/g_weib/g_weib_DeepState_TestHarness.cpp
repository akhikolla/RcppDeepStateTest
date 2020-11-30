#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double g_weib(double r, NumericVector n, NumericVector ex, NumericVector tx);

TEST(mixR_deepstate_test,g_weib_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector r(1);
  r[0]  = RcppDeepState_double();
  qs::c_qsave(r,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mixR/inst/testfiles/g_weib/inputs/r.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "r values: "<< r << std::endl;
  NumericVector n  = RcppDeepState_NumericVector();
  qs::c_qsave(n,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mixR/inst/testfiles/g_weib/inputs/n.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n values: "<< n << std::endl;
  NumericVector ex  = RcppDeepState_NumericVector();
  qs::c_qsave(ex,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mixR/inst/testfiles/g_weib/inputs/ex.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ex values: "<< ex << std::endl;
  NumericVector tx  = RcppDeepState_NumericVector();
  qs::c_qsave(tx,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mixR/inst/testfiles/g_weib/inputs/tx.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tx values: "<< tx << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    g_weib(r[0],n,ex,tx);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
