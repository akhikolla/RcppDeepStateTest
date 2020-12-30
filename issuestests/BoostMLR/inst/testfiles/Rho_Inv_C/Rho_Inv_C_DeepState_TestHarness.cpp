#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double Rho_Inv_C(double Rho_Value, double N_Value);

TEST(BoostMLR_deepstate_test,Rho_Inv_C_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector Rho_Value(1);
  Rho_Value[0]  = RcppDeepState_double();
  qs::c_qsave(Rho_Value,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BoostMLR/inst/testfiles/Rho_Inv_C/inputs/Rho_Value.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Rho_Value values: "<< Rho_Value << std::endl;
  NumericVector N_Value(1);
  N_Value[0]  = RcppDeepState_double();
  qs::c_qsave(N_Value,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BoostMLR/inst/testfiles/Rho_Inv_C/inputs/N_Value.qs",
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
