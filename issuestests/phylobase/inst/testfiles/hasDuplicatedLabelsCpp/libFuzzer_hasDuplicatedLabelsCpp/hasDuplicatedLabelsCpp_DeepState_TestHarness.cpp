#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

bool hasDuplicatedLabelsCpp(Rcpp::CharacterVector label);

TEST(phylobase_deepstate_test,hasDuplicatedLabelsCpp_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  CharacterVector label  = RcppDeepState_CharacterVector();
  std::string label_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/phylobase/inst/testfiles/hasDuplicatedLabelsCpp/libFuzzer_hasDuplicatedLabelsCpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_label.qs";
  qs::c_qsave(label,label_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "label values: "<< label << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    hasDuplicatedLabelsCpp(label);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
