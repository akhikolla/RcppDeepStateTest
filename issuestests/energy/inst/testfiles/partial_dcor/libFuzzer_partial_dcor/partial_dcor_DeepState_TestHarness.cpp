#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector partial_dcor(NumericMatrix Dx, NumericMatrix Dy, NumericMatrix Dz);

TEST(energy_deepstate_test,partial_dcor_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix Dx  = RcppDeepState_NumericMatrix();
  std::string Dx_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/energy/inst/testfiles/partial_dcor/libFuzzer_partial_dcor/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Dx.qs";
  qs::c_qsave(Dx,Dx_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Dx values: "<< Dx << std::endl;
  NumericMatrix Dy  = RcppDeepState_NumericMatrix();
  std::string Dy_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/energy/inst/testfiles/partial_dcor/libFuzzer_partial_dcor/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Dy.qs";
  qs::c_qsave(Dy,Dy_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Dy values: "<< Dy << std::endl;
  NumericMatrix Dz  = RcppDeepState_NumericMatrix();
  std::string Dz_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/energy/inst/testfiles/partial_dcor/libFuzzer_partial_dcor/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Dz.qs";
  qs::c_qsave(Dz,Dz_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Dz values: "<< Dz << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    partial_dcor(Dx,Dy,Dz);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
