#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::List cpp_detectEWMAMeanSinglePrechange(Rcpp::NumericVector x, double r, double L, double prechangeMean, double prechangeSigma);

TEST(ffstream_deepstate_test,cpp_detectEWMAMeanSinglePrechange_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ffstream/inst/testfiles/cpp_detectEWMAMeanSinglePrechange/libFuzzer_cpp_detectEWMAMeanSinglePrechange/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector r(1);
  r[0]  = RcppDeepState_double();
  std::string r_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ffstream/inst/testfiles/cpp_detectEWMAMeanSinglePrechange/libFuzzer_cpp_detectEWMAMeanSinglePrechange/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_r.qs";
  qs::c_qsave(r,r_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "r values: "<< r << std::endl;
  NumericVector L(1);
  L[0]  = RcppDeepState_double();
  std::string L_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ffstream/inst/testfiles/cpp_detectEWMAMeanSinglePrechange/libFuzzer_cpp_detectEWMAMeanSinglePrechange/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_L.qs";
  qs::c_qsave(L,L_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "L values: "<< L << std::endl;
  NumericVector prechangeMean(1);
  prechangeMean[0]  = RcppDeepState_double();
  std::string prechangeMean_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ffstream/inst/testfiles/cpp_detectEWMAMeanSinglePrechange/libFuzzer_cpp_detectEWMAMeanSinglePrechange/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_prechangeMean.qs";
  qs::c_qsave(prechangeMean,prechangeMean_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "prechangeMean values: "<< prechangeMean << std::endl;
  NumericVector prechangeSigma(1);
  prechangeSigma[0]  = RcppDeepState_double();
  std::string prechangeSigma_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ffstream/inst/testfiles/cpp_detectEWMAMeanSinglePrechange/libFuzzer_cpp_detectEWMAMeanSinglePrechange/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_prechangeSigma.qs";
  qs::c_qsave(prechangeSigma,prechangeSigma_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "prechangeSigma values: "<< prechangeSigma << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    cpp_detectEWMAMeanSinglePrechange(x,r[0],L[0],prechangeMean[0],prechangeSigma[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
