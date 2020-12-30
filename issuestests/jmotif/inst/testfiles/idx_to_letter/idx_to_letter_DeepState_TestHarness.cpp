#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

char idx_to_letter(int idx);

TEST(jmotif_deepstate_test,idx_to_letter_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector idx(1);
  idx[0]  = RcppDeepState_int();
  qs::c_qsave(idx,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/jmotif/inst/testfiles/idx_to_letter/inputs/idx.qs",
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
