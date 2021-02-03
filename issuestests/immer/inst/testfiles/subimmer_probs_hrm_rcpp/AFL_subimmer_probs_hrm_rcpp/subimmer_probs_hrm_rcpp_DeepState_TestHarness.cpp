#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericVector subimmer_probs_hrm_rcpp(Rcpp::NumericVector x, Rcpp::NumericVector xi, Rcpp::NumericVector phi, Rcpp::NumericVector psi, int K, Rcpp::NumericVector x_ind);

TEST(immer_deepstate_test,subimmer_probs_hrm_rcpp_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/subimmer_probs_hrm_rcpp/AFL_subimmer_probs_hrm_rcpp/afl_inputs/" + std::to_string(t) + "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector xi  = RcppDeepState_NumericVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/subimmer_probs_hrm_rcpp/AFL_subimmer_probs_hrm_rcpp/afl_inputs/" + std::to_string(t) + "_x.qs";
  std::string xi_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/subimmer_probs_hrm_rcpp/AFL_subimmer_probs_hrm_rcpp/afl_inputs/" + std::to_string(t) + "_xi.qs";
  qs::c_qsave(xi,xi_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "xi values: "<< xi << std::endl;
  NumericVector phi  = RcppDeepState_NumericVector();
  std::string phi_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/subimmer_probs_hrm_rcpp/AFL_subimmer_probs_hrm_rcpp/afl_inputs/" + std::to_string(t) + "_phi.qs";
  qs::c_qsave(phi,phi_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "phi values: "<< phi << std::endl;
  NumericVector psi  = RcppDeepState_NumericVector();
  std::string psi_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/subimmer_probs_hrm_rcpp/AFL_subimmer_probs_hrm_rcpp/afl_inputs/" + std::to_string(t) + "_psi.qs";
  qs::c_qsave(psi,psi_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "psi values: "<< psi << std::endl;
  IntegerVector K(1);
  K[0]  = RcppDeepState_int();
  std::string K_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/subimmer_probs_hrm_rcpp/AFL_subimmer_probs_hrm_rcpp/afl_inputs/" + std::to_string(t) + "_K.qs";
  qs::c_qsave(K,K_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "K values: "<< K << std::endl;
  NumericVector x_ind  = RcppDeepState_NumericVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/subimmer_probs_hrm_rcpp/AFL_subimmer_probs_hrm_rcpp/afl_inputs/" + std::to_string(t) + "_x.qs";
  std::string x_ind_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/subimmer_probs_hrm_rcpp/AFL_subimmer_probs_hrm_rcpp/afl_inputs/" + std::to_string(t) + "_x_ind.qs";
  qs::c_qsave(x_ind,x_ind_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x_ind values: "<< x_ind << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    subimmer_probs_hrm_rcpp(x,xi,phi,psi,K[0],x_ind);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
