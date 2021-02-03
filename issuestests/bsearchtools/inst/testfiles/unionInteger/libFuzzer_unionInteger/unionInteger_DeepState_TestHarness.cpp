#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::IntegerVector unionInteger(Rcpp::IntegerVector vec1, Rcpp::IntegerVector vec2);

TEST(bsearchtools_deepstate_test,unionInteger_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector vec1  = RcppDeepState_IntegerVector();
  std::string vec1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/bsearchtools/inst/testfiles/unionInteger/libFuzzer_unionInteger/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_vec1.qs";
  qs::c_qsave(vec1,vec1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "vec1 values: "<< vec1 << std::endl;
  IntegerVector vec2  = RcppDeepState_IntegerVector();
  std::string vec2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/bsearchtools/inst/testfiles/unionInteger/libFuzzer_unionInteger/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_vec2.qs";
  qs::c_qsave(vec2,vec2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "vec2 values: "<< vec2 << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    unionInteger(vec1,vec2);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
