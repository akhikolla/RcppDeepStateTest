#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

void rcpp_getz(Rcpp::NumericVector zf, Rcpp::NumericVector QQf, Rcpp::NumericMatrix denzity, Rcpp::NumericVector subseqy);

TEST(NHMM_deepstate_test,rcpp_getz_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector zf  = RcppDeepState_NumericVector();
  qs::c_qsave(zf,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getz/inputs/zf.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "zf values: "<< zf << std::endl;
  NumericVector QQf  = RcppDeepState_NumericVector();
  qs::c_qsave(QQf,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getz/inputs/QQf.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "QQf values: "<< QQf << std::endl;
  NumericMatrix denzity  = RcppDeepState_NumericMatrix();
  qs::c_qsave(denzity,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getz/inputs/denzity.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "denzity values: "<< denzity << std::endl;
  NumericVector subseqy  = RcppDeepState_NumericVector();
  qs::c_qsave(subseqy,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getz/inputs/subseqy.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "subseqy values: "<< subseqy << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    rcpp_getz(zf,QQf,denzity,subseqy);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
