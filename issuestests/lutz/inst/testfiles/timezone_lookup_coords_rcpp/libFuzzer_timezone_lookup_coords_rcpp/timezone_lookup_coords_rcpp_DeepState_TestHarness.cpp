#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::CharacterVector timezone_lookup_coords_rcpp(Rcpp::NumericVector latv, Rcpp::NumericVector lonv);

TEST(lutz_deepstate_test,timezone_lookup_coords_rcpp_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector latv  = RcppDeepState_NumericVector();
  std::string latv_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/lutz/inst/testfiles/timezone_lookup_coords_rcpp/libFuzzer_timezone_lookup_coords_rcpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_latv.qs";
  qs::c_qsave(latv,latv_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "latv values: "<< latv << std::endl;
  NumericVector lonv  = RcppDeepState_NumericVector();
  std::string lonv_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/lutz/inst/testfiles/timezone_lookup_coords_rcpp/libFuzzer_timezone_lookup_coords_rcpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_lonv.qs";
  qs::c_qsave(lonv,lonv_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lonv values: "<< lonv << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    timezone_lookup_coords_rcpp(latv,lonv);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
