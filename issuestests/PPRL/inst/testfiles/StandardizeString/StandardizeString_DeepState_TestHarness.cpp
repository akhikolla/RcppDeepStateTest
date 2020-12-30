#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

CharacterVector StandardizeString(CharacterVector strings);

TEST(PPRL_deepstate_test,StandardizeString_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  CharacterVector strings  = RcppDeepState_CharacterVector();
  qs::c_qsave(strings,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PPRL/inst/testfiles/StandardizeString/inputs/strings.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "strings values: "<< strings << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    StandardizeString(strings);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
