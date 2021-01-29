#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d);

TEST(Rvoterdistance_deepstate_test,distanceEarth_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector lat1d(1);
  lat1d[0]  = RcppDeepState_double();
  std::string lat1d_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rvoterdistance/inst/testfiles/distanceEarth/libFuzzer_distanceEarth/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_lat1d.qs";
  qs::c_qsave(lat1d,lat1d_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lat1d values: "<< lat1d << std::endl;
  NumericVector lon1d(1);
  lon1d[0]  = RcppDeepState_double();
  std::string lon1d_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rvoterdistance/inst/testfiles/distanceEarth/libFuzzer_distanceEarth/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_lon1d.qs";
  qs::c_qsave(lon1d,lon1d_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lon1d values: "<< lon1d << std::endl;
  NumericVector lat2d(1);
  lat2d[0]  = RcppDeepState_double();
  std::string lat2d_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rvoterdistance/inst/testfiles/distanceEarth/libFuzzer_distanceEarth/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_lat2d.qs";
  qs::c_qsave(lat2d,lat2d_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lat2d values: "<< lat2d << std::endl;
  NumericVector lon2d(1);
  lon2d[0]  = RcppDeepState_double();
  std::string lon2d_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rvoterdistance/inst/testfiles/distanceEarth/libFuzzer_distanceEarth/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_lon2d.qs";
  qs::c_qsave(lon2d,lon2d_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lon2d values: "<< lon2d << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    distanceEarth(lat1d[0],lon1d[0],lat2d[0],lon2d[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
