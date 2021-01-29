#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List solveODE(NumericMatrix inputTheta, double phi, const int verbose);

TEST(abcADM_deepstate_test,solveODE_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix inputTheta  = RcppDeepState_NumericMatrix();
  std::string inputTheta_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/abcADM/inst/testfiles/solveODE/libFuzzer_solveODE/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_inputTheta.qs";
  qs::c_qsave(inputTheta,inputTheta_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "inputTheta values: "<< inputTheta << std::endl;
  NumericVector phi(1);
  phi[0]  = RcppDeepState_double();
  std::string phi_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/abcADM/inst/testfiles/solveODE/libFuzzer_solveODE/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_phi.qs";
  qs::c_qsave(phi,phi_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "phi values: "<< phi << std::endl;
  IntegerVector verbose(1);
  verbose[0]  = RcppDeepState_int();
  std::string verbose_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/abcADM/inst/testfiles/solveODE/libFuzzer_solveODE/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_verbose.qs";
  qs::c_qsave(verbose,verbose_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "verbose values: "<< verbose << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    solveODE(inputTheta,phi[0],verbose[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
