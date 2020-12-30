#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

int binary_search(NumericVector array, double pattern);

TEST(BNSL_deepstate_test,binary_search_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector array  = RcppDeepState_NumericVector();
  qs::c_qsave(array,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BNSL/inst/testfiles/binary_search/inputs/array.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "array values: "<< array << std::endl;
  NumericVector pattern(1);
  pattern[0]  = RcppDeepState_double();
  qs::c_qsave(pattern,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BNSL/inst/testfiles/binary_search/inputs/pattern.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pattern values: "<< pattern << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    binary_search(array,pattern[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
