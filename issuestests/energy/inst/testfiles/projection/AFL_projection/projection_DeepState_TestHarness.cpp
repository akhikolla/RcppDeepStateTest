#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix projection(NumericMatrix Dx, NumericMatrix Dz);

TEST(energy_deepstate_test,projection_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix Dx  = RcppDeepState_NumericMatrix();
  std::string Dx_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/energy/inst/testfiles/projection/AFL_projection/afl_inputs/" + std::to_string(t) + "_Dx.qs";
  qs::c_qsave(Dx,Dx_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Dx values: "<< Dx << std::endl;
  NumericMatrix Dz  = RcppDeepState_NumericMatrix();
  std::string Dz_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/energy/inst/testfiles/projection/AFL_projection/afl_inputs/" + std::to_string(t) + "_Dz.qs";
  qs::c_qsave(Dz,Dz_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Dz values: "<< Dz << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    projection(Dx,Dz);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
