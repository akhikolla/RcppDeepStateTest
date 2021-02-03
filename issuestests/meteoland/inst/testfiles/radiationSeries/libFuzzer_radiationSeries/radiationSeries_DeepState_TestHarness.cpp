#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector radiationSeries(double latrad, double elevation, double slorad, double asprad, NumericVector J, NumericVector diffTemp, NumericVector diffTempMonth, NumericVector VP, NumericVector P);

TEST(meteoland_deepstate_test,radiationSeries_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector latrad(1);
  latrad[0]  = RcppDeepState_double();
  std::string latrad_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/radiationSeries/libFuzzer_radiationSeries/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_latrad.qs";
  qs::c_qsave(latrad,latrad_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "latrad values: "<< latrad << std::endl;
  NumericVector elevation(1);
  elevation[0]  = RcppDeepState_double();
  std::string elevation_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/radiationSeries/libFuzzer_radiationSeries/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_elevation.qs";
  qs::c_qsave(elevation,elevation_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "elevation values: "<< elevation << std::endl;
  NumericVector slorad(1);
  slorad[0]  = RcppDeepState_double();
  std::string slorad_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/radiationSeries/libFuzzer_radiationSeries/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_slorad.qs";
  qs::c_qsave(slorad,slorad_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "slorad values: "<< slorad << std::endl;
  NumericVector asprad(1);
  asprad[0]  = RcppDeepState_double();
  std::string asprad_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/radiationSeries/libFuzzer_radiationSeries/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_asprad.qs";
  qs::c_qsave(asprad,asprad_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "asprad values: "<< asprad << std::endl;
  NumericVector J  = RcppDeepState_NumericVector();
  std::string J_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/radiationSeries/libFuzzer_radiationSeries/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_J.qs";
  qs::c_qsave(J,J_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "J values: "<< J << std::endl;
  NumericVector diffTemp  = RcppDeepState_NumericVector();
  std::string diffTemp_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/radiationSeries/libFuzzer_radiationSeries/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_diffTemp.qs";
  qs::c_qsave(diffTemp,diffTemp_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "diffTemp values: "<< diffTemp << std::endl;
  NumericVector diffTempMonth  = RcppDeepState_NumericVector();
  std::string diffTemp_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/radiationSeries/libFuzzer_radiationSeries/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_diffTemp.qs";
  std::string diffTempMonth_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/radiationSeries/libFuzzer_radiationSeries/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_diffTempMonth.qs";
  qs::c_qsave(diffTempMonth,diffTempMonth_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "diffTempMonth values: "<< diffTempMonth << std::endl;
  NumericVector VP  = RcppDeepState_NumericVector();
  std::string VP_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/radiationSeries/libFuzzer_radiationSeries/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_VP.qs";
  qs::c_qsave(VP,VP_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "VP values: "<< VP << std::endl;
  NumericVector P  = RcppDeepState_NumericVector();
  std::string P_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/radiationSeries/libFuzzer_radiationSeries/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_P.qs";
  qs::c_qsave(P,P_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "P values: "<< P << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    radiationSeries(latrad[0],elevation[0],slorad[0],asprad[0],J,diffTemp,diffTempMonth,VP,P);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
