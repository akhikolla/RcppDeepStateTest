#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double dresscrps_cpp(NumericVector m, NumericVector s, double y);

TEST(SpecsVerification_deepstate_test,dresscrps_cpp_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector m  = RcppDeepState_NumericVector();
  std::string m_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/SpecsVerification/inst/testfiles/dresscrps_cpp/libFuzzer_dresscrps_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_m.qs";
  qs::c_qsave(m,m_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "m values: "<< m << std::endl;
  NumericVector s  = RcppDeepState_NumericVector();
  std::string s_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/SpecsVerification/inst/testfiles/dresscrps_cpp/libFuzzer_dresscrps_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_s.qs";
  qs::c_qsave(s,s_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "s values: "<< s << std::endl;
  NumericVector y(1);
  y[0]  = RcppDeepState_double();
  std::string y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/SpecsVerification/inst/testfiles/dresscrps_cpp/libFuzzer_dresscrps_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_y.qs";
  qs::c_qsave(y,y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    dresscrps_cpp(m,s,y[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
