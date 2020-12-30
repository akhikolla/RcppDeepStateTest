#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericMatrix rcpp_getsumz1(int Kf, int Jf, int Tf, Rcpp::NumericVector zf, Rcpp::NumericVector Sigmainvf, Rcpp::NumericMatrix in2f);

TEST(NHMM_deepstate_test,rcpp_getsumz1_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector Kf(1);
  Kf[0]  = RcppDeepState_int();
  qs::c_qsave(Kf,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getsumz1/inputs/Kf.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Kf values: "<< Kf << std::endl;
  IntegerVector Jf(1);
  Jf[0]  = RcppDeepState_int();
  qs::c_qsave(Jf,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getsumz1/inputs/Jf.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Jf values: "<< Jf << std::endl;
  IntegerVector Tf(1);
  Tf[0]  = RcppDeepState_int();
  qs::c_qsave(Tf,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getsumz1/inputs/Tf.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Tf values: "<< Tf << std::endl;
  NumericVector zf  = RcppDeepState_NumericVector();
  qs::c_qsave(zf,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getsumz1/inputs/zf.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "zf values: "<< zf << std::endl;
  NumericVector Sigmainvf  = RcppDeepState_NumericVector();
  qs::c_qsave(Sigmainvf,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getsumz1/inputs/Sigmainvf.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Sigmainvf values: "<< Sigmainvf << std::endl;
  NumericMatrix in2f  = RcppDeepState_NumericMatrix();
  qs::c_qsave(in2f,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getsumz1/inputs/in2f.qs",
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
