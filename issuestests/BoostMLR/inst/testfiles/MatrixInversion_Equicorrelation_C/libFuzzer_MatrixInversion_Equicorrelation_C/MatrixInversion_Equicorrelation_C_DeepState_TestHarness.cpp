#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

arma::mat MatrixInversion_Equicorrelation_C(int N_Value, double phi, double rho);

TEST(BoostMLR_deepstate_test,MatrixInversion_Equicorrelation_C_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector N_Value(1);
  N_Value[0]  = RcppDeepState_int();
  std::string N_Value_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BoostMLR/inst/testfiles/MatrixInversion_Equicorrelation_C/libFuzzer_MatrixInversion_Equicorrelation_C/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_N_Value.qs";
  qs::c_qsave(N_Value,N_Value_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "N_Value values: "<< N_Value << std::endl;
  NumericVector phi(1);
  phi[0]  = RcppDeepState_double();
  std::string phi_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BoostMLR/inst/testfiles/MatrixInversion_Equicorrelation_C/libFuzzer_MatrixInversion_Equicorrelation_C/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_phi.qs";
  qs::c_qsave(phi,phi_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "phi values: "<< phi << std::endl;
  NumericVector rho(1);
  rho[0]  = RcppDeepState_double();
  std::string rho_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BoostMLR/inst/testfiles/MatrixInversion_Equicorrelation_C/libFuzzer_MatrixInversion_Equicorrelation_C/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_rho.qs";
  qs::c_qsave(rho,rho_t,
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
