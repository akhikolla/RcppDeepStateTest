#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericVector immer_cml_extract_parmindex(Rcpp::NumericMatrix esf_par0, Rcpp::IntegerVector parm_index_pp);

TEST(immer_deepstate_test,immer_cml_extract_parmindex_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix esf_par0  = RcppDeepState_NumericMatrix();
  std::string esf_par0_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_cml_extract_parmindex/AFL_immer_cml_extract_parmindex/afl_inputs/" + std::to_string(t) + "_esf_par0.qs";
  qs::c_qsave(esf_par0,esf_par0_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "esf_par0 values: "<< esf_par0 << std::endl;
  IntegerVector parm_index_pp  = RcppDeepState_IntegerVector();
  std::string parm_index_pp_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_cml_extract_parmindex/AFL_immer_cml_extract_parmindex/afl_inputs/" + std::to_string(t) + "_parm_index_pp.qs";
  qs::c_qsave(parm_index_pp,parm_index_pp_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "parm_index_pp values: "<< parm_index_pp << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    immer_cml_extract_parmindex(esf_par0,parm_index_pp);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
