#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::CharacterVector timezone_lookup_coords_rcpp(Rcpp::NumericVector latv, Rcpp::NumericVector lonv);

TEST(lutz_deepstate_test,timezone_lookup_coords_rcpp_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector latv  = RcppDeepState_NumericVector();
  qs::c_qsave(latv,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/lutz/inst/testfiles/timezone_lookup_coords_rcpp/inputs/latv.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "latv values: "<< latv << std::endl;
  NumericVector lonv  = RcppDeepState_NumericVector();
  qs::c_qsave(lonv,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/lutz/inst/testfiles/timezone_lookup_coords_rcpp/inputs/lonv.qs",
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
