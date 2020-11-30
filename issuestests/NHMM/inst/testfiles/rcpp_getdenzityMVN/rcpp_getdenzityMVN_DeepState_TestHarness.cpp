#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericMatrix rcpp_getdenzityMVN(int A, Rcpp::NumericVector Wbin, Rcpp::NumericMatrix psi, int K, Rcpp::NumericMatrix y, Rcpp::NumericVector thetainv, Rcpp::NumericVector detS);

TEST(NHMM_deepstate_test,rcpp_getdenzityMVN_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector A(1);
  A[0]  = RcppDeepState_int();
  qs::c_qsave(A,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getdenzityMVN/inputs/A.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "A values: "<< A << std::endl;
  NumericVector Wbin  = RcppDeepState_NumericVector();
  qs::c_qsave(Wbin,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getdenzityMVN/inputs/Wbin.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Wbin values: "<< Wbin << std::endl;
  NumericMatrix psi  = RcppDeepState_NumericMatrix();
  qs::c_qsave(psi,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getdenzityMVN/inputs/psi.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "psi values: "<< psi << std::endl;
  IntegerVector K(1);
  K[0]  = RcppDeepState_int();
  qs::c_qsave(K,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getdenzityMVN/inputs/K.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "K values: "<< K << std::endl;
  NumericMatrix y  = RcppDeepState_NumericMatrix();
  qs::c_qsave(y,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getdenzityMVN/inputs/y.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericVector thetainv  = RcppDeepState_NumericVector();
  qs::c_qsave(thetainv,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getdenzityMVN/inputs/thetainv.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "thetainv values: "<< thetainv << std::endl;
  NumericVector detS  = RcppDeepState_NumericVector();
  qs::c_qsave(detS,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getdenzityMVN/inputs/detS.qs",
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
