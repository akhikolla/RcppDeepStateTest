#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double euclidean_dist(NumericVector seq1, NumericVector seq2);

TEST(jmotif_deepstate_test,euclidean_dist_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector seq1  = RcppDeepState_NumericVector();
  std::string seq1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/jmotif/inst/testfiles/euclidean_dist/AFL_euclidean_dist/afl_inputs/" + std::to_string(t) + "_seq1.qs";
  qs::c_qsave(seq1,seq1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "seq1 values: "<< seq1 << std::endl;
  NumericVector seq2  = RcppDeepState_NumericVector();
  std::string seq2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/jmotif/inst/testfiles/euclidean_dist/AFL_euclidean_dist/afl_inputs/" + std::to_string(t) + "_seq2.qs";
  qs::c_qsave(seq2,seq2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "seq2 values: "<< seq2 << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    euclidean_dist(seq1,seq2);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
