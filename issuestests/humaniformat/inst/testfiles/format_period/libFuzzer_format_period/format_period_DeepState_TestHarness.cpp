#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

CharacterVector format_period(CharacterVector names);

TEST(humaniformat_deepstate_test,format_period_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  CharacterVector names  = RcppDeepState_CharacterVector();
  std::string names_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/humaniformat/inst/testfiles/format_period/libFuzzer_format_period/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_names.qs";
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
