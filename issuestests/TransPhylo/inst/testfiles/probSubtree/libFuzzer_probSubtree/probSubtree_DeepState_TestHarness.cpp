#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double probSubtree(NumericMatrix tab, double rate);

TEST(TransPhylo_deepstate_test,probSubtree_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix tab  = RcppDeepState_NumericMatrix();
  std::string tab_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/TransPhylo/inst/testfiles/probSubtree/libFuzzer_probSubtree/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_tab.qs";
  qs::c_qsave(tab,tab_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tab values: "<< tab << std::endl;
  NumericVector rate(1);
  rate[0]  = RcppDeepState_double();
  std::string rate_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/TransPhylo/inst/testfiles/probSubtree/libFuzzer_probSubtree/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_rate.qs";
  qs::c_qsave(rate,rate_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "rate values: "<< rate << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    probSubtree(tab,rate[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
