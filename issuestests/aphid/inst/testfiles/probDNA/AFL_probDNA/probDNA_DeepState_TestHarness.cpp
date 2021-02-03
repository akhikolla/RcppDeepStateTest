#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double probDNA(int x, NumericVector probs);

TEST(aphid_deepstate_test,probDNA_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector x(1);
  x[0]  = RcppDeepState_int();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aphid/inst/testfiles/probDNA/AFL_probDNA/afl_inputs/" + std::to_string(t) + "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector probs  = RcppDeepState_NumericVector();
  std::string probs_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aphid/inst/testfiles/probDNA/AFL_probDNA/afl_inputs/" + std::to_string(t) + "_probs.qs";
  qs::c_qsave(probs,probs_t,
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
