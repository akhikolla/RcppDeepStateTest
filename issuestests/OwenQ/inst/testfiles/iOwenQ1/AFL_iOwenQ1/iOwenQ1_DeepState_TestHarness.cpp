#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericVector iOwenQ1(double nu, double t, double delta, double R, int subdiv, double eps_abs, double eps_rel);

TEST(OwenQ_deepstate_test,iOwenQ1_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector nu(1);
  nu[0]  = RcppDeepState_double();
  std::string nu_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/iOwenQ1/AFL_iOwenQ1/afl_inputs/" + std::to_string(t) + "_nu.qs";
  qs::c_qsave(nu,nu_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nu values: "<< nu << std::endl;
  NumericVector t(1);
  t[0]  = RcppDeepState_double();
  std::string t_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/iOwenQ1/AFL_iOwenQ1/afl_inputs/" + std::to_string(t) + "_t.qs";
  qs::c_qsave(t,t_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "t values: "<< t << std::endl;
  NumericVector delta(1);
  delta[0]  = RcppDeepState_double();
  std::string delta_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/iOwenQ1/AFL_iOwenQ1/afl_inputs/" + std::to_string(t) + "_delta.qs";
  qs::c_qsave(delta,delta_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "delta values: "<< delta << std::endl;
  NumericVector R(1);
  R[0]  = RcppDeepState_double();
  std::string R_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/iOwenQ1/AFL_iOwenQ1/afl_inputs/" + std::to_string(t) + "_R.qs";
  qs::c_qsave(R,R_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "R values: "<< R << std::endl;
  IntegerVector subdiv(1);
  subdiv[0]  = RcppDeepState_int();
  std::string subdiv_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/iOwenQ1/AFL_iOwenQ1/afl_inputs/" + std::to_string(t) + "_subdiv.qs";
  qs::c_qsave(subdiv,subdiv_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "subdiv values: "<< subdiv << std::endl;
  NumericVector eps_abs(1);
  eps_abs[0]  = RcppDeepState_double();
  std::string eps_abs_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/iOwenQ1/AFL_iOwenQ1/afl_inputs/" + std::to_string(t) + "_eps_abs.qs";
  qs::c_qsave(eps_abs,eps_abs_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "eps_abs values: "<< eps_abs << std::endl;
  NumericVector eps_rel(1);
  eps_rel[0]  = RcppDeepState_double();
  std::string eps_rel_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/iOwenQ1/AFL_iOwenQ1/afl_inputs/" + std::to_string(t) + "_eps_rel.qs";
  qs::c_qsave(eps_rel,eps_rel_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "eps_rel values: "<< eps_rel << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    iOwenQ1(nu[0],t[0],delta[0],R[0],subdiv[0],eps_abs[0],eps_rel[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
