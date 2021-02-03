#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::List cpp_detectAFFMeanMultiple(Rcpp::NumericVector x, double alpha, double eta, int BL);

TEST(ffstream_deepstate_test,cpp_detectAFFMeanMultiple_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ffstream/inst/testfiles/cpp_detectAFFMeanMultiple/libFuzzer_cpp_detectAFFMeanMultiple/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector alpha(1);
  alpha[0]  = RcppDeepState_double();
  std::string alpha_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ffstream/inst/testfiles/cpp_detectAFFMeanMultiple/libFuzzer_cpp_detectAFFMeanMultiple/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_alpha.qs";
  qs::c_qsave(alpha,alpha_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "alpha values: "<< alpha << std::endl;
  NumericVector eta(1);
  eta[0]  = RcppDeepState_double();
  std::string eta_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ffstream/inst/testfiles/cpp_detectAFFMeanMultiple/libFuzzer_cpp_detectAFFMeanMultiple/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_eta.qs";
  qs::c_qsave(eta,eta_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "eta values: "<< eta << std::endl;
  IntegerVector BL(1);
  BL[0]  = RcppDeepState_int();
  std::string BL_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ffstream/inst/testfiles/cpp_detectAFFMeanMultiple/libFuzzer_cpp_detectAFFMeanMultiple/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_BL.qs";
  qs::c_qsave(BL,BL_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "BL values: "<< BL << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    cpp_detectAFFMeanMultiple(x,alpha[0],eta[0],BL[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
