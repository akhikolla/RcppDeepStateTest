#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector relativeHumidityFromMinMaxTemp(NumericVector Tmin, NumericVector Tmax);

TEST(meteoland_deepstate_test,relativeHumidityFromMinMaxTemp_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector Tmin  = RcppDeepState_NumericVector();
  std::string Tmin_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/relativeHumidityFromMinMaxTemp/libFuzzer_relativeHumidityFromMinMaxTemp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Tmin.qs";
  qs::c_qsave(Tmin,Tmin_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Tmin values: "<< Tmin << std::endl;
  NumericVector Tmax  = RcppDeepState_NumericVector();
  std::string Tmax_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/relativeHumidityFromMinMaxTemp/libFuzzer_relativeHumidityFromMinMaxTemp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Tmax.qs";
  qs::c_qsave(Tmax,Tmax_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Tmax values: "<< Tmax << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    relativeHumidityFromMinMaxTemp(Tmin,Tmax);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
