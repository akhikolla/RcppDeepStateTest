#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List prob2IntFreq(NumericVector pIn, int pop);

TEST(humanleague_deepstate_test,prob2IntFreq_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector pIn  = RcppDeepState_NumericVector();
  std::string pIn_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/humanleague/inst/testfiles/prob2IntFreq/libFuzzer_prob2IntFreq/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_pIn.qs";
  qs::c_qsave(pIn,pIn_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pIn values: "<< pIn << std::endl;
  IntegerVector pop(1);
  pop[0]  = RcppDeepState_int();
  std::string pop_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/humanleague/inst/testfiles/prob2IntFreq/libFuzzer_prob2IntFreq/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_pop.qs";
  qs::c_qsave(pop,pop_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pop values: "<< pop << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    prob2IntFreq(pIn,pop[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
