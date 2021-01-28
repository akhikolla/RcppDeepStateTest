#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double Rho_Inv_C(double Rho_Value, double N_Value);

TEST(BoostMLR_deepstate_test,Rho_Inv_C_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector Rho_Value(1);
  Rho_Value[0]  = RcppDeepState_double();
  std::string Rho_Value_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BoostMLR/inst/testfiles/Rho_Inv_C/libFuzzer_Rho_Inv_C/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Rho_Value.qs";
  qs::c_qsave(Rho_Value,Rho_Value_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Rho_Value values: "<< Rho_Value << std::endl;
  NumericVector N_Value(1);
  N_Value[0]  = RcppDeepState_double();
  std::string N_Value_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BoostMLR/inst/testfiles/Rho_Inv_C/libFuzzer_Rho_Inv_C/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_N_Value.qs";
  qs::c_qsave(N_Value,N_Value_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "N_Value values: "<< N_Value << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    Rho_Inv_C(Rho_Value[0],N_Value[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
