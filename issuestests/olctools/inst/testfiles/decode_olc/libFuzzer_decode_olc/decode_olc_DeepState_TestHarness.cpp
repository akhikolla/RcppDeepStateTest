#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

DataFrame decode_olc(CharacterVector olcs);

TEST(olctools_deepstate_test,decode_olc_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  CharacterVector olcs  = RcppDeepState_CharacterVector();
  std::string olcs_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/olctools/inst/testfiles/decode_olc/libFuzzer_decode_olc/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_olcs.qs";
  qs::c_qsave(olcs,olcs_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "olcs values: "<< olcs << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    decode_olc(olcs);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
