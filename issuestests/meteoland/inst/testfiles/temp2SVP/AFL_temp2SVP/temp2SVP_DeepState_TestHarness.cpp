#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector temp2SVP(NumericVector TD);

TEST(meteoland_deepstate_test,temp2SVP_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector TD  = RcppDeepState_NumericVector();
  std::string TD_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/temp2SVP/AFL_temp2SVP/afl_inputs/" + std::to_string(t) + "_TD.qs";
  qs::c_qsave(TD,TD_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "TD values: "<< TD << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    temp2SVP(TD);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
