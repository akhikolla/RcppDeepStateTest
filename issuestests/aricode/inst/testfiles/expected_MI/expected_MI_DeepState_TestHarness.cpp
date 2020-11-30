#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double expected_MI(IntegerVector ni_, IntegerVector n_j);

TEST(aricode_deepstate_test,expected_MI_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector ni_  = RcppDeepState_IntegerVector();
  qs::c_qsave(ni_,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aricode/inst/testfiles/expected_MI/inputs/ni_.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ni_ values: "<< ni_ << std::endl;
  IntegerVector n_j  = RcppDeepState_IntegerVector();
  qs::c_qsave(n_j,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aricode/inst/testfiles/expected_MI/inputs/n_j.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n_j values: "<< n_j << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    expected_MI(ni_,n_j);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
