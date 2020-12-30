#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericVector rcpp_getsumz2(int llf, int LLf, int Kf, int Jf, int Tf, Rcpp::NumericVector zf, Rcpp::NumericVector Sigmainvf, Rcpp::NumericVector in2f, Rcpp::NumericMatrix yf, Rcpp::NumericMatrix betaemf, Rcpp::NumericMatrix betaem0f);

TEST(NHMM_deepstate_test,rcpp_getsumz2_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector llf(1);
  llf[0]  = RcppDeepState_int();
  qs::c_qsave(llf,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getsumz2/inputs/llf.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "llf values: "<< llf << std::endl;
  IntegerVector LLf(1);
  LLf[0]  = RcppDeepState_int();
  qs::c_qsave(LLf,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getsumz2/inputs/LLf.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "LLf values: "<< LLf << std::endl;
  IntegerVector Kf(1);
  Kf[0]  = RcppDeepState_int();
  qs::c_qsave(Kf,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getsumz2/inputs/Kf.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Kf values: "<< Kf << std::endl;
  IntegerVector Jf(1);
  Jf[0]  = RcppDeepState_int();
  qs::c_qsave(Jf,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getsumz2/inputs/Jf.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Jf values: "<< Jf << std::endl;
  IntegerVector Tf(1);
  Tf[0]  = RcppDeepState_int();
  qs::c_qsave(Tf,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getsumz2/inputs/Tf.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Tf values: "<< Tf << std::endl;
  NumericVector zf  = RcppDeepState_NumericVector();
  qs::c_qsave(zf,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getsumz2/inputs/zf.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "zf values: "<< zf << std::endl;
  NumericVector Sigmainvf  = RcppDeepState_NumericVector();
  qs::c_qsave(Sigmainvf,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getsumz2/inputs/Sigmainvf.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Sigmainvf values: "<< Sigmainvf << std::endl;
  NumericVector in2f  = RcppDeepState_NumericVector();
  qs::c_qsave(in2f,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getsumz2/inputs/in2f.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "in2f values: "<< in2f << std::endl;
  NumericMatrix yf  = RcppDeepState_NumericMatrix();
  qs::c_qsave(yf,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getsumz2/inputs/yf.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "yf values: "<< yf << std::endl;
  NumericMatrix betaemf  = RcppDeepState_NumericMatrix();
  qs::c_qsave(betaemf,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getsumz2/inputs/betaemf.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "betaemf values: "<< betaemf << std::endl;
  NumericMatrix betaem0f  = RcppDeepState_NumericMatrix();
  qs::c_qsave(betaem0f,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getsumz2/inputs/betaem0f.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "betaem0f values: "<< betaem0f << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    rcpp_getsumz2(llf[0],LLf[0],Kf[0],Jf[0],Tf[0],zf,Sigmainvf,in2f,yf,betaemf,betaem0f);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
