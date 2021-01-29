#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector do_geoddist(NumericVector lon1, NumericVector lat1, NumericVector lon2, NumericVector lat2, NumericVector a, NumericVector f);

TEST(oce_deepstate_test,do_geoddist_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector lon1  = RcppDeepState_NumericVector();
  std::string lon1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_geoddist/libFuzzer_do_geoddist/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_lon1.qs";
  qs::c_qsave(lon1,lon1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lon1 values: "<< lon1 << std::endl;
  NumericVector lat1  = RcppDeepState_NumericVector();
  std::string lat1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_geoddist/libFuzzer_do_geoddist/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_lat1.qs";
  qs::c_qsave(lat1,lat1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lat1 values: "<< lat1 << std::endl;
  NumericVector lon2  = RcppDeepState_NumericVector();
  std::string lon2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_geoddist/libFuzzer_do_geoddist/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_lon2.qs";
  qs::c_qsave(lon2,lon2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lon2 values: "<< lon2 << std::endl;
  NumericVector lat2  = RcppDeepState_NumericVector();
  std::string lat2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_geoddist/libFuzzer_do_geoddist/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_lat2.qs";
  qs::c_qsave(lat2,lat2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lat2 values: "<< lat2 << std::endl;
  NumericVector a  = RcppDeepState_NumericVector();
  std::string a_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_geoddist/libFuzzer_do_geoddist/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_a.qs";
  qs::c_qsave(a,a_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "a values: "<< a << std::endl;
  NumericVector f  = RcppDeepState_NumericVector();
  std::string f_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_geoddist/libFuzzer_do_geoddist/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_f.qs";
  qs::c_qsave(f,f_t,
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
