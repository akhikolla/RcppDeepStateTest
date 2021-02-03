#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix do_ad2cp_ahrs(NumericMatrix v, NumericMatrix ahrs);

TEST(oce_deepstate_test,do_ad2cp_ahrs_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix v  = RcppDeepState_NumericMatrix();
  std::string v_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_ad2cp_ahrs/AFL_do_ad2cp_ahrs/afl_inputs/" + std::to_string(t) + "_v.qs";
  qs::c_qsave(v,v_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "v values: "<< v << std::endl;
  NumericMatrix ahrs  = RcppDeepState_NumericMatrix();
  std::string ahrs_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_ad2cp_ahrs/AFL_do_ad2cp_ahrs/afl_inputs/" + std::to_string(t) + "_ahrs.qs";
  qs::c_qsave(ahrs,ahrs_t,
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
