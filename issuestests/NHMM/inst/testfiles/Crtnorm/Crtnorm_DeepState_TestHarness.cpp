#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericVector Crtnorm(int a, Rcpp::NumericVector muf, Rcpp::NumericVector sigf, Rcpp::NumericVector lowf, Rcpp::NumericVector upf, Rcpp::NumericVector boolowf, Rcpp::NumericVector booupf);

TEST(NHMM_deepstate_test,Crtnorm_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector a(1);
  a[0]  = RcppDeepState_int();
  qs::c_qsave(a,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/Crtnorm/inputs/a.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "a values: "<< a << std::endl;
  NumericVector muf  = RcppDeepState_NumericVector();
  qs::c_qsave(muf,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/Crtnorm/inputs/muf.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "muf values: "<< muf << std::endl;
  NumericVector sigf  = RcppDeepState_NumericVector();
  qs::c_qsave(sigf,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/Crtnorm/inputs/sigf.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "sigf values: "<< sigf << std::endl;
  NumericVector lowf  = RcppDeepState_NumericVector();
  qs::c_qsave(lowf,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/Crtnorm/inputs/lowf.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lowf values: "<< lowf << std::endl;
  NumericVector upf  = RcppDeepState_NumericVector();
  qs::c_qsave(upf,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/Crtnorm/inputs/upf.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "upf values: "<< upf << std::endl;
  NumericVector boolowf  = RcppDeepState_NumericVector();
  qs::c_qsave(boolowf,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/Crtnorm/inputs/boolowf.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "boolowf values: "<< boolowf << std::endl;
  NumericVector booupf  = RcppDeepState_NumericVector();
  qs::c_qsave(booupf,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/Crtnorm/inputs/booupf.qs",
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
