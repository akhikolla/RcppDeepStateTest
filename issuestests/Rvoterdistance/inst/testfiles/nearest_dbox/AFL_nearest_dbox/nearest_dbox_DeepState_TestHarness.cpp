#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector nearest_dbox(NumericVector lat1d_vec, NumericVector lon1d_vec, NumericVector lat2d_vec, NumericVector lon2d_vec);

TEST(Rvoterdistance_deepstate_test,nearest_dbox_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector lat1d_vec  = RcppDeepState_NumericVector();
  std::string lat1d_vec_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rvoterdistance/inst/testfiles/nearest_dbox/AFL_nearest_dbox/afl_inputs/" + std::to_string(t) + "_lat1d_vec.qs";
  qs::c_qsave(lat1d_vec,lat1d_vec_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lat1d_vec values: "<< lat1d_vec << std::endl;
  NumericVector lon1d_vec  = RcppDeepState_NumericVector();
  std::string lon1d_vec_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rvoterdistance/inst/testfiles/nearest_dbox/AFL_nearest_dbox/afl_inputs/" + std::to_string(t) + "_lon1d_vec.qs";
  qs::c_qsave(lon1d_vec,lon1d_vec_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lon1d_vec values: "<< lon1d_vec << std::endl;
  NumericVector lat2d_vec  = RcppDeepState_NumericVector();
  std::string lat2d_vec_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rvoterdistance/inst/testfiles/nearest_dbox/AFL_nearest_dbox/afl_inputs/" + std::to_string(t) + "_lat2d_vec.qs";
  qs::c_qsave(lat2d_vec,lat2d_vec_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lat2d_vec values: "<< lat2d_vec << std::endl;
  NumericVector lon2d_vec  = RcppDeepState_NumericVector();
  std::string lon2d_vec_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rvoterdistance/inst/testfiles/nearest_dbox/AFL_nearest_dbox/afl_inputs/" + std::to_string(t) + "_lon2d_vec.qs";
  qs::c_qsave(lon2d_vec,lon2d_vec_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lon2d_vec values: "<< lon2d_vec << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    nearest_dbox(lat1d_vec,lon1d_vec,lat2d_vec,lon2d_vec);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
