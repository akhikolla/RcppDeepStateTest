#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::List immer_cml_splitvec(Rcpp::NumericVector esf_par1, Rcpp::IntegerVector splitvec_len_pp);

TEST(immer_deepstate_test,immer_cml_splitvec_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector esf_par1  = RcppDeepState_NumericVector();
  std::string esf_par1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_cml_splitvec/libFuzzer_immer_cml_splitvec/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_esf_par1.qs";
  qs::c_qsave(esf_par1,esf_par1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "esf_par1 values: "<< esf_par1 << std::endl;
  IntegerVector splitvec_len_pp  = RcppDeepState_IntegerVector();
  std::string splitvec_len_pp_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_cml_splitvec/libFuzzer_immer_cml_splitvec/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_splitvec_len_pp.qs";
  qs::c_qsave(splitvec_len_pp,splitvec_len_pp_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "splitvec_len_pp values: "<< splitvec_len_pp << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    immer_cml_splitvec(esf_par1,splitvec_len_pp);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
