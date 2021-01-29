#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

IntegerVector solve_interval_partition(NumericMatrix x, const int kmax);

TEST(RcppDynProg_deepstate_test,solve_interval_partition_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix x  = RcppDeepState_NumericMatrix();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RcppDynProg/inst/testfiles/solve_interval_partition/libFuzzer_solve_interval_partition/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  IntegerVector kmax(1);
  kmax[0]  = RcppDeepState_int();
  std::string kmax_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RcppDynProg/inst/testfiles/solve_interval_partition/libFuzzer_solve_interval_partition/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_kmax.qs";
  qs::c_qsave(kmax,kmax_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "kmax values: "<< kmax << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    solve_interval_partition(x,kmax[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
