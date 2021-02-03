#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericVector computeStdNormCdf(Rcpp::NumericVector x_);

TEST(ffstream_deepstate_test,computeStdNormCdf_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector x_  = RcppDeepState_NumericVector();
  std::string x__t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ffstream/inst/testfiles/computeStdNormCdf/libFuzzer_computeStdNormCdf/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_x_.qs";
  qs::c_qsave(x_,x__t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x_ values: "<< x_ << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    computeStdNormCdf(x_);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
