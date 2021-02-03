#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericVector ipowen2(double nu, double t1, double t2, double delta1, double delta2, int subdiv, double eps_abs, double eps_rel);

TEST(OwenQ_deepstate_test,ipowen2_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector nu(1);
  nu[0]  = RcppDeepState_double();
  std::string nu_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/ipowen2/AFL_ipowen2/afl_inputs/" + std::to_string(t) + "_nu.qs";
  qs::c_qsave(nu,nu_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nu values: "<< nu << std::endl;
  NumericVector t1(1);
  t1[0]  = RcppDeepState_double();
  std::string t1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/ipowen2/AFL_ipowen2/afl_inputs/" + std::to_string(t) + "_t1.qs";
  qs::c_qsave(t1,t1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "t1 values: "<< t1 << std::endl;
  NumericVector t2(1);
  t2[0]  = RcppDeepState_double();
  std::string t2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/ipowen2/AFL_ipowen2/afl_inputs/" + std::to_string(t) + "_t2.qs";
  qs::c_qsave(t2,t2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "t2 values: "<< t2 << std::endl;
  NumericVector delta1(1);
  delta1[0]  = RcppDeepState_double();
  std::string delta1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/ipowen2/AFL_ipowen2/afl_inputs/" + std::to_string(t) + "_delta1.qs";
  qs::c_qsave(delta1,delta1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "delta1 values: "<< delta1 << std::endl;
  NumericVector delta2(1);
  delta2[0]  = RcppDeepState_double();
  std::string delta2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/ipowen2/AFL_ipowen2/afl_inputs/" + std::to_string(t) + "_delta2.qs";
  qs::c_qsave(delta2,delta2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "delta2 values: "<< delta2 << std::endl;
  IntegerVector subdiv(1);
  subdiv[0]  = RcppDeepState_int();
  std::string subdiv_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/ipowen2/AFL_ipowen2/afl_inputs/" + std::to_string(t) + "_subdiv.qs";
  qs::c_qsave(subdiv,subdiv_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "subdiv values: "<< subdiv << std::endl;
  NumericVector eps_abs(1);
  eps_abs[0]  = RcppDeepState_double();
  std::string eps_abs_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/ipowen2/AFL_ipowen2/afl_inputs/" + std::to_string(t) + "_eps_abs.qs";
  qs::c_qsave(eps_abs,eps_abs_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "eps_abs values: "<< eps_abs << std::endl;
  NumericVector eps_rel(1);
  eps_rel[0]  = RcppDeepState_double();
  std::string eps_rel_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/ipowen2/AFL_ipowen2/afl_inputs/" + std::to_string(t) + "_eps_rel.qs";
  qs::c_qsave(eps_rel,eps_rel_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "eps_rel values: "<< eps_rel << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    ipowen2(nu[0],t1[0],t2[0],delta1[0],delta2[0],subdiv[0],eps_abs[0],eps_rel[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
