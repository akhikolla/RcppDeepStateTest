#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector pseudoRainfall(NumericVector RainM, NumericVector daysMonthAll, double shape, double scale, int firstMonth);

TEST(meteoland_deepstate_test,pseudoRainfall_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector RainM  = RcppDeepState_NumericVector();
  std::string RainM_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/pseudoRainfall/libFuzzer_pseudoRainfall/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_RainM.qs";
  qs::c_qsave(RainM,RainM_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "RainM values: "<< RainM << std::endl;
  NumericVector daysMonthAll  = RcppDeepState_NumericVector();
  std::string daysMonthAll_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/pseudoRainfall/libFuzzer_pseudoRainfall/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_daysMonthAll.qs";
  qs::c_qsave(daysMonthAll,daysMonthAll_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "daysMonthAll values: "<< daysMonthAll << std::endl;
  NumericVector shape(1);
  shape[0]  = RcppDeepState_double();
  std::string shape_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/pseudoRainfall/libFuzzer_pseudoRainfall/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_shape.qs";
  qs::c_qsave(shape,shape_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "shape values: "<< shape << std::endl;
  NumericVector scale(1);
  scale[0]  = RcppDeepState_double();
  std::string scale_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/pseudoRainfall/libFuzzer_pseudoRainfall/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_scale.qs";
  qs::c_qsave(scale,scale_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "scale values: "<< scale << std::endl;
  IntegerVector firstMonth(1);
  firstMonth[0]  = RcppDeepState_int();
  std::string firstMonth_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/pseudoRainfall/libFuzzer_pseudoRainfall/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_firstMonth.qs";
  qs::c_qsave(firstMonth,firstMonth_t,
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
