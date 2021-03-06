// AUTOMATICALLY GENERATED BY RCPPDEEPSTATE PLEASE DO NOT EDIT BY HAND, INSTEAD EDIT
// asyVarVUS_C_DeepState_TestHarness_generation.cpp and asyVarVUS_C_DeepState_TestHarness_checks.cpp

#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector asyVarVUS_C(NumericVector tt, NumericMatrix D_hat, double mu_hat, NumericMatrix EstFunc, NumericMatrix Hess_inv, NumericMatrix Der_D1_hat, NumericMatrix Der_D2_hat, NumericMatrix Der_D3_hat);

TEST(bcROCsurface_deepstate_test,asyVarVUS_C_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector tt  = RcppDeepState_NumericVector();
  std::string tt_t = "/home/akhila/fuzzer_packages/fuzzedpackages/bcROCsurface/inst/testfiles/asyVarVUS_C/libFuzzer_asyVarVUS_C/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_tt.qs";
  qs::c_qsave(tt,tt_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tt values: "<< tt << std::endl;
  NumericMatrix D_hat  = RcppDeepState_NumericMatrix();
  std::string D_hat_t = "/home/akhila/fuzzer_packages/fuzzedpackages/bcROCsurface/inst/testfiles/asyVarVUS_C/libFuzzer_asyVarVUS_C/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_D_hat.qs";
  qs::c_qsave(D_hat,D_hat_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "D_hat values: "<< D_hat << std::endl;
  NumericVector mu_hat(1);
  mu_hat[0]  = RcppDeepState_double();
  std::string mu_hat_t = "/home/akhila/fuzzer_packages/fuzzedpackages/bcROCsurface/inst/testfiles/asyVarVUS_C/libFuzzer_asyVarVUS_C/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_mu_hat.qs";
  qs::c_qsave(mu_hat,mu_hat_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "mu_hat values: "<< mu_hat << std::endl;
  NumericMatrix EstFunc  = RcppDeepState_NumericMatrix();
  std::string EstFunc_t = "/home/akhila/fuzzer_packages/fuzzedpackages/bcROCsurface/inst/testfiles/asyVarVUS_C/libFuzzer_asyVarVUS_C/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_EstFunc.qs";
  qs::c_qsave(EstFunc,EstFunc_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "EstFunc values: "<< EstFunc << std::endl;
  NumericMatrix Hess_inv  = RcppDeepState_NumericMatrix();
  std::string Hess_inv_t = "/home/akhila/fuzzer_packages/fuzzedpackages/bcROCsurface/inst/testfiles/asyVarVUS_C/libFuzzer_asyVarVUS_C/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Hess_inv.qs";
  qs::c_qsave(Hess_inv,Hess_inv_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Hess_inv values: "<< Hess_inv << std::endl;
  NumericMatrix Der_D1_hat  = RcppDeepState_NumericMatrix();
  std::string Der_D1_hat_t = "/home/akhila/fuzzer_packages/fuzzedpackages/bcROCsurface/inst/testfiles/asyVarVUS_C/libFuzzer_asyVarVUS_C/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Der_D1_hat.qs";
  qs::c_qsave(Der_D1_hat,Der_D1_hat_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Der_D1_hat values: "<< Der_D1_hat << std::endl;
  NumericMatrix Der_D2_hat  = RcppDeepState_NumericMatrix();
  std::string Der_D2_hat_t = "/home/akhila/fuzzer_packages/fuzzedpackages/bcROCsurface/inst/testfiles/asyVarVUS_C/libFuzzer_asyVarVUS_C/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Der_D2_hat.qs";
  qs::c_qsave(Der_D2_hat,Der_D2_hat_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Der_D2_hat values: "<< Der_D2_hat << std::endl;
  NumericMatrix Der_D3_hat  = RcppDeepState_NumericMatrix();
  std::string Der_D3_hat_t = "/home/akhila/fuzzer_packages/fuzzedpackages/bcROCsurface/inst/testfiles/asyVarVUS_C/libFuzzer_asyVarVUS_C/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Der_D3_hat.qs";
  qs::c_qsave(Der_D3_hat,Der_D3_hat_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Der_D3_hat values: "<< Der_D3_hat << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    asyVarVUS_C(tt,D_hat,mu_hat[0],EstFunc,Hess_inv,Der_D1_hat,Der_D2_hat,Der_D3_hat);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
