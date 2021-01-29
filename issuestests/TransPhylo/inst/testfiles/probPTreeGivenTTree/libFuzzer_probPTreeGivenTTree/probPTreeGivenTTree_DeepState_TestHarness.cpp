#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double probPTreeGivenTTree(NumericMatrix ctree, double neg, IntegerVector w);

TEST(TransPhylo_deepstate_test,probPTreeGivenTTree_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix ctree  = RcppDeepState_NumericMatrix();
  std::string ctree_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/TransPhylo/inst/testfiles/probPTreeGivenTTree/libFuzzer_probPTreeGivenTTree/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_ctree.qs";
  qs::c_qsave(ctree,ctree_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ctree values: "<< ctree << std::endl;
  NumericVector neg(1);
  neg[0]  = RcppDeepState_double();
  std::string neg_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/TransPhylo/inst/testfiles/probPTreeGivenTTree/libFuzzer_probPTreeGivenTTree/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_neg.qs";
  qs::c_qsave(neg,neg_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "neg values: "<< neg << std::endl;
  IntegerVector w  = RcppDeepState_IntegerVector();
  std::string w_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/TransPhylo/inst/testfiles/probPTreeGivenTTree/libFuzzer_probPTreeGivenTTree/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_w.qs";
  qs::c_qsave(w,w_t,
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
