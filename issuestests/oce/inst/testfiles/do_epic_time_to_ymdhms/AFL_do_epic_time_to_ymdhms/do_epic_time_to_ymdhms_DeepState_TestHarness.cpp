#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List do_epic_time_to_ymdhms(IntegerVector julianDay, IntegerVector millisecond);

TEST(oce_deepstate_test,do_epic_time_to_ymdhms_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector julianDay  = RcppDeepState_IntegerVector();
  std::string julianDay_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_epic_time_to_ymdhms/AFL_do_epic_time_to_ymdhms/afl_inputs/" + std::to_string(t) + "_julianDay.qs";
  qs::c_qsave(julianDay,julianDay_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "julianDay values: "<< julianDay << std::endl;
  IntegerVector millisecond  = RcppDeepState_IntegerVector();
  std::string millisecond_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_epic_time_to_ymdhms/AFL_do_epic_time_to_ymdhms/afl_inputs/" + std::to_string(t) + "_millisecond.qs";
  qs::c_qsave(millisecond,millisecond_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "millisecond values: "<< millisecond << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    do_epic_time_to_ymdhms(julianDay,millisecond);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
