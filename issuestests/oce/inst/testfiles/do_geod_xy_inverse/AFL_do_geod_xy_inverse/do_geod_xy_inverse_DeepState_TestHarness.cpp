#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List do_geod_xy_inverse(NumericVector x, NumericVector y, NumericVector lonr, NumericVector latr, NumericVector a, NumericVector f);

TEST(oce_deepstate_test,do_geod_xy_inverse_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_geod_xy_inverse/AFL_do_geod_xy_inverse/afl_inputs/" + std::to_string(t) + "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  std::string y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_geod_xy_inverse/AFL_do_geod_xy_inverse/afl_inputs/" + std::to_string(t) + "_y.qs";
  qs::c_qsave(y,y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericVector lonr  = RcppDeepState_NumericVector();
  std::string lonr_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_geod_xy_inverse/AFL_do_geod_xy_inverse/afl_inputs/" + std::to_string(t) + "_lonr.qs";
  qs::c_qsave(lonr,lonr_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lonr values: "<< lonr << std::endl;
  NumericVector latr  = RcppDeepState_NumericVector();
  std::string latr_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_geod_xy_inverse/AFL_do_geod_xy_inverse/afl_inputs/" + std::to_string(t) + "_latr.qs";
  qs::c_qsave(latr,latr_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "latr values: "<< latr << std::endl;
  NumericVector a  = RcppDeepState_NumericVector();
  std::string a_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_geod_xy_inverse/AFL_do_geod_xy_inverse/afl_inputs/" + std::to_string(t) + "_a.qs";
  qs::c_qsave(a,a_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "a values: "<< a << std::endl;
  NumericVector f  = RcppDeepState_NumericVector();
  std::string f_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_geod_xy_inverse/AFL_do_geod_xy_inverse/afl_inputs/" + std::to_string(t) + "_f.qs";
  qs::c_qsave(f,f_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "f values: "<< f << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    do_geod_xy_inverse(x,y,lonr,latr,a,f);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
