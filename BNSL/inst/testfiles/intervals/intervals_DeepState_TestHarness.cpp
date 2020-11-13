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
  std::ofstream level_stream;
  int level  = RcppDeepState_int();
  level_stream.open("/home/akhila/RcppDeepStateTest/BNSL/inst/testfiles/intervals/inputs/level");
  level_stream << level;
  std::cout << "level values: "<< level << std::endl;
  level_stream.close();
  NumericVector array  = RcppDeepState_NumericVector();
  qs::c_qsave(array,"/home/akhila/RcppDeepStateTest/BNSL/inst/testfiles/intervals/inputs/array.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "array values: "<< array << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    intervals(level,array);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
