#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::List immer_cmml_proc_generate_tau(Rcpp::IntegerVector maxK, int K);

TEST(immer_deepstate_test,immer_cmml_proc_generate_tau_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector maxK  = RcppDeepState_IntegerVector();
  std::string maxK_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_cmml_proc_generate_tau/libFuzzer_immer_cmml_proc_generate_tau/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_maxK.qs";
  qs::c_qsave(maxK,maxK_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "maxK values: "<< maxK << std::endl;
  IntegerVector K(1);
  K[0]  = RcppDeepState_int();
  std::string K_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_cmml_proc_generate_tau/libFuzzer_immer_cmml_proc_generate_tau/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_K.qs";
  qs::c_qsave(K,K_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "K values: "<< K << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    immer_cmml_proc_generate_tau(maxK,K[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
