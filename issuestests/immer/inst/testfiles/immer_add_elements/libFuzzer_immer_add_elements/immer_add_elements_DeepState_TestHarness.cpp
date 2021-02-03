#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericVector immer_add_elements(Rcpp::NumericVector x, int pos, double h);

TEST(immer_deepstate_test,immer_add_elements_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_add_elements/libFuzzer_immer_add_elements/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  IntegerVector pos(1);
  pos[0]  = RcppDeepState_int();
  std::string pos_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_add_elements/libFuzzer_immer_add_elements/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_pos.qs";
  qs::c_qsave(pos,pos_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pos values: "<< pos << std::endl;
  NumericVector h(1);
  h[0]  = RcppDeepState_double();
  std::string h_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_add_elements/libFuzzer_immer_add_elements/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_h.qs";
  qs::c_qsave(h,h_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "h values: "<< h << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    immer_add_elements(x,pos[0],h[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
