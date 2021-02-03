#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector dailyEquilibriumPET(NumericVector Temp, NumericVector Rn);

TEST(meteoland_deepstate_test,dailyEquilibriumPET_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector Temp  = RcppDeepState_NumericVector();
  std::string Temp_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/dailyEquilibriumPET/AFL_dailyEquilibriumPET/afl_inputs/" + std::to_string(t) + "_Temp.qs";
  qs::c_qsave(Temp,Temp_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Temp values: "<< Temp << std::endl;
  NumericVector Rn  = RcppDeepState_NumericVector();
  std::string Rn_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/dailyEquilibriumPET/AFL_dailyEquilibriumPET/afl_inputs/" + std::to_string(t) + "_Rn.qs";
  qs::c_qsave(Rn,Rn_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Rn values: "<< Rn << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    dailyEquilibriumPET(Temp,Rn);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
