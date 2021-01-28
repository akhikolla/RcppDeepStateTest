#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector FindCayley(NumericMatrix obs, NumericVector pi0);

TEST(rankdist_deepstate_test,FindCayley_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix obs  = RcppDeepState_NumericMatrix();
  std::string obs_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rankdist/inst/testfiles/FindCayley/libFuzzer_FindCayley/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_obs.qs";
  qs::c_qsave(obs,obs_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "obs values: "<< obs << std::endl;
  NumericVector pi0  = RcppDeepState_NumericVector();
  std::string pi0_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rankdist/inst/testfiles/FindCayley/libFuzzer_FindCayley/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_pi0.qs";
  qs::c_qsave(pi0,pi0_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pi0 values: "<< pi0 << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    FindCayley(obs,pi0);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
