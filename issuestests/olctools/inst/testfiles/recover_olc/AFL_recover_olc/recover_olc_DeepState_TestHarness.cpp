#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

CharacterVector recover_olc(CharacterVector olcs, NumericVector lats, NumericVector longs);

TEST(olctools_deepstate_test,recover_olc_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  CharacterVector olcs  = RcppDeepState_CharacterVector();
  std::string olcs_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/olctools/inst/testfiles/recover_olc/AFL_recover_olc/afl_inputs/" + std::to_string(t) + "_olcs.qs";
  qs::c_qsave(olcs,olcs_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "olcs values: "<< olcs << std::endl;
  NumericVector lats  = RcppDeepState_NumericVector();
  std::string lats_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/olctools/inst/testfiles/recover_olc/AFL_recover_olc/afl_inputs/" + std::to_string(t) + "_lats.qs";
  qs::c_qsave(lats,lats_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lats values: "<< lats << std::endl;
  NumericVector longs  = RcppDeepState_NumericVector();
  std::string longs_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/olctools/inst/testfiles/recover_olc/AFL_recover_olc/afl_inputs/" + std::to_string(t) + "_longs.qs";
  qs::c_qsave(longs,longs_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "longs values: "<< longs << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    recover_olc(olcs,lats,longs);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
