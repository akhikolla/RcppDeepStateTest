#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List do_geod_xy(NumericVector lon, NumericVector lat, NumericVector lonr, NumericVector latr, NumericVector a, NumericVector f);

TEST(oce_deepstate_test,do_geod_xy_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector lon  = RcppDeepState_NumericVector();
  qs::c_qsave(lon,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_geod_xy/inputs/lon.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lon values: "<< lon << std::endl;
  NumericVector lat  = RcppDeepState_NumericVector();
  qs::c_qsave(lat,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_geod_xy/inputs/lat.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lat values: "<< lat << std::endl;
  NumericVector lonr  = RcppDeepState_NumericVector();
  qs::c_qsave(lonr,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_geod_xy/inputs/lonr.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lonr values: "<< lonr << std::endl;
  NumericVector latr  = RcppDeepState_NumericVector();
  qs::c_qsave(latr,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_geod_xy/inputs/latr.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "latr values: "<< latr << std::endl;
  NumericVector a  = RcppDeepState_NumericVector();
  qs::c_qsave(a,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_geod_xy/inputs/a.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "a values: "<< a << std::endl;
  NumericVector f  = RcppDeepState_NumericVector();
  qs::c_qsave(f,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_geod_xy/inputs/f.qs",
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
