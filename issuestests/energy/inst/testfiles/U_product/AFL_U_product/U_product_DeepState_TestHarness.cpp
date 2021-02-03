#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double U_product(NumericMatrix U, NumericMatrix V);

TEST(energy_deepstate_test,U_product_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix U  = RcppDeepState_NumericMatrix();
  std::string U_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/energy/inst/testfiles/U_product/AFL_U_product/afl_inputs/" + std::to_string(t) + "_U.qs";
  qs::c_qsave(U,U_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "U values: "<< U << std::endl;
  NumericMatrix V  = RcppDeepState_NumericMatrix();
  std::string V_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/energy/inst/testfiles/U_product/AFL_U_product/afl_inputs/" + std::to_string(t) + "_V.qs";
  qs::c_qsave(V,V_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "V values: "<< V << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    U_product(U,V);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
