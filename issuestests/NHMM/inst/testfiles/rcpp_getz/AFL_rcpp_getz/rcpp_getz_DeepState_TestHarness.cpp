#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

void rcpp_getz(Rcpp::NumericVector zf, Rcpp::NumericVector QQf, Rcpp::NumericMatrix denzity, Rcpp::NumericVector subseqy);

TEST(NHMM_deepstate_test,rcpp_getz_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector zf  = RcppDeepState_NumericVector();
  std::string zf_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getz/AFL_rcpp_getz/afl_inputs/" + std::to_string(t) + "_zf.qs";
  qs::c_qsave(zf,zf_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "zf values: "<< zf << std::endl;
  NumericVector QQf  = RcppDeepState_NumericVector();
  std::string QQf_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getz/AFL_rcpp_getz/afl_inputs/" + std::to_string(t) + "_QQf.qs";
  qs::c_qsave(QQf,QQf_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "QQf values: "<< QQf << std::endl;
  NumericMatrix denzity  = RcppDeepState_NumericMatrix();
  std::string denzity_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getz/AFL_rcpp_getz/afl_inputs/" + std::to_string(t) + "_denzity.qs";
  qs::c_qsave(denzity,denzity_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "denzity values: "<< denzity << std::endl;
  NumericVector subseqy  = RcppDeepState_NumericVector();
  std::string subseqy_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getz/AFL_rcpp_getz/afl_inputs/" + std::to_string(t) + "_subseqy.qs";
  qs::c_qsave(subseqy,subseqy_t,
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
