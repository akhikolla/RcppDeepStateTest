#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::CharacterVector cpp_problems_wkt(CharacterVector wkt);

TEST(wk_deepstate_test,cpp_problems_wkt_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  CharacterVector wkt  = RcppDeepState_CharacterVector();
  std::string wkt_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/wk/inst/testfiles/cpp_problems_wkt/AFL_cpp_problems_wkt/afl_inputs/" + std::to_string(t) + "_wkt.qs";
  qs::c_qsave(wkt,wkt_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "wkt values: "<< wkt << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    cpp_problems_wkt(wkt);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
