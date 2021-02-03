#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix kdist(NumericMatrix x, IntegerVector from, IntegerVector to, IntegerVector seqlengths, int k);

TEST(kmer_deepstate_test,kdist_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix x  = RcppDeepState_NumericMatrix();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/kmer/inst/testfiles/kdist/AFL_kdist/afl_inputs/" + std::to_string(t) + "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  IntegerVector from  = RcppDeepState_IntegerVector();
  std::string from_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/kmer/inst/testfiles/kdist/AFL_kdist/afl_inputs/" + std::to_string(t) + "_from.qs";
  qs::c_qsave(from,from_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "from values: "<< from << std::endl;
  IntegerVector to  = RcppDeepState_IntegerVector();
  std::string to_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/kmer/inst/testfiles/kdist/AFL_kdist/afl_inputs/" + std::to_string(t) + "_to.qs";
  qs::c_qsave(to,to_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "to values: "<< to << std::endl;
  IntegerVector seqlengths  = RcppDeepState_IntegerVector();
  std::string seqlengths_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/kmer/inst/testfiles/kdist/AFL_kdist/afl_inputs/" + std::to_string(t) + "_seqlengths.qs";
  qs::c_qsave(seqlengths,seqlengths_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "seqlengths values: "<< seqlengths << std::endl;
  IntegerVector k(1);
  k[0]  = RcppDeepState_int();
  std::string k_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/kmer/inst/testfiles/kdist/AFL_kdist/afl_inputs/" + std::to_string(t) + "_k.qs";
  qs::c_qsave(k,k_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "k values: "<< k << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    kdist(x,from,to,seqlengths,k[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
