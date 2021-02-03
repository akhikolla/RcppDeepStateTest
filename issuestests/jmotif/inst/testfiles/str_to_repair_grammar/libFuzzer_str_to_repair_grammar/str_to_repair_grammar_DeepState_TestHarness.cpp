#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::List str_to_repair_grammar(CharacterVector str);

TEST(jmotif_deepstate_test,str_to_repair_grammar_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  CharacterVector str  = RcppDeepState_CharacterVector();
  std::string str_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/jmotif/inst/testfiles/str_to_repair_grammar/libFuzzer_str_to_repair_grammar/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_str.qs";
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
