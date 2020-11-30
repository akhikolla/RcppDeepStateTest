#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double draw_SBM_geodesic_angle_CPP(const double tD);

TEST(castor_deepstate_test,draw_SBM_geodesic_angle_CPP_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector tD(1);
  tD[0]  = RcppDeepState_double();
  std::string tD_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/castor/inst/testfiles/draw_SBM_geodesic_angle_CPP/AFL_draw_SBM_geodesic_angle_CPP/afl_inputs/" + std::to_string(t) + "_tD.qs";
  qs::c_qsave(tD,tD_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tD values: "<< tD << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    draw_SBM_geodesic_angle_CPP(tD[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
