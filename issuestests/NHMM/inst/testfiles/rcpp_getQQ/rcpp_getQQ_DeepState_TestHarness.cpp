#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericVector rcpp_getQQ(int K, Rcpp::NumericVector z, Rcpp::NumericMatrix dirprior, Rcpp::NumericVector subseqy);

TEST(NHMM_deepstate_test,rcpp_getQQ_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector K(1);
  K[0]  = RcppDeepState_int();
  qs::c_qsave(K,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getQQ/inputs/K.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "K values: "<< K << std::endl;
  NumericVector z  = RcppDeepState_NumericVector();
  qs::c_qsave(z,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getQQ/inputs/z.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "z values: "<< z << std::endl;
  NumericMatrix dirprior  = RcppDeepState_NumericMatrix();
  qs::c_qsave(dirprior,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getQQ/inputs/dirprior.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "dirprior values: "<< dirprior << std::endl;
  NumericVector subseqy  = RcppDeepState_NumericVector();
  qs::c_qsave(subseqy,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getQQ/inputs/subseqy.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "subseqy values: "<< subseqy << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    rcpp_getQQ(K[0],z,dirprior,subseqy);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
