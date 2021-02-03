#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double Pz(double mu, double alpha, double zeta1, double zeta2);

TEST(RJafroc_deepstate_test,Pz_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector mu(1);
  mu[0]  = RcppDeepState_double();
  std::string mu_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/Pz/AFL_Pz/afl_inputs/" + std::to_string(t) + "_mu.qs";
  qs::c_qsave(mu,mu_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "mu values: "<< mu << std::endl;
  NumericVector alpha(1);
  alpha[0]  = RcppDeepState_double();
  std::string alpha_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/Pz/AFL_Pz/afl_inputs/" + std::to_string(t) + "_alpha.qs";
  qs::c_qsave(alpha,alpha_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "alpha values: "<< alpha << std::endl;
  NumericVector zeta1(1);
  zeta1[0]  = RcppDeepState_double();
  std::string zeta1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/Pz/AFL_Pz/afl_inputs/" + std::to_string(t) + "_zeta1.qs";
  qs::c_qsave(zeta1,zeta1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "zeta1 values: "<< zeta1 << std::endl;
  NumericVector zeta2(1);
  zeta2[0]  = RcppDeepState_double();
  std::string zeta2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/Pz/AFL_Pz/afl_inputs/" + std::to_string(t) + "_zeta2.qs";
  qs::c_qsave(zeta2,zeta2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "zeta2 values: "<< zeta2 << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    Pz(mu[0],alpha[0],zeta1[0],zeta2[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
