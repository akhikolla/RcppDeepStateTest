#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double probDNA(int x, NumericVector probs);

TEST(aphid_deepstate_test,probDNA_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector x(1);
  x[0]  = RcppDeepState_int();
  qs::c_qsave(x,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aphid/inst/testfiles/probDNA/inputs/x.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector probs  = RcppDeepState_NumericVector();
  qs::c_qsave(probs,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aphid/inst/testfiles/probDNA/inputs/probs.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "probs values: "<< probs << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    probDNA(x[0],probs);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
