#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericMatrix rcpp_getdenzityMVN(int A, Rcpp::NumericVector Wbin, Rcpp::NumericMatrix psi, int K, Rcpp::NumericMatrix y, Rcpp::NumericVector thetainv, Rcpp::NumericVector detS);

TEST(NHMM_deepstate_test,rcpp_getdenzityMVN_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector A(1);
  A[0]  = RcppDeepState_int();
  std::string A_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getdenzityMVN/AFL_rcpp_getdenzityMVN/afl_inputs/" + std::to_string(t) + "_A.qs";
  qs::c_qsave(A,A_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "A values: "<< A << std::endl;
  NumericVector Wbin  = RcppDeepState_NumericVector();
  std::string Wbin_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getdenzityMVN/AFL_rcpp_getdenzityMVN/afl_inputs/" + std::to_string(t) + "_Wbin.qs";
  qs::c_qsave(Wbin,Wbin_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Wbin values: "<< Wbin << std::endl;
  NumericMatrix psi  = RcppDeepState_NumericMatrix();
  std::string psi_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getdenzityMVN/AFL_rcpp_getdenzityMVN/afl_inputs/" + std::to_string(t) + "_psi.qs";
  qs::c_qsave(psi,psi_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "psi values: "<< psi << std::endl;
  IntegerVector K(1);
  K[0]  = RcppDeepState_int();
  std::string K_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getdenzityMVN/AFL_rcpp_getdenzityMVN/afl_inputs/" + std::to_string(t) + "_K.qs";
  qs::c_qsave(K,K_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "K values: "<< K << std::endl;
  NumericMatrix y  = RcppDeepState_NumericMatrix();
  std::string y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getdenzityMVN/AFL_rcpp_getdenzityMVN/afl_inputs/" + std::to_string(t) + "_y.qs";
  qs::c_qsave(y,y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericVector thetainv  = RcppDeepState_NumericVector();
  std::string thetainv_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getdenzityMVN/AFL_rcpp_getdenzityMVN/afl_inputs/" + std::to_string(t) + "_thetainv.qs";
  qs::c_qsave(thetainv,thetainv_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "thetainv values: "<< thetainv << std::endl;
  NumericVector detS  = RcppDeepState_NumericVector();
  std::string detS_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getdenzityMVN/AFL_rcpp_getdenzityMVN/afl_inputs/" + std::to_string(t) + "_detS.qs";
  qs::c_qsave(detS,detS_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "detS values: "<< detS << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    rcpp_getdenzityMVN(A[0],Wbin,psi,K[0],y,thetainv,detS);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
