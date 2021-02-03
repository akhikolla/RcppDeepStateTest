#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericVector make_integral_density_multilevel(Rcpp::NumericVector density);

TEST(imagerExtra_deepstate_test,make_integral_density_multilevel_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector density  = RcppDeepState_NumericVector();
  std::string density_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/make_integral_density_multilevel/libFuzzer_make_integral_density_multilevel/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_density.qs";
  qs::c_qsave(density,density_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "density values: "<< density << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    make_integral_density_multilevel(density);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
