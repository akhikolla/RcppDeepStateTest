#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

void addFormats(Rcpp::CharacterVector fmt);

TEST(anytime_deepstate_test,addFormats_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  CharacterVector fmt  = RcppDeepState_CharacterVector();
  qs::c_qsave(fmt,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/anytime/inst/testfiles/addFormats/inputs/fmt.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "fmt values: "<< fmt << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    addFormats(fmt);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
