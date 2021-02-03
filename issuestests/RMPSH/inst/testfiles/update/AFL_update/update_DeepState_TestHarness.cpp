#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector update(NumericVector x, double epsilon, double rho, double phi);

TEST(RMPSH_deepstate_test,update_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RMPSH/inst/testfiles/update/AFL_update/afl_inputs/" + std::to_string(t) + "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector epsilon(1);
  epsilon[0]  = RcppDeepState_double();
  std::string epsilon_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RMPSH/inst/testfiles/update/AFL_update/afl_inputs/" + std::to_string(t) + "_epsilon.qs";
  qs::c_qsave(epsilon,epsilon_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "epsilon values: "<< epsilon << std::endl;
  NumericVector rho(1);
  rho[0]  = RcppDeepState_double();
  std::string rho_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RMPSH/inst/testfiles/update/AFL_update/afl_inputs/" + std::to_string(t) + "_rho.qs";
  qs::c_qsave(rho,rho_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "rho values: "<< rho << std::endl;
  NumericVector phi(1);
  phi[0]  = RcppDeepState_double();
  std::string phi_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RMPSH/inst/testfiles/update/AFL_update/afl_inputs/" + std::to_string(t) + "_phi.qs";
  qs::c_qsave(phi,phi_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "phi values: "<< phi << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    update(x,epsilon[0],rho[0],phi[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
