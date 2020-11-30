#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector dailyEquilibriumPET(NumericVector Temp, NumericVector Rn);

TEST(meteoland_deepstate_test,dailyEquilibriumPET_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector Temp  = RcppDeepState_NumericVector();
  qs::c_qsave(Temp,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/dailyEquilibriumPET/inputs/Temp.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Temp values: "<< Temp << std::endl;
  NumericVector Rn  = RcppDeepState_NumericVector();
  qs::c_qsave(Rn,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/dailyEquilibriumPET/inputs/Rn.qs",
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
