#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

arma::vec dwnorm2_manyx_onepar(arma::mat x, double k1, double k2, double k3, double mu1, double mu2, arma::mat omega_2pi);

TEST(BAMBI_deepstate_test,dwnorm2_manyx_onepar_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  std::ofstream x_stream;
  arma::mat x  = RcppDeepState_mat();
  x_stream.open("/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/dwnorm2_manyx_onepar/inputs/x");
  x_stream << x;
  std::cout << "x values: "<< x << std::endl;
  x_stream.close();
  NumericVector k1(1);
  k1[0]  = RcppDeepState_double();
  qs::c_qsave(k1,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/dwnorm2_manyx_onepar/inputs/k1.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "k1 values: "<< k1 << std::endl;
  NumericVector k2(1);
  k2[0]  = RcppDeepState_double();
  qs::c_qsave(k2,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/dwnorm2_manyx_onepar/inputs/k2.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "k2 values: "<< k2 << std::endl;
  NumericVector k3(1);
  k3[0]  = RcppDeepState_double();
  qs::c_qsave(k3,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/dwnorm2_manyx_onepar/inputs/k3.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "k3 values: "<< k3 << std::endl;
  NumericVector mu1(1);
  mu1[0]  = RcppDeepState_double();
  qs::c_qsave(mu1,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/dwnorm2_manyx_onepar/inputs/mu1.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "mu1 values: "<< mu1 << std::endl;
  NumericVector mu2(1);
  mu2[0]  = RcppDeepState_double();
  qs::c_qsave(mu2,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/dwnorm2_manyx_onepar/inputs/mu2.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "mu2 values: "<< mu2 << std::endl;
  std::ofstream omega_2pi_stream;
  arma::mat omega_2pi  = RcppDeepState_mat();
  omega_2pi_stream.open("/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/dwnorm2_manyx_onepar/inputs/omega_2pi");
  omega_2pi_stream << omega_2pi;
  std::cout << "omega_2pi values: "<< omega_2pi << std::endl;
  omega_2pi_stream.close();
  std::cout << "input ends" << std::endl;
  try{
    dwnorm2_manyx_onepar(x,k1[0],k2[0],k3[0],mu1[0],mu2[0],omega_2pi);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
