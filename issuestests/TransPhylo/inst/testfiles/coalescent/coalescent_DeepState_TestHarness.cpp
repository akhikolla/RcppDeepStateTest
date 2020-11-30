#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double coalescent(NumericVector leaves, NumericVector nodes, double alpha);

TEST(TransPhylo_deepstate_test,coalescent_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector leaves  = RcppDeepState_NumericVector();
  qs::c_qsave(leaves,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/TransPhylo/inst/testfiles/coalescent/inputs/leaves.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "leaves values: "<< leaves << std::endl;
  NumericVector nodes  = RcppDeepState_NumericVector();
  qs::c_qsave(nodes,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/TransPhylo/inst/testfiles/coalescent/inputs/nodes.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nodes values: "<< nodes << std::endl;
  NumericVector alpha(1);
  alpha[0]  = RcppDeepState_double();
  qs::c_qsave(alpha,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/TransPhylo/inst/testfiles/coalescent/inputs/alpha.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "alpha values: "<< alpha << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    coalescent(leaves,nodes,alpha[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
