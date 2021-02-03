#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

arma::vec dcos_manyx_onepar(arma::mat x, double k1, double k2, double k3, double mu1, double mu2, double l_const);

TEST(BAMBI_deepstate_test,dcos_manyx_onepar_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  std::ofstream x_stream;
  arma::mat x  = RcppDeepState_mat();
  x_stream.open("/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/dcos_manyx_onepar/inputs/x");
  x_stream << x;
  std::cout << "x values: "<< x << std::endl;
  x_stream.close();
  NumericVector k1(1);
  k1[0]  = RcppDeepState_double();
  std::string k1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/dcos_manyx_onepar/AFL_dcos_manyx_onepar/afl_inputs/" + std::to_string(t) + "_k1.qs";
  qs::c_qsave(k1,k1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "k1 values: "<< k1 << std::endl;
  NumericVector k2(1);
  k2[0]  = RcppDeepState_double();
  std::string k2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/dcos_manyx_onepar/AFL_dcos_manyx_onepar/afl_inputs/" + std::to_string(t) + "_k2.qs";
  qs::c_qsave(k2,k2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "k2 values: "<< k2 << std::endl;
  NumericVector k3(1);
  k3[0]  = RcppDeepState_double();
  std::string k3_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/dcos_manyx_onepar/AFL_dcos_manyx_onepar/afl_inputs/" + std::to_string(t) + "_k3.qs";
  qs::c_qsave(k3,k3_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "k3 values: "<< k3 << std::endl;
  NumericVector mu1(1);
  mu1[0]  = RcppDeepState_double();
  std::string mu1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/dcos_manyx_onepar/AFL_dcos_manyx_onepar/afl_inputs/" + std::to_string(t) + "_mu1.qs";
  qs::c_qsave(mu1,mu1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "mu1 values: "<< mu1 << std::endl;
  NumericVector mu2(1);
  mu2[0]  = RcppDeepState_double();
  std::string mu2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/dcos_manyx_onepar/AFL_dcos_manyx_onepar/afl_inputs/" + std::to_string(t) + "_mu2.qs";
  qs::c_qsave(mu2,mu2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "mu2 values: "<< mu2 << std::endl;
  NumericVector l_const(1);
  l_const[0]  = RcppDeepState_double();
  std::string l_const_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/dcos_manyx_onepar/AFL_dcos_manyx_onepar/afl_inputs/" + std::to_string(t) + "_l_const.qs";
  qs::c_qsave(l_const,l_const_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "l_const values: "<< l_const << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    dcos_manyx_onepar(x,k1[0],k2[0],k3[0],mu1[0],mu2[0],l_const[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
