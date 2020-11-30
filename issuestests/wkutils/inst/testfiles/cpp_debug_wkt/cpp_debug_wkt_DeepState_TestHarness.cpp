#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

void cpp_debug_wkt(CharacterVector input);

TEST(wkutils_deepstate_test,cpp_debug_wkt_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  CharacterVector input  = RcppDeepState_CharacterVector();
  qs::c_qsave(input,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/wkutils/inst/testfiles/cpp_debug_wkt/inputs/input.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "input values: "<< input << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    cpp_debug_wkt(input);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
