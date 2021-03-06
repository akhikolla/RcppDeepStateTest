#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

arma::mat rsin_unimodal(int n, double k1, double k2, double k3, double mu1, double mu2, double kappa_opt, double log_I0_kappa_opt, double logK, double log_const_vmsin);

TEST(BAMBI_deepstate_test,rsin_unimodal_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector n(1);
  n[0]  = RcppDeepState_int();
  qs::c_qsave(n,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/rsin_unimodal/inputs/n.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n values: "<< n << std::endl;
  NumericVector k1(1);
  k1[0]  = RcppDeepState_double();
  qs::c_qsave(k1,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/rsin_unimodal/inputs/k1.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "k1 values: "<< k1 << std::endl;
  NumericVector k2(1);
  k2[0]  = RcppDeepState_double();
  qs::c_qsave(k2,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/rsin_unimodal/inputs/k2.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "k2 values: "<< k2 << std::endl;
  NumericVector k3(1);
  k3[0]  = RcppDeepState_double();
  qs::c_qsave(k3,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/rsin_unimodal/inputs/k3.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "k3 values: "<< k3 << std::endl;
  NumericVector mu1(1);
  mu1[0]  = RcppDeepState_double();
  qs::c_qsave(mu1,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/rsin_unimodal/inputs/mu1.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "mu1 values: "<< mu1 << std::endl;
  NumericVector mu2(1);
  mu2[0]  = RcppDeepState_double();
  qs::c_qsave(mu2,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/rsin_unimodal/inputs/mu2.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "mu2 values: "<< mu2 << std::endl;
  NumericVector kappa_opt(1);
  kappa_opt[0]  = RcppDeepState_double();
  qs::c_qsave(kappa_opt,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/rsin_unimodal/inputs/kappa_opt.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "kappa_opt values: "<< kappa_opt << std::endl;
  NumericVector log_I0_kappa_opt(1);
  log_I0_kappa_opt[0]  = RcppDeepState_double();
  qs::c_qsave(log_I0_kappa_opt,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/rsin_unimodal/inputs/log_I0_kappa_opt.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "log_I0_kappa_opt values: "<< log_I0_kappa_opt << std::endl;
  NumericVector logK(1);
  logK[0]  = RcppDeepState_double();
  qs::c_qsave(logK,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/rsin_unimodal/inputs/logK.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "logK values: "<< logK << std::endl;
  NumericVector log_const_vmsin(1);
  log_const_vmsin[0]  = RcppDeepState_double();
  qs::c_qsave(log_const_vmsin,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/rsin_unimodal/inputs/log_const_vmsin.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "log_const_vmsin values: "<< log_const_vmsin << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    rsin_unimodal(n[0],k1[0],k2[0],k3[0],mu1[0],mu2[0],kappa_opt[0],log_I0_kappa_opt[0],logK[0],log_const_vmsin[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
