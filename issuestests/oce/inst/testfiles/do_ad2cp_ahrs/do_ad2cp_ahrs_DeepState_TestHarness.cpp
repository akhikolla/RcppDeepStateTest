#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix do_ad2cp_ahrs(NumericMatrix v, NumericMatrix ahrs);

TEST(oce_deepstate_test,do_ad2cp_ahrs_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix v  = RcppDeepState_NumericMatrix();
  qs::c_qsave(v,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_ad2cp_ahrs/inputs/v.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "v values: "<< v << std::endl;
  NumericMatrix ahrs  = RcppDeepState_NumericMatrix();
  qs::c_qsave(ahrs,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_ad2cp_ahrs/inputs/ahrs.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ahrs values: "<< ahrs << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    do_ad2cp_ahrs(v,ahrs);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
