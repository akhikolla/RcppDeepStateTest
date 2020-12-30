#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

int julianDay(int year, int month, int day);

TEST(meteoland_deepstate_test,julianDay_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector year(1);
  year[0]  = RcppDeepState_int();
  qs::c_qsave(year,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/julianDay/inputs/year.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "year values: "<< year << std::endl;
  IntegerVector month(1);
  month[0]  = RcppDeepState_int();
  qs::c_qsave(month,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/julianDay/inputs/month.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "month values: "<< month << std::endl;
  IntegerVector day(1);
  day[0]  = RcppDeepState_int();
  qs::c_qsave(day,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/julianDay/inputs/day.qs",
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
