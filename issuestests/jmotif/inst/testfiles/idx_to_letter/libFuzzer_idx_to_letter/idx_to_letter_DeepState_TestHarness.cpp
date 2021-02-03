#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

char idx_to_letter(int idx);

TEST(jmotif_deepstate_test,idx_to_letter_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector idx(1);
  idx[0]  = RcppDeepState_int();
  std::string idx_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/jmotif/inst/testfiles/idx_to_letter/libFuzzer_idx_to_letter/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_idx.qs";
  qs::c_qsave(idx,idx_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "idx values: "<< idx << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    idx_to_letter(idx[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
