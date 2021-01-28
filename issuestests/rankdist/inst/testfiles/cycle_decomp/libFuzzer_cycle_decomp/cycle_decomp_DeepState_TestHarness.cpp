#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

int cycle_decomp(NumericVector comp);

TEST(rankdist_deepstate_test,cycle_decomp_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector comp  = RcppDeepState_NumericVector();
  std::string comp_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rankdist/inst/testfiles/cycle_decomp/libFuzzer_cycle_decomp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_comp.qs";
  qs::c_qsave(comp,comp_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "comp values: "<< comp << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    cycle_decomp(comp);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
