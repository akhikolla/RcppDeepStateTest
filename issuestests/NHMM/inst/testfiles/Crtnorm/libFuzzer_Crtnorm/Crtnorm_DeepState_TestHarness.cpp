#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericVector Crtnorm(int a, Rcpp::NumericVector muf, Rcpp::NumericVector sigf, Rcpp::NumericVector lowf, Rcpp::NumericVector upf, Rcpp::NumericVector boolowf, Rcpp::NumericVector booupf);

TEST(NHMM_deepstate_test,Crtnorm_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector a(1);
  a[0]  = RcppDeepState_int();
  std::string a_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/Crtnorm/libFuzzer_Crtnorm/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_a.qs";
  qs::c_qsave(a,a_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "a values: "<< a << std::endl;
  NumericVector muf  = RcppDeepState_NumericVector();
  std::string muf_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/Crtnorm/libFuzzer_Crtnorm/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_muf.qs";
  qs::c_qsave(muf,muf_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "muf values: "<< muf << std::endl;
  NumericVector sigf  = RcppDeepState_NumericVector();
  std::string sigf_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/Crtnorm/libFuzzer_Crtnorm/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_sigf.qs";
  qs::c_qsave(sigf,sigf_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "sigf values: "<< sigf << std::endl;
  NumericVector lowf  = RcppDeepState_NumericVector();
  std::string lowf_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/Crtnorm/libFuzzer_Crtnorm/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_lowf.qs";
  qs::c_qsave(lowf,lowf_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lowf values: "<< lowf << std::endl;
  NumericVector upf  = RcppDeepState_NumericVector();
  std::string upf_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/Crtnorm/libFuzzer_Crtnorm/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_upf.qs";
  qs::c_qsave(upf,upf_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "upf values: "<< upf << std::endl;
  NumericVector boolowf  = RcppDeepState_NumericVector();
  std::string boolowf_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/Crtnorm/libFuzzer_Crtnorm/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_boolowf.qs";
  qs::c_qsave(boolowf,boolowf_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "boolowf values: "<< boolowf << std::endl;
  NumericVector booupf  = RcppDeepState_NumericVector();
  std::string booupf_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/Crtnorm/libFuzzer_Crtnorm/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_booupf.qs";
  qs::c_qsave(booupf,booupf_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "booupf values: "<< booupf << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    Crtnorm(a[0],muf,sigf,lowf,upf,boolowf,booupf);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
