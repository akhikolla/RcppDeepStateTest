#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix vapourPressureFromRH(NumericMatrix T, NumericMatrix RH);

TEST(meteoland_deepstate_test,vapourPressureFromRH_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix T  = RcppDeepState_NumericMatrix();
  std::string T_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/vapourPressureFromRH/AFL_vapourPressureFromRH/afl_inputs/" + std::to_string(t) + "_T.qs";
  qs::c_qsave(T,T_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "T values: "<< T << std::endl;
  NumericMatrix RH  = RcppDeepState_NumericMatrix();
  std::string RH_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/vapourPressureFromRH/AFL_vapourPressureFromRH/afl_inputs/" + std::to_string(t) + "_RH.qs";
  qs::c_qsave(RH,RH_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "RH values: "<< RH << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    vapourPressureFromRH(T,RH);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
