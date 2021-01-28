#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

IntegerVector scps_coord(NumericVector prob, NumericMatrix x, NumericVector rand);

TEST(BalancedSampling_deepstate_test,scps_coord_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector prob  = RcppDeepState_NumericVector();
  std::string prob_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BalancedSampling/inst/testfiles/scps_coord/libFuzzer_scps_coord/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_prob.qs";
  qs::c_qsave(prob,prob_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "prob values: "<< prob << std::endl;
  NumericMatrix x  = RcppDeepState_NumericMatrix();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BalancedSampling/inst/testfiles/scps_coord/libFuzzer_scps_coord/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector rand  = RcppDeepState_NumericVector();
  std::string rand_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BalancedSampling/inst/testfiles/scps_coord/libFuzzer_scps_coord/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_rand.qs";
  qs::c_qsave(rand,rand_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "rand values: "<< rand << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    scps_coord(prob,x,rand);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
