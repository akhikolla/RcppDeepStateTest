#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double rv(NumericVector a, NumericVector b, int na, int period, NumericVector tmpa, NumericVector tmpb, int tmpna);

TEST(highfrequency_deepstate_test,rv_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector a  = RcppDeepState_NumericVector();
  std::string a_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/rv/AFL_rv/afl_inputs/" + std::to_string(t) + "_a.qs";
  qs::c_qsave(a,a_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "a values: "<< a << std::endl;
  NumericVector b  = RcppDeepState_NumericVector();
  std::string b_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/rv/AFL_rv/afl_inputs/" + std::to_string(t) + "_b.qs";
  qs::c_qsave(b,b_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "b values: "<< b << std::endl;
  IntegerVector na(1);
  na[0]  = RcppDeepState_int();
  std::string na_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/rv/AFL_rv/afl_inputs/" + std::to_string(t) + "_na.qs";
  qs::c_qsave(na,na_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "na values: "<< na << std::endl;
  IntegerVector period(1);
  period[0]  = RcppDeepState_int();
  std::string period_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/rv/AFL_rv/afl_inputs/" + std::to_string(t) + "_period.qs";
  qs::c_qsave(period,period_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "period values: "<< period << std::endl;
  NumericVector tmpa  = RcppDeepState_NumericVector();
  std::string tmpa_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/rv/AFL_rv/afl_inputs/" + std::to_string(t) + "_tmpa.qs";
  qs::c_qsave(tmpa,tmpa_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tmpa values: "<< tmpa << std::endl;
  NumericVector tmpb  = RcppDeepState_NumericVector();
  std::string tmpb_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/rv/AFL_rv/afl_inputs/" + std::to_string(t) + "_tmpb.qs";
  qs::c_qsave(tmpb,tmpb_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tmpb values: "<< tmpb << std::endl;
  IntegerVector tmpna(1);
  tmpna[0]  = RcppDeepState_int();
  std::string tmpna_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/rv/AFL_rv/afl_inputs/" + std::to_string(t) + "_tmpna.qs";
  qs::c_qsave(tmpna,tmpna_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tmpna values: "<< tmpna << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    rv(a,b,na[0],period[0],tmpa,tmpb,tmpna[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
