#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

CharacterVector get_(CharacterVector names, int element);

TEST(humaniformat_deepstate_test,get__test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  CharacterVector names  = RcppDeepState_CharacterVector();
  std::string names_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/humaniformat/inst/testfiles/get_/AFL_get_/afl_inputs/" + std::to_string(t) + "_names.qs";
  qs::c_qsave(names,names_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "names values: "<< names << std::endl;
  IntegerVector element(1);
  element[0]  = RcppDeepState_int();
  std::string element_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/humaniformat/inst/testfiles/get_/AFL_get_/afl_inputs/" + std::to_string(t) + "_element.qs";
  qs::c_qsave(element,element_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "element values: "<< element << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    get_(names,element[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
