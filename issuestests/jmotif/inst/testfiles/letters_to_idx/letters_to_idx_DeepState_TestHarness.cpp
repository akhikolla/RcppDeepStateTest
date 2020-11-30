#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

IntegerVector letters_to_idx(CharacterVector str);

TEST(jmotif_deepstate_test,letters_to_idx_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  CharacterVector str  = RcppDeepState_CharacterVector();
  qs::c_qsave(str,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/jmotif/inst/testfiles/letters_to_idx/inputs/str.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "str values: "<< str << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    letters_to_idx(str);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
