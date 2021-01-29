#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List do_geod_xy(NumericVector lon, NumericVector lat, NumericVector lonr, NumericVector latr, NumericVector a, NumericVector f);

TEST(oce_deepstate_test,do_geod_xy_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector lon  = RcppDeepState_NumericVector();
  std::string lon_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_geod_xy/libFuzzer_do_geod_xy/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_lon.qs";
  qs::c_qsave(lon,lon_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lon values: "<< lon << std::endl;
  NumericVector lat  = RcppDeepState_NumericVector();
  std::string lat_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_geod_xy/libFuzzer_do_geod_xy/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_lat.qs";
  qs::c_qsave(lat,lat_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lat values: "<< lat << std::endl;
  NumericVector lonr  = RcppDeepState_NumericVector();
  std::string lon_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_geod_xy/libFuzzer_do_geod_xy/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_lon.qs";
  std::string lonr_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_geod_xy/libFuzzer_do_geod_xy/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_lonr.qs";
  qs::c_qsave(lonr,lonr_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lonr values: "<< lonr << std::endl;
  NumericVector latr  = RcppDeepState_NumericVector();
  std::string lat_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_geod_xy/libFuzzer_do_geod_xy/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_lat.qs";
  std::string latr_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_geod_xy/libFuzzer_do_geod_xy/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_latr.qs";
  qs::c_qsave(latr,latr_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "latr values: "<< latr << std::endl;
  NumericVector a  = RcppDeepState_NumericVector();
  std::string a_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_geod_xy/libFuzzer_do_geod_xy/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_a.qs";
  qs::c_qsave(a,a_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "a values: "<< a << std::endl;
  NumericVector f  = RcppDeepState_NumericVector();
  std::string f_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_geod_xy/libFuzzer_do_geod_xy/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_f.qs";
  qs::c_qsave(f,f_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "f values: "<< f << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    do_geod_xy(lon,lat,lonr,latr,a,f);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
