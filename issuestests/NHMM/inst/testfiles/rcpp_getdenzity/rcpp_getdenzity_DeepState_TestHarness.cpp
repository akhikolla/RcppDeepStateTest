#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericVector rcpp_getdenzity(int A, Rcpp::NumericVector Wbin, Rcpp::NumericMatrix psi, Rcpp::NumericMatrix gamy, int fam, int K, int mixes, int delt, Rcpp::NumericMatrix y, Rcpp::NumericVector ppp, Rcpp::NumericVector theta1, Rcpp::NumericVector theta2);

TEST(NHMM_deepstate_test,rcpp_getdenzity_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector A(1);
  A[0]  = RcppDeepState_int();
  qs::c_qsave(A,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getdenzity/inputs/A.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "A values: "<< A << std::endl;
  NumericVector Wbin  = RcppDeepState_NumericVector();
  qs::c_qsave(Wbin,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getdenzity/inputs/Wbin.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Wbin values: "<< Wbin << std::endl;
  NumericMatrix psi  = RcppDeepState_NumericMatrix();
  qs::c_qsave(psi,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getdenzity/inputs/psi.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "psi values: "<< psi << std::endl;
  NumericMatrix gamy  = RcppDeepState_NumericMatrix();
  qs::c_qsave(gamy,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getdenzity/inputs/gamy.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "gamy values: "<< gamy << std::endl;
  IntegerVector fam(1);
  fam[0]  = RcppDeepState_int();
  qs::c_qsave(fam,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getdenzity/inputs/fam.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "fam values: "<< fam << std::endl;
  IntegerVector K(1);
  K[0]  = RcppDeepState_int();
  qs::c_qsave(K,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getdenzity/inputs/K.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "K values: "<< K << std::endl;
  IntegerVector mixes(1);
  mixes[0]  = RcppDeepState_int();
  qs::c_qsave(mixes,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getdenzity/inputs/mixes.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "mixes values: "<< mixes << std::endl;
  IntegerVector delt(1);
  delt[0]  = RcppDeepState_int();
  qs::c_qsave(delt,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getdenzity/inputs/delt.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "delt values: "<< delt << std::endl;
  NumericMatrix y  = RcppDeepState_NumericMatrix();
  qs::c_qsave(y,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getdenzity/inputs/y.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericVector ppp  = RcppDeepState_NumericVector();
  qs::c_qsave(ppp,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getdenzity/inputs/ppp.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ppp values: "<< ppp << std::endl;
  NumericVector theta1  = RcppDeepState_NumericVector();
  qs::c_qsave(theta1,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getdenzity/inputs/theta1.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "theta1 values: "<< theta1 << std::endl;
  NumericVector theta2  = RcppDeepState_NumericVector();
  qs::c_qsave(theta2,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getdenzity/inputs/theta2.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "theta2 values: "<< theta2 << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    rcpp_getdenzity(A[0],Wbin,psi,gamy,fam[0],K[0],mixes[0],delt[0],y,ppp,theta1,theta2);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
