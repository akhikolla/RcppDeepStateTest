#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

IntegerVector solve_interval_partition(NumericMatrix x, const int kmax);

TEST(RcppDynProg_deepstate_test,solve_interval_partition_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix x  = RcppDeepState_NumericMatrix();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RcppDynProg/inst/testfiles/solve_interval_partition/AFL_solve_interval_partition/afl_inputs/" + std::to_string(t) + "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  IntegerVector kmax(1);
  kmax[0]  = RcppDeepState_int();
  std::string kmax_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RcppDynProg/inst/testfiles/solve_interval_partition/AFL_solve_interval_partition/afl_inputs/" + std::to_string(t) + "_kmax.qs";
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
