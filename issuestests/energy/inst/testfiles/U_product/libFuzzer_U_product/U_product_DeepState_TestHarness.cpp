#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double U_product(NumericMatrix U, NumericMatrix V);

TEST(energy_deepstate_test,U_product_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix U  = RcppDeepState_NumericMatrix();
  std::string U_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/energy/inst/testfiles/U_product/libFuzzer_U_product/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_U.qs";
  qs::c_qsave(U,U_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "U values: "<< U << std::endl;
  NumericMatrix V  = RcppDeepState_NumericMatrix();
  std::string V_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/energy/inst/testfiles/U_product/libFuzzer_U_product/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_V.qs";
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
