#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector intervals(int level, NumericVector array);

TEST(BNSL_deepstate_test,intervals_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector level(1);
  level[0]  = RcppDeepState_int();
  qs::c_qsave(level,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BNSL/inst/testfiles/intervals/inputs/level.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "level values: "<< level << std::endl;
  NumericVector array  = RcppDeepState_NumericVector();
  qs::c_qsave(array,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BNSL/inst/testfiles/intervals/inputs/array.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "array values: "<< array << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    intervals(level[0],array);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
