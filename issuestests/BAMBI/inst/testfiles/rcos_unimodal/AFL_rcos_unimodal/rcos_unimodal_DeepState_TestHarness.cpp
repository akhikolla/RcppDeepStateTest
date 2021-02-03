#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

arma::mat rcos_unimodal(int n, double k1, double k2, double k3, double mu1, double mu2, double kappa_opt, double log_I0_kappa_opt, double logK, double log_const_vmcos);

TEST(BAMBI_deepstate_test,rcos_unimodal_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector n(1);
  n[0]  = RcppDeepState_int();
  std::string n_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/rcos_unimodal/AFL_rcos_unimodal/afl_inputs/" + std::to_string(t) + "_n.qs";
  qs::c_qsave(n,n_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n values: "<< n << std::endl;
  NumericVector k1(1);
  k1[0]  = RcppDeepState_double();
  std::string k1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/rcos_unimodal/AFL_rcos_unimodal/afl_inputs/" + std::to_string(t) + "_k1.qs";
  qs::c_qsave(k1,k1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "k1 values: "<< k1 << std::endl;
  NumericVector k2(1);
  k2[0]  = RcppDeepState_double();
  std::string k2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/rcos_unimodal/AFL_rcos_unimodal/afl_inputs/" + std::to_string(t) + "_k2.qs";
  qs::c_qsave(k2,k2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "k2 values: "<< k2 << std::endl;
  NumericVector k3(1);
  k3[0]  = RcppDeepState_double();
  std::string k3_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/rcos_unimodal/AFL_rcos_unimodal/afl_inputs/" + std::to_string(t) + "_k3.qs";
  qs::c_qsave(k3,k3_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "k3 values: "<< k3 << std::endl;
  NumericVector mu1(1);
  mu1[0]  = RcppDeepState_double();
  std::string mu1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/rcos_unimodal/AFL_rcos_unimodal/afl_inputs/" + std::to_string(t) + "_mu1.qs";
  qs::c_qsave(mu1,mu1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "mu1 values: "<< mu1 << std::endl;
  NumericVector mu2(1);
  mu2[0]  = RcppDeepState_double();
  std::string mu2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/rcos_unimodal/AFL_rcos_unimodal/afl_inputs/" + std::to_string(t) + "_mu2.qs";
  qs::c_qsave(mu2,mu2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "mu2 values: "<< mu2 << std::endl;
  NumericVector kappa_opt(1);
  kappa_opt[0]  = RcppDeepState_double();
  std::string kappa_opt_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/rcos_unimodal/AFL_rcos_unimodal/afl_inputs/" + std::to_string(t) + "_kappa_opt.qs";
  qs::c_qsave(kappa_opt,kappa_opt_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "kappa_opt values: "<< kappa_opt << std::endl;
  NumericVector log_I0_kappa_opt(1);
  log_I0_kappa_opt[0]  = RcppDeepState_double();
  std::string log_I0_kappa_opt_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/rcos_unimodal/AFL_rcos_unimodal/afl_inputs/" + std::to_string(t) + "_log_I0_kappa_opt.qs";
  qs::c_qsave(log_I0_kappa_opt,log_I0_kappa_opt_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "log_I0_kappa_opt values: "<< log_I0_kappa_opt << std::endl;
  NumericVector logK(1);
  logK[0]  = RcppDeepState_double();
  std::string logK_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/rcos_unimodal/AFL_rcos_unimodal/afl_inputs/" + std::to_string(t) + "_logK.qs";
  qs::c_qsave(logK,logK_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "logK values: "<< logK << std::endl;
  NumericVector log_const_vmcos(1);
  log_const_vmcos[0]  = RcppDeepState_double();
  std::string log_const_vmcos_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/rcos_unimodal/AFL_rcos_unimodal/afl_inputs/" + std::to_string(t) + "_log_const_vmcos.qs";
  qs::c_qsave(log_const_vmcos,log_const_vmcos_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "log_const_vmcos values: "<< log_const_vmcos << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    rcos_unimodal(n[0],k1[0],k2[0],k3[0],mu1[0],mu2[0],kappa_opt[0],log_I0_kappa_opt[0],logK[0],log_const_vmcos[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
