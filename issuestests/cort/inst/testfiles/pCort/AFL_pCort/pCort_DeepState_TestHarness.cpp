#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericVector pCort(const NumericMatrix a, const NumericMatrix b, const NumericVector p, const NumericMatrix u);

TEST(cort_deepstate_test,pCort_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix a  = RcppDeepState_NumericMatrix();
  std::string a_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/cort/inst/testfiles/pCort/AFL_pCort/afl_inputs/" + std::to_string(t) + "_a.qs";
  qs::c_qsave(a,a_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "a values: "<< a << std::endl;
  NumericMatrix b  = RcppDeepState_NumericMatrix();
  std::string b_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/cort/inst/testfiles/pCort/AFL_pCort/afl_inputs/" + std::to_string(t) + "_b.qs";
  qs::c_qsave(b,b_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "b values: "<< b << std::endl;
  NumericVector p  = RcppDeepState_NumericVector();
  std::string p_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/cort/inst/testfiles/pCort/AFL_pCort/afl_inputs/" + std::to_string(t) + "_p.qs";
  qs::c_qsave(p,p_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "p values: "<< p << std::endl;
  NumericMatrix u  = RcppDeepState_NumericMatrix();
  std::string u_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/cort/inst/testfiles/pCort/AFL_pCort/afl_inputs/" + std::to_string(t) + "_u.qs";
  qs::c_qsave(u,u_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "u values: "<< u << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    pCort(a,b,p,u);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
