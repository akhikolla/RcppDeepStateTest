#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

IntegerVector cut_counts(IntegerVector counts, IntegerVector int_cuts);

TEST(accelerometry_deepstate_test,cut_counts_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector counts  = RcppDeepState_IntegerVector();
  std::string counts_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/accelerometry/inst/testfiles/cut_counts/AFL_cut_counts/afl_inputs/" + std::to_string(t) + "_counts.qs";
  qs::c_qsave(counts,counts_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "counts values: "<< counts << std::endl;
  IntegerVector int_cuts  = RcppDeepState_IntegerVector();
  std::string int_cuts_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/accelerometry/inst/testfiles/cut_counts/AFL_cut_counts/afl_inputs/" + std::to_string(t) + "_int_cuts.qs";
  qs::c_qsave(int_cuts,int_cuts_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "int_cuts values: "<< int_cuts << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    cut_counts(counts,int_cuts);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
