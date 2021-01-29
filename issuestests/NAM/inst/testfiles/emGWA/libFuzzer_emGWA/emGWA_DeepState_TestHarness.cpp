#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

SEXP emGWA(NumericVector y, NumericMatrix gen);

TEST(NAM_deepstate_test,emGWA_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  std::string y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/emGWA/libFuzzer_emGWA/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_y.qs";
  qs::c_qsave(y,y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericMatrix gen  = RcppDeepState_NumericMatrix();
  std::string gen_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/emGWA/libFuzzer_emGWA/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_gen.qs";
  qs::c_qsave(gen,gen_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "gen values: "<< gen << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    emGWA(y,gen);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
