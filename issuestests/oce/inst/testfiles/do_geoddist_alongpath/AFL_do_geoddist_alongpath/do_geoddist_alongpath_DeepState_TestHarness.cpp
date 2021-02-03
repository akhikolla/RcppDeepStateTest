#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector do_geoddist_alongpath(NumericVector lon, NumericVector lat, NumericVector a, NumericVector f);

TEST(oce_deepstate_test,do_geoddist_alongpath_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector lon  = RcppDeepState_NumericVector();
  std::string lon_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_geoddist_alongpath/AFL_do_geoddist_alongpath/afl_inputs/" + std::to_string(t) + "_lon.qs";
  qs::c_qsave(lon,lon_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lon values: "<< lon << std::endl;
  NumericVector lat  = RcppDeepState_NumericVector();
  std::string lat_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_geoddist_alongpath/AFL_do_geoddist_alongpath/afl_inputs/" + std::to_string(t) + "_lat.qs";
  qs::c_qsave(lat,lat_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lat values: "<< lat << std::endl;
  NumericVector a  = RcppDeepState_NumericVector();
  std::string a_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_geoddist_alongpath/AFL_do_geoddist_alongpath/afl_inputs/" + std::to_string(t) + "_a.qs";
  qs::c_qsave(a,a_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "a values: "<< a << std::endl;
  NumericVector f  = RcppDeepState_NumericVector();
  std::string f_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_geoddist_alongpath/AFL_do_geoddist_alongpath/afl_inputs/" + std::to_string(t) + "_f.qs";
  qs::c_qsave(f,f_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "f values: "<< f << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    do_geoddist_alongpath(lon,lat,a,f);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
