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
  qs::c_qsave(array,"/home/akolla/extdata/packages/BNSL/inst/testfiles/binary_search/inputs/array.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "array values: "<< array << std::endl;
  std::ofstream pattern_stream;
  double pattern  = RcppDeepState_double();
  pattern_stream.open("/home/akolla/extdata/packages/BNSL/inst/testfiles/binary_search/inputs/pattern");
  pattern_stream << pattern;
  std::cout << "pattern values: "<< pattern << std::endl;
  pattern_stream.close();
  std::cout << "input ends" << std::endl;
  try{
    binary_search(array,pattern);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
