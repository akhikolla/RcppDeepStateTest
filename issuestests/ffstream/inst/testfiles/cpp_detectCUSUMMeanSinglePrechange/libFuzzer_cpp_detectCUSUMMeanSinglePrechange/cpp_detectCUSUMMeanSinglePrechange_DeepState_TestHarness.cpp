#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::List cpp_detectCUSUMMeanSinglePrechange(Rcpp::NumericVector x, double k, double h, double prechangeMean, double prechangeSigma);

TEST(ffstream_deepstate_test,cpp_detectCUSUMMeanSinglePrechange_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ffstream/inst/testfiles/cpp_detectCUSUMMeanSinglePrechange/libFuzzer_cpp_detectCUSUMMeanSinglePrechange/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector k(1);
  k[0]  = RcppDeepState_double();
  std::string k_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ffstream/inst/testfiles/cpp_detectCUSUMMeanSinglePrechange/libFuzzer_cpp_detectCUSUMMeanSinglePrechange/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_k.qs";
  qs::c_qsave(k,k_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "k values: "<< k << std::endl;
  NumericVector h(1);
  h[0]  = RcppDeepState_double();
  std::string h_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ffstream/inst/testfiles/cpp_detectCUSUMMeanSinglePrechange/libFuzzer_cpp_detectCUSUMMeanSinglePrechange/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_h.qs";
  qs::c_qsave(h,h_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "h values: "<< h << std::endl;
  NumericVector prechangeMean(1);
  prechangeMean[0]  = RcppDeepState_double();
  std::string prechangeMean_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ffstream/inst/testfiles/cpp_detectCUSUMMeanSinglePrechange/libFuzzer_cpp_detectCUSUMMeanSinglePrechange/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_prechangeMean.qs";
  qs::c_qsave(prechangeMean,prechangeMean_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "prechangeMean values: "<< prechangeMean << std::endl;
  NumericVector prechangeSigma(1);
  prechangeSigma[0]  = RcppDeepState_double();
  std::string prechangeSigma_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ffstream/inst/testfiles/cpp_detectCUSUMMeanSinglePrechange/libFuzzer_cpp_detectCUSUMMeanSinglePrechange/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_prechangeSigma.qs";
  qs::c_qsave(prechangeSigma,prechangeSigma_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "prechangeSigma values: "<< prechangeSigma << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    cpp_detectCUSUMMeanSinglePrechange(x,k[0],h[0],prechangeMean[0],prechangeSigma[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
