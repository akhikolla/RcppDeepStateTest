#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector dcovU_stats(NumericMatrix Dx, NumericMatrix Dy);

TEST(energy_deepstate_test,dcovU_stats_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix Dx  = RcppDeepState_NumericMatrix();
  std::string Dx_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/energy/inst/testfiles/dcovU_stats/AFL_dcovU_stats/afl_inputs/" + std::to_string(t) + "_Dx.qs";
  qs::c_qsave(Dx,Dx_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Dx values: "<< Dx << std::endl;
  NumericMatrix Dy  = RcppDeepState_NumericMatrix();
  std::string Dy_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/energy/inst/testfiles/dcovU_stats/AFL_dcovU_stats/afl_inputs/" + std::to_string(t) + "_Dy.qs";
  qs::c_qsave(Dy,Dy_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Dy values: "<< Dy << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    dcovU_stats(Dx,Dy);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
