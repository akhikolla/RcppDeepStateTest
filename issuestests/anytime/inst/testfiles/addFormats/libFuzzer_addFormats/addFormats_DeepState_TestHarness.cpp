#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

void addFormats(Rcpp::CharacterVector fmt);

TEST(anytime_deepstate_test,addFormats_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  CharacterVector fmt  = RcppDeepState_CharacterVector();
  std::string fmt_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/anytime/inst/testfiles/addFormats/libFuzzer_addFormats/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_fmt.qs";
  qs::c_qsave(fmt,fmt_t,
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
