#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector gradlik_pw(NumericVector par, NumericMatrix Dm, NumericVector eta, IntegerVector breaks);

TEST(icensmis_deepstate_test,gradlik_pw_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector par  = RcppDeepState_NumericVector();
  std::string par_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icensmis/inst/testfiles/gradlik_pw/libFuzzer_gradlik_pw/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_par.qs";
  qs::c_qsave(par,par_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "par values: "<< par << std::endl;
  NumericMatrix Dm  = RcppDeepState_NumericMatrix();
  std::string Dm_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icensmis/inst/testfiles/gradlik_pw/libFuzzer_gradlik_pw/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Dm.qs";
  qs::c_qsave(Dm,Dm_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Dm values: "<< Dm << std::endl;
  NumericVector eta  = RcppDeepState_NumericVector();
  std::string eta_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icensmis/inst/testfiles/gradlik_pw/libFuzzer_gradlik_pw/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_eta.qs";
  qs::c_qsave(eta,eta_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "eta values: "<< eta << std::endl;
  IntegerVector breaks  = RcppDeepState_IntegerVector();
  std::string breaks_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icensmis/inst/testfiles/gradlik_pw/libFuzzer_gradlik_pw/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_breaks.qs";
  qs::c_qsave(breaks,breaks_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "breaks values: "<< breaks << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    gradlik_pw(par,Dm,eta,breaks);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
