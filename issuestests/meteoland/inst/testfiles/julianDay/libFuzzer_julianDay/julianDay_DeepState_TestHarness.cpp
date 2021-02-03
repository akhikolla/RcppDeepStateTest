#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

int julianDay(int year, int month, int day);

TEST(meteoland_deepstate_test,julianDay_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector year(1);
  year[0]  = RcppDeepState_int();
  std::string year_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/julianDay/libFuzzer_julianDay/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_year.qs";
  qs::c_qsave(year,year_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "year values: "<< year << std::endl;
  IntegerVector month(1);
  month[0]  = RcppDeepState_int();
  std::string month_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/julianDay/libFuzzer_julianDay/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_month.qs";
  qs::c_qsave(month,month_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "month values: "<< month << std::endl;
  IntegerVector day(1);
  day[0]  = RcppDeepState_int();
  std::string day_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/julianDay/libFuzzer_julianDay/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_day.qs";
  qs::c_qsave(day,day_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "day values: "<< day << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    julianDay(year[0],month[0],day[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
