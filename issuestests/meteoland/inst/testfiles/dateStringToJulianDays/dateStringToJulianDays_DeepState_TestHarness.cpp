#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

IntegerVector dateStringToJulianDays(CharacterVector dateStrings);

TEST(meteoland_deepstate_test,dateStringToJulianDays_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  CharacterVector dateStrings  = RcppDeepState_CharacterVector();
  qs::c_qsave(dateStrings,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/dateStringToJulianDays/inputs/dateStrings.qs",
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
