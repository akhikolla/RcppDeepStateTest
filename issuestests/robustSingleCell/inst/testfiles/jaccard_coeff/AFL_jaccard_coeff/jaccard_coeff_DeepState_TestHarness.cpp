#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix jaccard_coeff(NumericMatrix idx);

TEST(robustSingleCell_deepstate_test,jaccard_coeff_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix idx  = RcppDeepState_NumericMatrix();
  std::string idx_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/robustSingleCell/inst/testfiles/jaccard_coeff/AFL_jaccard_coeff/afl_inputs/" + std::to_string(t) + "_idx.qs";
  qs::c_qsave(idx,idx_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "idx values: "<< idx << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    jaccard_coeff(idx);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
