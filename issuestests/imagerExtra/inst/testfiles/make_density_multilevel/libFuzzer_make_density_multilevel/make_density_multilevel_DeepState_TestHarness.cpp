#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericVector make_density_multilevel(Rcpp::NumericVector ordered, Rcpp::NumericVector interval);

TEST(imagerExtra_deepstate_test,make_density_multilevel_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector ordered  = RcppDeepState_NumericVector();
  std::string ordered_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/make_density_multilevel/libFuzzer_make_density_multilevel/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_ordered.qs";
  qs::c_qsave(ordered,ordered_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ordered values: "<< ordered << std::endl;
  NumericVector interval  = RcppDeepState_NumericVector();
  std::string interval_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/make_density_multilevel/libFuzzer_make_density_multilevel/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_interval.qs";
  qs::c_qsave(interval,interval_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "interval values: "<< interval << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    make_density_multilevel(ordered,interval);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
