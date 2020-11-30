#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::List immer_cmml_proc_generate_tau(Rcpp::IntegerVector maxK, int K);

TEST(immer_deepstate_test,immer_cmml_proc_generate_tau_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector maxK  = RcppDeepState_IntegerVector();
  qs::c_qsave(maxK,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_cmml_proc_generate_tau/inputs/maxK.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "maxK values: "<< maxK << std::endl;
  IntegerVector K(1);
  K[0]  = RcppDeepState_int();
  qs::c_qsave(K,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_cmml_proc_generate_tau/inputs/K.qs",
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
