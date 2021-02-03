#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

CharacterVector encode_olc(NumericVector lats, NumericVector longs, IntegerVector length);

TEST(olctools_deepstate_test,encode_olc_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector lats  = RcppDeepState_NumericVector();
  std::string lats_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/olctools/inst/testfiles/encode_olc/AFL_encode_olc/afl_inputs/" + std::to_string(t) + "_lats.qs";
  qs::c_qsave(lats,lats_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lats values: "<< lats << std::endl;
  NumericVector longs  = RcppDeepState_NumericVector();
  std::string longs_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/olctools/inst/testfiles/encode_olc/AFL_encode_olc/afl_inputs/" + std::to_string(t) + "_longs.qs";
  qs::c_qsave(longs,longs_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "longs values: "<< longs << std::endl;
  IntegerVector length  = RcppDeepState_IntegerVector();
  std::string length_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/olctools/inst/testfiles/encode_olc/AFL_encode_olc/afl_inputs/" + std::to_string(t) + "_length.qs";
  qs::c_qsave(length,length_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "length values: "<< length << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    encode_olc(lats,longs,length);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
