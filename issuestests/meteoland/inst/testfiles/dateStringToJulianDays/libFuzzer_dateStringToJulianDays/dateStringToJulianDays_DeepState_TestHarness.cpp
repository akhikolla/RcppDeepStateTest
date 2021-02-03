#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

IntegerVector dateStringToJulianDays(CharacterVector dateStrings);

TEST(meteoland_deepstate_test,dateStringToJulianDays_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  CharacterVector dateStrings  = RcppDeepState_CharacterVector();
  std::string dateStrings_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/dateStringToJulianDays/libFuzzer_dateStringToJulianDays/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_dateStrings.qs";
  qs::c_qsave(dateStrings,dateStrings_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "dateStrings values: "<< dateStrings << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    dateStringToJulianDays(dateStrings);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
