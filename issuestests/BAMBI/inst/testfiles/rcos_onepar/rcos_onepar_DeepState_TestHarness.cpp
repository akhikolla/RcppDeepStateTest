#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

arma::mat rcos_onepar(int n, double k1, double k2, double k3, double mu1, double mu2, double I_upper_bd);

TEST(BAMBI_deepstate_test,rcos_onepar_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector n(1);
  n[0]  = RcppDeepState_int();
  qs::c_qsave(n,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/rcos_onepar/inputs/n.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n values: "<< n << std::endl;
  NumericVector k1(1);
  k1[0]  = RcppDeepState_double();
  qs::c_qsave(k1,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/rcos_onepar/inputs/k1.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "k1 values: "<< k1 << std::endl;
  NumericVector k2(1);
  k2[0]  = RcppDeepState_double();
  qs::c_qsave(k2,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/rcos_onepar/inputs/k2.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "k2 values: "<< k2 << std::endl;
  NumericVector k3(1);
  k3[0]  = RcppDeepState_double();
  qs::c_qsave(k3,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/rcos_onepar/inputs/k3.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "k3 values: "<< k3 << std::endl;
  NumericVector mu1(1);
  mu1[0]  = RcppDeepState_double();
  qs::c_qsave(mu1,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/rcos_onepar/inputs/mu1.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "mu1 values: "<< mu1 << std::endl;
  NumericVector mu2(1);
  mu2[0]  = RcppDeepState_double();
  qs::c_qsave(mu2,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/rcos_onepar/inputs/mu2.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "mu2 values: "<< mu2 << std::endl;
  NumericVector I_upper_bd(1);
  I_upper_bd[0]  = RcppDeepState_double();
  qs::c_qsave(I_upper_bd,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/rcos_onepar/inputs/I_upper_bd.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "I_upper_bd values: "<< I_upper_bd << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    rcos_onepar(n[0],k1[0],k2[0],k3[0],mu1[0],mu2[0],I_upper_bd[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
