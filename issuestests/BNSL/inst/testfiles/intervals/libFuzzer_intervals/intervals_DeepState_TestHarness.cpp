#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector intervals(int level, NumericVector array);

TEST(BNSL_deepstate_test,intervals_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector level(1);
  level[0]  = RcppDeepState_int();
  std::string level_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BNSL/inst/testfiles/intervals/libFuzzer_intervals/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_level.qs";
  qs::c_qsave(level,level_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "level values: "<< level << std::endl;
  NumericVector array  = RcppDeepState_NumericVector();
  std::string array_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BNSL/inst/testfiles/intervals/libFuzzer_intervals/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_array.qs";
  qs::c_qsave(array,array_t,
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
