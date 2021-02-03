#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double quadform(NumericMatrix Wtriplet, NumericVector Wtripletsum, const int n_triplet, const int nsites, NumericVector phi, NumericVector theta, double rho);

TEST(CARBayes_deepstate_test,quadform_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix Wtriplet  = RcppDeepState_NumericMatrix();
  std::string Wtriplet_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/quadform/AFL_quadform/afl_inputs/" + std::to_string(t) + "_Wtriplet.qs";
  qs::c_qsave(Wtriplet,Wtriplet_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Wtriplet values: "<< Wtriplet << std::endl;
  NumericVector Wtripletsum  = RcppDeepState_NumericVector();
  std::string Wtriplet_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/quadform/AFL_quadform/afl_inputs/" + std::to_string(t) + "_Wtriplet.qs";
  std::string Wtripletsum_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/quadform/AFL_quadform/afl_inputs/" + std::to_string(t) + "_Wtripletsum.qs";
  qs::c_qsave(Wtripletsum,Wtripletsum_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Wtripletsum values: "<< Wtripletsum << std::endl;
  IntegerVector n_triplet(1);
  n_triplet[0]  = RcppDeepState_int();
  std::string n_triplet_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/quadform/AFL_quadform/afl_inputs/" + std::to_string(t) + "_n_triplet.qs";
  qs::c_qsave(n_triplet,n_triplet_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n_triplet values: "<< n_triplet << std::endl;
  IntegerVector nsites(1);
  nsites[0]  = RcppDeepState_int();
  std::string nsites_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/quadform/AFL_quadform/afl_inputs/" + std::to_string(t) + "_nsites.qs";
  qs::c_qsave(nsites,nsites_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nsites values: "<< nsites << std::endl;
  NumericVector phi  = RcppDeepState_NumericVector();
  std::string phi_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/quadform/AFL_quadform/afl_inputs/" + std::to_string(t) + "_phi.qs";
  qs::c_qsave(phi,phi_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "phi values: "<< phi << std::endl;
  NumericVector theta  = RcppDeepState_NumericVector();
  std::string theta_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/quadform/AFL_quadform/afl_inputs/" + std::to_string(t) + "_theta.qs";
  qs::c_qsave(theta,theta_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "theta values: "<< theta << std::endl;
  NumericVector rho(1);
  rho[0]  = RcppDeepState_double();
  std::string rho_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/quadform/AFL_quadform/afl_inputs/" + std::to_string(t) + "_rho.qs";
  qs::c_qsave(rho,rho_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "rho values: "<< rho << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    quadform(Wtriplet,Wtripletsum,n_triplet[0],nsites[0],phi,theta,rho[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
