#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::IntegerVector tipsSafe(Rcpp::IntegerVector ances, Rcpp::IntegerVector desc);

TEST(phylobase_deepstate_test,tipsSafe_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector ances  = RcppDeepState_IntegerVector();
  std::string ances_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/phylobase/inst/testfiles/tipsSafe/libFuzzer_tipsSafe/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_ances.qs";
  qs::c_qsave(ances,ances_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ances values: "<< ances << std::endl;
  IntegerVector desc  = RcppDeepState_IntegerVector();
  std::string desc_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/phylobase/inst/testfiles/tipsSafe/libFuzzer_tipsSafe/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_desc.qs";
  qs::c_qsave(desc,desc_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "desc values: "<< desc << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    tipsSafe(ances,desc);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
