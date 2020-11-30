#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double probSubtree(NumericMatrix tab, double rate);

TEST(TransPhylo_deepstate_test,probSubtree_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix tab  = RcppDeepState_NumericMatrix();
  qs::c_qsave(tab,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/TransPhylo/inst/testfiles/probSubtree/inputs/tab.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tab values: "<< tab << std::endl;
  NumericVector rate(1);
  rate[0]  = RcppDeepState_double();
  qs::c_qsave(rate,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/TransPhylo/inst/testfiles/probSubtree/inputs/rate.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "rate values: "<< rate << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    probSubtree(tab,rate[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
