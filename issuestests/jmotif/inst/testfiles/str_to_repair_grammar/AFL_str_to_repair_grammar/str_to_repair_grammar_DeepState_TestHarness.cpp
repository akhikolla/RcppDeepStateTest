#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::List str_to_repair_grammar(CharacterVector str);

TEST(jmotif_deepstate_test,str_to_repair_grammar_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  CharacterVector str  = RcppDeepState_CharacterVector();
  std::string str_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/jmotif/inst/testfiles/str_to_repair_grammar/AFL_str_to_repair_grammar/afl_inputs/" + std::to_string(t) + "_str.qs";
  qs::c_qsave(str,str_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "str values: "<< str << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    str_to_repair_grammar(str);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
