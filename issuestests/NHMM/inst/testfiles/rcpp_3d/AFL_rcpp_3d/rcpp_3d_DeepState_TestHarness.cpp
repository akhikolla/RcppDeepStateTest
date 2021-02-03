#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

int rcpp_3d(int jf, int kf, int lf, int Jf, int Kf, int Lf);

TEST(NHMM_deepstate_test,rcpp_3d_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector jf(1);
  jf[0]  = RcppDeepState_int();
  std::string jf_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_3d/AFL_rcpp_3d/afl_inputs/" + std::to_string(t) + "_jf.qs";
  qs::c_qsave(jf,jf_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "jf values: "<< jf << std::endl;
  IntegerVector kf(1);
  kf[0]  = RcppDeepState_int();
  std::string kf_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_3d/AFL_rcpp_3d/afl_inputs/" + std::to_string(t) + "_kf.qs";
  qs::c_qsave(kf,kf_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "kf values: "<< kf << std::endl;
  IntegerVector lf(1);
  lf[0]  = RcppDeepState_int();
  std::string lf_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_3d/AFL_rcpp_3d/afl_inputs/" + std::to_string(t) + "_lf.qs";
  qs::c_qsave(lf,lf_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lf values: "<< lf << std::endl;
  IntegerVector Jf(1);
  Jf[0]  = RcppDeepState_int();
  std::string Jf_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_3d/AFL_rcpp_3d/afl_inputs/" + std::to_string(t) + "_Jf.qs";
  qs::c_qsave(Jf,Jf_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Jf values: "<< Jf << std::endl;
  IntegerVector Kf(1);
  Kf[0]  = RcppDeepState_int();
  std::string Kf_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_3d/AFL_rcpp_3d/afl_inputs/" + std::to_string(t) + "_Kf.qs";
  qs::c_qsave(Kf,Kf_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Kf values: "<< Kf << std::endl;
  IntegerVector Lf(1);
  Lf[0]  = RcppDeepState_int();
  std::string Lf_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_3d/AFL_rcpp_3d/afl_inputs/" + std::to_string(t) + "_Lf.qs";
  qs::c_qsave(Lf,Lf_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Lf values: "<< Lf << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    rcpp_3d(jf[0],kf[0],lf[0],Jf[0],Kf[0],Lf[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
