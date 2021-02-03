#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double loglikPLMIX(NumericMatrix p, NumericMatrix ref_order, NumericVector weights, NumericMatrix pi_inv);

TEST(PLMIX_deepstate_test,loglikPLMIX_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix p  = RcppDeepState_NumericMatrix();
  std::string p_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/loglikPLMIX/AFL_loglikPLMIX/afl_inputs/" + std::to_string(t) + "_p.qs";
  qs::c_qsave(p,p_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "p values: "<< p << std::endl;
  NumericMatrix ref_order  = RcppDeepState_NumericMatrix();
  std::string ref_order_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/loglikPLMIX/AFL_loglikPLMIX/afl_inputs/" + std::to_string(t) + "_ref_order.qs";
  qs::c_qsave(ref_order,ref_order_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ref_order values: "<< ref_order << std::endl;
  NumericVector weights  = RcppDeepState_NumericVector();
  std::string weights_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/loglikPLMIX/AFL_loglikPLMIX/afl_inputs/" + std::to_string(t) + "_weights.qs";
  qs::c_qsave(weights,weights_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "weights values: "<< weights << std::endl;
  NumericMatrix pi_inv  = RcppDeepState_NumericMatrix();
  std::string p_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/loglikPLMIX/AFL_loglikPLMIX/afl_inputs/" + std::to_string(t) + "_p.qs";
  std::string pi_inv_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/loglikPLMIX/AFL_loglikPLMIX/afl_inputs/" + std::to_string(t) + "_pi_inv.qs";
  qs::c_qsave(pi_inv,pi_inv_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pi_inv values: "<< pi_inv << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    loglikPLMIX(p,ref_order,weights,pi_inv);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
