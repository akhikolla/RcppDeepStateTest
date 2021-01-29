#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double BMNLLInner(double a, double b, NumericVector zetas, NumericVector fi, NumericVector ti);

TEST(RJafroc_deepstate_test,BMNLLInner_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector a(1);
  a[0]  = RcppDeepState_double();
  std::string a_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/BMNLLInner/libFuzzer_BMNLLInner/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_a.qs";
  qs::c_qsave(a,a_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "a values: "<< a << std::endl;
  NumericVector b(1);
  b[0]  = RcppDeepState_double();
  std::string b_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/BMNLLInner/libFuzzer_BMNLLInner/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_b.qs";
  qs::c_qsave(b,b_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "b values: "<< b << std::endl;
  NumericVector zetas  = RcppDeepState_NumericVector();
  std::string zetas_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/BMNLLInner/libFuzzer_BMNLLInner/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_zetas.qs";
  qs::c_qsave(zetas,zetas_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "zetas values: "<< zetas << std::endl;
  NumericVector fi  = RcppDeepState_NumericVector();
  std::string fi_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/BMNLLInner/libFuzzer_BMNLLInner/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_fi.qs";
  qs::c_qsave(fi,fi_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "fi values: "<< fi << std::endl;
  NumericVector ti  = RcppDeepState_NumericVector();
  std::string ti_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/BMNLLInner/libFuzzer_BMNLLInner/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_ti.qs";
  qs::c_qsave(ti,ti_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ti values: "<< ti << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    BMNLLInner(a[0],b[0],zetas,fi,ti);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
