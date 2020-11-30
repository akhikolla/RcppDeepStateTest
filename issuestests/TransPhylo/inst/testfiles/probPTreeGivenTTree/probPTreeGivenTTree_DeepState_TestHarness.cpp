#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double probPTreeGivenTTree(NumericMatrix ctree, double neg, IntegerVector w);

TEST(TransPhylo_deepstate_test,probPTreeGivenTTree_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix ctree  = RcppDeepState_NumericMatrix();
  qs::c_qsave(ctree,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/TransPhylo/inst/testfiles/probPTreeGivenTTree/inputs/ctree.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ctree values: "<< ctree << std::endl;
  NumericVector neg(1);
  neg[0]  = RcppDeepState_double();
  qs::c_qsave(neg,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/TransPhylo/inst/testfiles/probPTreeGivenTTree/inputs/neg.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "neg values: "<< neg << std::endl;
  IntegerVector w  = RcppDeepState_IntegerVector();
  qs::c_qsave(w,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/TransPhylo/inst/testfiles/probPTreeGivenTTree/inputs/w.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "w values: "<< w << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    probPTreeGivenTTree(ctree,neg[0],w);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
