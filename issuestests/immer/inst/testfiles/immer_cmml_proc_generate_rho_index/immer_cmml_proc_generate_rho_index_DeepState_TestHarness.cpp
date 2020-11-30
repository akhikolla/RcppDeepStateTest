#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::IntegerMatrix immer_cmml_proc_generate_rho_index(int I);

TEST(immer_deepstate_test,immer_cmml_proc_generate_rho_index_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector I(1);
  I[0]  = RcppDeepState_int();
  qs::c_qsave(I,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_cmml_proc_generate_rho_index/inputs/I.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "I values: "<< I << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    immer_cmml_proc_generate_rho_index(I[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
