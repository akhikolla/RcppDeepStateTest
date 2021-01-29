#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

LogicalVector validate_short(CharacterVector codes);

TEST(olctools_deepstate_test,validate_short_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  CharacterVector codes  = RcppDeepState_CharacterVector();
  std::string codes_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/olctools/inst/testfiles/validate_short/libFuzzer_validate_short/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_codes.qs";
  qs::c_qsave(codes,codes_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "codes values: "<< codes << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    validate_short(codes);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
