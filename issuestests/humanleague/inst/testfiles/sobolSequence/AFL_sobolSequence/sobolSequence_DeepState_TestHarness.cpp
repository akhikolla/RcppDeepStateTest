#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix sobolSequence(int dim, int n, int skip);

TEST(humanleague_deepstate_test,sobolSequence_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector dim(1);
  dim[0]  = RcppDeepState_int();
  std::string dim_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/humanleague/inst/testfiles/sobolSequence/AFL_sobolSequence/afl_inputs/" + std::to_string(t) + "_dim.qs";
  qs::c_qsave(dim,dim_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "dim values: "<< dim << std::endl;
  IntegerVector n(1);
  n[0]  = RcppDeepState_int();
  std::string n_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/humanleague/inst/testfiles/sobolSequence/AFL_sobolSequence/afl_inputs/" + std::to_string(t) + "_n.qs";
  qs::c_qsave(n,n_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n values: "<< n << std::endl;
  IntegerVector skip(1);
  skip[0]  = RcppDeepState_int();
  std::string skip_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/humanleague/inst/testfiles/sobolSequence/AFL_sobolSequence/afl_inputs/" + std::to_string(t) + "_skip.qs";
  qs::c_qsave(skip,skip_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "skip values: "<< skip << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    sobolSequence(dim[0],n[0],skip[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
