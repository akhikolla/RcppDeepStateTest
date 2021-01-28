#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

int binary_search(NumericVector array, double pattern);

TEST(BNSL_deepstate_test,binary_search_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector array  = RcppDeepState_NumericVector();
  std::string array_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BNSL/inst/testfiles/binary_search/libFuzzer_binary_search/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_array.qs";
  qs::c_qsave(array,array_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "array values: "<< array << std::endl;
  NumericVector pattern(1);
  pattern[0]  = RcppDeepState_double();
  std::string pattern_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BNSL/inst/testfiles/binary_search/libFuzzer_binary_search/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_pattern.qs";
  qs::c_qsave(pattern,pattern_t,
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
