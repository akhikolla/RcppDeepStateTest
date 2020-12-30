#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector do_geoddist(NumericVector lon1, NumericVector lat1, NumericVector lon2, NumericVector lat2, NumericVector a, NumericVector f);

TEST(oce_deepstate_test,do_geoddist_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector lon1  = RcppDeepState_NumericVector();
  qs::c_qsave(lon1,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_geoddist/inputs/lon1.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lon1 values: "<< lon1 << std::endl;
  NumericVector lat1  = RcppDeepState_NumericVector();
  qs::c_qsave(lat1,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_geoddist/inputs/lat1.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lat1 values: "<< lat1 << std::endl;
  NumericVector lon2  = RcppDeepState_NumericVector();
  qs::c_qsave(lon2,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_geoddist/inputs/lon2.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lon2 values: "<< lon2 << std::endl;
  NumericVector lat2  = RcppDeepState_NumericVector();
  qs::c_qsave(lat2,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_geoddist/inputs/lat2.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lat2 values: "<< lat2 << std::endl;
  NumericVector a  = RcppDeepState_NumericVector();
  qs::c_qsave(a,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_geoddist/inputs/a.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "a values: "<< a << std::endl;
  NumericVector f  = RcppDeepState_NumericVector();
  qs::c_qsave(f,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_geoddist/inputs/f.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "f values: "<< f << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    do_geoddist(lon1,lat1,lon2,lat2,a,f);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
