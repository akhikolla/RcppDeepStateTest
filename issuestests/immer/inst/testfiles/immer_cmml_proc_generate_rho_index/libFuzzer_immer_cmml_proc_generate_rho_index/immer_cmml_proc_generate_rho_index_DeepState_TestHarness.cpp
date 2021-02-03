#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::IntegerMatrix immer_cmml_proc_generate_rho_index(int I);

TEST(immer_deepstate_test,immer_cmml_proc_generate_rho_index_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector I(1);
  I[0]  = RcppDeepState_int();
  std::string I_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_cmml_proc_generate_rho_index/libFuzzer_immer_cmml_proc_generate_rho_index/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_I.qs";
  qs::c_qsave(I,I_t,
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
