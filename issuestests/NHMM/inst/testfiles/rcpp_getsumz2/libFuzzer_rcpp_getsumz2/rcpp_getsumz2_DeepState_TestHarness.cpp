#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericVector rcpp_getsumz2(int llf, int LLf, int Kf, int Jf, int Tf, Rcpp::NumericVector zf, Rcpp::NumericVector Sigmainvf, Rcpp::NumericVector in2f, Rcpp::NumericMatrix yf, Rcpp::NumericMatrix betaemf, Rcpp::NumericMatrix betaem0f);

TEST(NHMM_deepstate_test,rcpp_getsumz2_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector llf(1);
  llf[0]  = RcppDeepState_int();
  std::string llf_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getsumz2/libFuzzer_rcpp_getsumz2/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_llf.qs";
  qs::c_qsave(llf,llf_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "llf values: "<< llf << std::endl;
  IntegerVector LLf(1);
  LLf[0]  = RcppDeepState_int();
  std::string LLf_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getsumz2/libFuzzer_rcpp_getsumz2/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_LLf.qs";
  qs::c_qsave(LLf,LLf_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "LLf values: "<< LLf << std::endl;
  IntegerVector Kf(1);
  Kf[0]  = RcppDeepState_int();
  std::string Kf_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getsumz2/libFuzzer_rcpp_getsumz2/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Kf.qs";
  qs::c_qsave(Kf,Kf_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Kf values: "<< Kf << std::endl;
  IntegerVector Jf(1);
  Jf[0]  = RcppDeepState_int();
  std::string Jf_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getsumz2/libFuzzer_rcpp_getsumz2/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Jf.qs";
  qs::c_qsave(Jf,Jf_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Jf values: "<< Jf << std::endl;
  IntegerVector Tf(1);
  Tf[0]  = RcppDeepState_int();
  std::string Tf_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getsumz2/libFuzzer_rcpp_getsumz2/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Tf.qs";
  qs::c_qsave(Tf,Tf_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Tf values: "<< Tf << std::endl;
  NumericVector zf  = RcppDeepState_NumericVector();
  std::string zf_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getsumz2/libFuzzer_rcpp_getsumz2/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_zf.qs";
  qs::c_qsave(zf,zf_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "zf values: "<< zf << std::endl;
  NumericVector Sigmainvf  = RcppDeepState_NumericVector();
  std::string Sigmainvf_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getsumz2/libFuzzer_rcpp_getsumz2/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Sigmainvf.qs";
  qs::c_qsave(Sigmainvf,Sigmainvf_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Sigmainvf values: "<< Sigmainvf << std::endl;
  NumericVector in2f  = RcppDeepState_NumericVector();
  std::string in2f_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getsumz2/libFuzzer_rcpp_getsumz2/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_in2f.qs";
  qs::c_qsave(in2f,in2f_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "in2f values: "<< in2f << std::endl;
  NumericMatrix yf  = RcppDeepState_NumericMatrix();
  std::string yf_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getsumz2/libFuzzer_rcpp_getsumz2/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_yf.qs";
  qs::c_qsave(yf,yf_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "yf values: "<< yf << std::endl;
  NumericMatrix betaemf  = RcppDeepState_NumericMatrix();
  std::string betaemf_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getsumz2/libFuzzer_rcpp_getsumz2/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_betaemf.qs";
  qs::c_qsave(betaemf,betaemf_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "betaemf values: "<< betaemf << std::endl;
  NumericMatrix betaem0f  = RcppDeepState_NumericMatrix();
  std::string betaem0f_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getsumz2/libFuzzer_rcpp_getsumz2/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_betaem0f.qs";
  qs::c_qsave(betaem0f,betaem0f_t,
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
