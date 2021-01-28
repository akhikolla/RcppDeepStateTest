#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

LogicalVector is_date_format_(CharacterVector formats);

TEST(tidyxl_deepstate_test,is_date_format__test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  CharacterVector formats  = RcppDeepState_CharacterVector();
  std::string formats_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/tidyxl/inst/testfiles/is_date_format_/libFuzzer_is_date_format_/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_formats.qs";
  qs::c_qsave(formats,formats_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "formats values: "<< formats << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    is_date_format_(formats);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
