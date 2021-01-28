#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

int interval_match(double proportion, NumericVector references);

TEST(AGread_deepstate_test,interval_match_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector proportion(1);
  proportion[0]  = RcppDeepState_double();
  std::string proportion_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/AGread/inst/testfiles/interval_match/libFuzzer_interval_match/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_proportion.qs";
  qs::c_qsave(proportion,proportion_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "proportion values: "<< proportion << std::endl;
  NumericVector references  = RcppDeepState_NumericVector();
  std::string references_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/AGread/inst/testfiles/interval_match/libFuzzer_interval_match/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_references.qs";
  qs::c_qsave(references,references_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "references values: "<< references << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    interval_match(proportion[0],references);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
