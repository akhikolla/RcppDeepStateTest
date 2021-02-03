#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double lossFunc(const NumericVector bp, const NumericMatrix bin_repr, const NumericMatrix z);

TEST(cort_deepstate_test,lossFunc_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector bp  = RcppDeepState_NumericVector();
  std::string bp_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/cort/inst/testfiles/lossFunc/AFL_lossFunc/afl_inputs/" + std::to_string(t) + "_bp.qs";
  qs::c_qsave(bp,bp_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "bp values: "<< bp << std::endl;
  NumericMatrix bin_repr  = RcppDeepState_NumericMatrix();
  std::string bin_repr_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/cort/inst/testfiles/lossFunc/AFL_lossFunc/afl_inputs/" + std::to_string(t) + "_bin_repr.qs";
  qs::c_qsave(bin_repr,bin_repr_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "bin_repr values: "<< bin_repr << std::endl;
  NumericMatrix z  = RcppDeepState_NumericMatrix();
  std::string z_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/cort/inst/testfiles/lossFunc/AFL_lossFunc/afl_inputs/" + std::to_string(t) + "_z.qs";
  qs::c_qsave(z,z_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "z values: "<< z << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    lossFunc(bp,bin_repr,z);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
