#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector pseudoRainfall(NumericVector RainM, NumericVector daysMonthAll, double shape, double scale, int firstMonth);

TEST(meteoland_deepstate_test,pseudoRainfall_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector RainM  = RcppDeepState_NumericVector();
  qs::c_qsave(RainM,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/pseudoRainfall/inputs/RainM.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "RainM values: "<< RainM << std::endl;
  NumericVector daysMonthAll  = RcppDeepState_NumericVector();
  qs::c_qsave(daysMonthAll,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/pseudoRainfall/inputs/daysMonthAll.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "daysMonthAll values: "<< daysMonthAll << std::endl;
  NumericVector shape(1);
  shape[0]  = RcppDeepState_double();
  qs::c_qsave(shape,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/pseudoRainfall/inputs/shape.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "shape values: "<< shape << std::endl;
  NumericVector scale(1);
  scale[0]  = RcppDeepState_double();
  qs::c_qsave(scale,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/pseudoRainfall/inputs/scale.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "scale values: "<< scale << std::endl;
  IntegerVector firstMonth(1);
  firstMonth[0]  = RcppDeepState_int();
  qs::c_qsave(firstMonth,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/pseudoRainfall/inputs/firstMonth.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "firstMonth values: "<< firstMonth << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    pseudoRainfall(RainM,daysMonthAll,shape[0],scale[0],firstMonth[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
