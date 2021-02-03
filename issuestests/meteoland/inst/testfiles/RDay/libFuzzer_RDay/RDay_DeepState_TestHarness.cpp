#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double RDay(double solarConstant, double latrad, double elevation, double slorad, double asprad, double delta, double diffTemp, double diffTempMonth, double vpa, double precipitation);

TEST(meteoland_deepstate_test,RDay_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector solarConstant(1);
  solarConstant[0]  = RcppDeepState_double();
  std::string solarConstant_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/RDay/libFuzzer_RDay/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_solarConstant.qs";
  qs::c_qsave(solarConstant,solarConstant_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "solarConstant values: "<< solarConstant << std::endl;
  NumericVector latrad(1);
  latrad[0]  = RcppDeepState_double();
  std::string latrad_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/RDay/libFuzzer_RDay/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_latrad.qs";
  qs::c_qsave(latrad,latrad_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "latrad values: "<< latrad << std::endl;
  NumericVector elevation(1);
  elevation[0]  = RcppDeepState_double();
  std::string elevation_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/RDay/libFuzzer_RDay/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_elevation.qs";
  qs::c_qsave(elevation,elevation_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "elevation values: "<< elevation << std::endl;
  NumericVector slorad(1);
  slorad[0]  = RcppDeepState_double();
  std::string slorad_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/RDay/libFuzzer_RDay/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_slorad.qs";
  qs::c_qsave(slorad,slorad_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "slorad values: "<< slorad << std::endl;
  NumericVector asprad(1);
  asprad[0]  = RcppDeepState_double();
  std::string asprad_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/RDay/libFuzzer_RDay/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_asprad.qs";
  qs::c_qsave(asprad,asprad_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "asprad values: "<< asprad << std::endl;
  NumericVector delta(1);
  delta[0]  = RcppDeepState_double();
  std::string delta_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/RDay/libFuzzer_RDay/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_delta.qs";
  qs::c_qsave(delta,delta_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "delta values: "<< delta << std::endl;
  NumericVector diffTemp(1);
  diffTemp[0]  = RcppDeepState_double();
  std::string diffTemp_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/RDay/libFuzzer_RDay/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_diffTemp.qs";
  qs::c_qsave(diffTemp,diffTemp_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "diffTemp values: "<< diffTemp << std::endl;
  NumericVector diffTempMonth(1);
  diffTempMonth[0]  = RcppDeepState_double();
  std::string diffTemp_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/RDay/libFuzzer_RDay/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_diffTemp.qs";
  std::string diffTempMonth_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/RDay/libFuzzer_RDay/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_diffTempMonth.qs";
  qs::c_qsave(diffTempMonth,diffTempMonth_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "diffTempMonth values: "<< diffTempMonth << std::endl;
  NumericVector vpa(1);
  vpa[0]  = RcppDeepState_double();
  std::string vpa_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/RDay/libFuzzer_RDay/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_vpa.qs";
  qs::c_qsave(vpa,vpa_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "vpa values: "<< vpa << std::endl;
  NumericVector precipitation(1);
  precipitation[0]  = RcppDeepState_double();
  std::string precipitation_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/RDay/libFuzzer_RDay/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_precipitation.qs";
  qs::c_qsave(precipitation,precipitation_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "precipitation values: "<< precipitation << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    RDay(solarConstant[0],latrad[0],elevation[0],slorad[0],asprad[0],delta[0],diffTemp[0],diffTempMonth[0],vpa[0],precipitation[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
