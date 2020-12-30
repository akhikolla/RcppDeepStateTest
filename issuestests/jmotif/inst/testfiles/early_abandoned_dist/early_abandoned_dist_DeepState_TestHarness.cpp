#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double early_abandoned_dist(NumericVector seq1, NumericVector seq2, double upper_limit);

TEST(jmotif_deepstate_test,early_abandoned_dist_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector seq1  = RcppDeepState_NumericVector();
  qs::c_qsave(seq1,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/jmotif/inst/testfiles/early_abandoned_dist/inputs/seq1.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "seq1 values: "<< seq1 << std::endl;
  NumericVector seq2  = RcppDeepState_NumericVector();
  qs::c_qsave(seq2,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/jmotif/inst/testfiles/early_abandoned_dist/inputs/seq2.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "seq2 values: "<< seq2 << std::endl;
  NumericVector upper_limit(1);
  upper_limit[0]  = RcppDeepState_double();
  qs::c_qsave(upper_limit,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/jmotif/inst/testfiles/early_abandoned_dist/inputs/upper_limit.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "upper_limit values: "<< upper_limit << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    early_abandoned_dist(seq1,seq2,upper_limit[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
