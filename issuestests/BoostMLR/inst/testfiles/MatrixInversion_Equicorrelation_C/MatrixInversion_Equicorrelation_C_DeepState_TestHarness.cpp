#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

arma::mat MatrixInversion_Equicorrelation_C(int N_Value, double phi, double rho);

TEST(BoostMLR_deepstate_test,MatrixInversion_Equicorrelation_C_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector N_Value(1);
  N_Value[0]  = RcppDeepState_int();
  qs::c_qsave(N_Value,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BoostMLR/inst/testfiles/MatrixInversion_Equicorrelation_C/inputs/N_Value.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "N_Value values: "<< N_Value << std::endl;
  NumericVector phi(1);
  phi[0]  = RcppDeepState_double();
  qs::c_qsave(phi,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BoostMLR/inst/testfiles/MatrixInversion_Equicorrelation_C/inputs/phi.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "phi values: "<< phi << std::endl;
  NumericVector rho(1);
  rho[0]  = RcppDeepState_double();
  qs::c_qsave(rho,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BoostMLR/inst/testfiles/MatrixInversion_Equicorrelation_C/inputs/rho.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "rho values: "<< rho << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    MatrixInversion_Equicorrelation_C(N_Value[0],phi[0],rho[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
