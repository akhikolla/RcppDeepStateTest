#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double euclidean_dist(NumericVector seq1, NumericVector seq2);

TEST(jmotif_deepstate_test,euclidean_dist_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector seq1  = RcppDeepState_NumericVector();
  std::string seq1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/jmotif/inst/testfiles/euclidean_dist/libFuzzer_euclidean_dist/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_seq1.qs";
  qs::c_qsave(seq1,seq1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "seq1 values: "<< seq1 << std::endl;
  NumericVector seq2  = RcppDeepState_NumericVector();
  std::string seq2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/jmotif/inst/testfiles/euclidean_dist/libFuzzer_euclidean_dist/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_seq2.qs";
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
