#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

CharacterVector format_period(CharacterVector names);

TEST(humaniformat_deepstate_test,format_period_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  CharacterVector names  = RcppDeepState_CharacterVector();
  std::string names_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/humaniformat/inst/testfiles/format_period/AFL_format_period/afl_inputs/" + std::to_string(t) + "_names.qs";
  qs::c_qsave(names,names_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "names values: "<< names << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    format_period(names);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
