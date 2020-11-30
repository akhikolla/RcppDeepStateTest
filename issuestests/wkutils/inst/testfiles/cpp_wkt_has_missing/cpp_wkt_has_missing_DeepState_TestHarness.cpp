#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

LogicalVector cpp_wkt_has_missing(CharacterVector wkt);

TEST(wkutils_deepstate_test,cpp_wkt_has_missing_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  CharacterVector wkt  = RcppDeepState_CharacterVector();
  qs::c_qsave(wkt,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/wkutils/inst/testfiles/cpp_wkt_has_missing/inputs/wkt.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "wkt values: "<< wkt << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    cpp_wkt_has_missing(wkt);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
