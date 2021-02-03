#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

arma::mat rsin_onepar(int n, double k1, double k2, double k3, double mu1, double mu2, double I_upper_bd);

TEST(BAMBI_deepstate_test,rsin_onepar_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector n(1);
  n[0]  = RcppDeepState_int();
  std::string n_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/rsin_onepar/AFL_rsin_onepar/afl_inputs/" + std::to_string(t) + "_n.qs";
  qs::c_qsave(n,n_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n values: "<< n << std::endl;
  NumericVector k1(1);
  k1[0]  = RcppDeepState_double();
  std::string k1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/rsin_onepar/AFL_rsin_onepar/afl_inputs/" + std::to_string(t) + "_k1.qs";
  qs::c_qsave(k1,k1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "k1 values: "<< k1 << std::endl;
  NumericVector k2(1);
  k2[0]  = RcppDeepState_double();
  std::string k2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/rsin_onepar/AFL_rsin_onepar/afl_inputs/" + std::to_string(t) + "_k2.qs";
  qs::c_qsave(k2,k2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "k2 values: "<< k2 << std::endl;
  NumericVector k3(1);
  k3[0]  = RcppDeepState_double();
  std::string k3_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/rsin_onepar/AFL_rsin_onepar/afl_inputs/" + std::to_string(t) + "_k3.qs";
  qs::c_qsave(k3,k3_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "k3 values: "<< k3 << std::endl;
  NumericVector mu1(1);
  mu1[0]  = RcppDeepState_double();
  std::string mu1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/rsin_onepar/AFL_rsin_onepar/afl_inputs/" + std::to_string(t) + "_mu1.qs";
  qs::c_qsave(mu1,mu1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "mu1 values: "<< mu1 << std::endl;
  NumericVector mu2(1);
  mu2[0]  = RcppDeepState_double();
  std::string mu2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/rsin_onepar/AFL_rsin_onepar/afl_inputs/" + std::to_string(t) + "_mu2.qs";
  qs::c_qsave(mu2,mu2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "mu2 values: "<< mu2 << std::endl;
  NumericVector I_upper_bd(1);
  I_upper_bd[0]  = RcppDeepState_double();
  std::string I_upper_bd_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/rsin_onepar/AFL_rsin_onepar/afl_inputs/" + std::to_string(t) + "_I_upper_bd.qs";
  qs::c_qsave(I_upper_bd,I_upper_bd_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "I_upper_bd values: "<< I_upper_bd << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    rsin_onepar(n[0],k1[0],k2[0],k3[0],mu1[0],mu2[0],I_upper_bd[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
