#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

CharacterVector get_(CharacterVector names, int element);

TEST(humaniformat_deepstate_test,get__test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  CharacterVector names  = RcppDeepState_CharacterVector();
  std::string names_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/humaniformat/inst/testfiles/get_/libFuzzer_get_/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_names.qs";
  qs::c_qsave(names,names_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "names values: "<< names << std::endl;
  IntegerVector element(1);
  element[0]  = RcppDeepState_int();
  std::string element_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/humaniformat/inst/testfiles/get_/libFuzzer_get_/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_element.qs";
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
