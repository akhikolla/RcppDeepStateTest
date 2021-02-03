#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericMatrix rcpp_getsumz1(int Kf, int Jf, int Tf, Rcpp::NumericVector zf, Rcpp::NumericVector Sigmainvf, Rcpp::NumericMatrix in2f);

TEST(NHMM_deepstate_test,rcpp_getsumz1_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector Kf(1);
  Kf[0]  = RcppDeepState_int();
  std::string Kf_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getsumz1/AFL_rcpp_getsumz1/afl_inputs/" + std::to_string(t) + "_Kf.qs";
  qs::c_qsave(Kf,Kf_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Kf values: "<< Kf << std::endl;
  IntegerVector Jf(1);
  Jf[0]  = RcppDeepState_int();
  std::string Jf_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getsumz1/AFL_rcpp_getsumz1/afl_inputs/" + std::to_string(t) + "_Jf.qs";
  qs::c_qsave(Jf,Jf_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Jf values: "<< Jf << std::endl;
  IntegerVector Tf(1);
  Tf[0]  = RcppDeepState_int();
  std::string Tf_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getsumz1/AFL_rcpp_getsumz1/afl_inputs/" + std::to_string(t) + "_Tf.qs";
  qs::c_qsave(Tf,Tf_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Tf values: "<< Tf << std::endl;
  NumericVector zf  = RcppDeepState_NumericVector();
  std::string zf_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getsumz1/AFL_rcpp_getsumz1/afl_inputs/" + std::to_string(t) + "_zf.qs";
  qs::c_qsave(zf,zf_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "zf values: "<< zf << std::endl;
  NumericVector Sigmainvf  = RcppDeepState_NumericVector();
  std::string Sigmainvf_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getsumz1/AFL_rcpp_getsumz1/afl_inputs/" + std::to_string(t) + "_Sigmainvf.qs";
  qs::c_qsave(Sigmainvf,Sigmainvf_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Sigmainvf values: "<< Sigmainvf << std::endl;
  NumericMatrix in2f  = RcppDeepState_NumericMatrix();
  std::string in2f_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getsumz1/AFL_rcpp_getsumz1/afl_inputs/" + std::to_string(t) + "_in2f.qs";
  qs::c_qsave(in2f,in2f_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "in2f values: "<< in2f << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    rcpp_getsumz1(Kf[0],Jf[0],Tf[0],zf,Sigmainvf,in2f);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
