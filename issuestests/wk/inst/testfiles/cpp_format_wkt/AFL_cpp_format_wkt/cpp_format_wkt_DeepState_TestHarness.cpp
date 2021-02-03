#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::CharacterVector cpp_format_wkt(CharacterVector wkt, int maxCoords);

TEST(wk_deepstate_test,cpp_format_wkt_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  CharacterVector wkt  = RcppDeepState_CharacterVector();
  std::string wkt_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/wk/inst/testfiles/cpp_format_wkt/AFL_cpp_format_wkt/afl_inputs/" + std::to_string(t) + "_wkt.qs";
  qs::c_qsave(wkt,wkt_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "wkt values: "<< wkt << std::endl;
  IntegerVector maxCoords(1);
  maxCoords[0]  = RcppDeepState_int();
  std::string maxCoords_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/wk/inst/testfiles/cpp_format_wkt/AFL_cpp_format_wkt/afl_inputs/" + std::to_string(t) + "_maxCoords.qs";
  qs::c_qsave(maxCoords,maxCoords_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "maxCoords values: "<< maxCoords << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    cpp_format_wkt(wkt,maxCoords[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
