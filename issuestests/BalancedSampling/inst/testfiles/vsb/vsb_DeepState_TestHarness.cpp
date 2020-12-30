#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double vsb(NumericVector probs, NumericVector ys, NumericMatrix xs);

TEST(BalancedSampling_deepstate_test,vsb_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector probs  = RcppDeepState_NumericVector();
  qs::c_qsave(probs,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BalancedSampling/inst/testfiles/vsb/inputs/probs.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "probs values: "<< probs << std::endl;
  NumericVector ys  = RcppDeepState_NumericVector();
  qs::c_qsave(ys,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BalancedSampling/inst/testfiles/vsb/inputs/ys.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ys values: "<< ys << std::endl;
  NumericMatrix xs  = RcppDeepState_NumericMatrix();
  qs::c_qsave(xs,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BalancedSampling/inst/testfiles/vsb/inputs/xs.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "xs values: "<< xs << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    vsb(probs,ys,xs);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
