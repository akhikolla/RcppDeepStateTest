#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

arma::vec runivm_onepar(int n, double k, double mu);

TEST(BAMBI_deepstate_test,runivm_onepar_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector n(1);
  n[0]  = RcppDeepState_int();
  std::string n_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/runivm_onepar/AFL_runivm_onepar/afl_inputs/" + std::to_string(t) + "_n.qs";
  qs::c_qsave(n,n_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n values: "<< n << std::endl;
  NumericVector k(1);
  k[0]  = RcppDeepState_double();
  std::string k_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/runivm_onepar/AFL_runivm_onepar/afl_inputs/" + std::to_string(t) + "_k.qs";
  qs::c_qsave(k,k_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "k values: "<< k << std::endl;
  NumericVector mu(1);
  mu[0]  = RcppDeepState_double();
  std::string mu_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/runivm_onepar/AFL_runivm_onepar/afl_inputs/" + std::to_string(t) + "_mu.qs";
  qs::c_qsave(mu,mu_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "mu values: "<< mu << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    runivm_onepar(n[0],k[0],mu[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
