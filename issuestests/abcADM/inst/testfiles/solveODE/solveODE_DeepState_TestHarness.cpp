#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List solveODE(NumericMatrix inputTheta, double phi, const int verbose);

TEST(abcADM_deepstate_test,solveODE_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix inputTheta  = RcppDeepState_NumericMatrix();
  qs::c_qsave(inputTheta,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/abcADM/inst/testfiles/solveODE/inputs/inputTheta.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "inputTheta values: "<< inputTheta << std::endl;
  NumericVector phi(1);
  phi[0]  = RcppDeepState_double();
  qs::c_qsave(phi,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/abcADM/inst/testfiles/solveODE/inputs/phi.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "phi values: "<< phi << std::endl;
  IntegerVector verbose(1);
  verbose[0]  = RcppDeepState_int();
  qs::c_qsave(verbose,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/abcADM/inst/testfiles/solveODE/inputs/verbose.qs",
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
