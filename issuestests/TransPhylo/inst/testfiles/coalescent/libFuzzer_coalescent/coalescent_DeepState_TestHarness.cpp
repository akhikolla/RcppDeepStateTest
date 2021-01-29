#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double coalescent(NumericVector leaves, NumericVector nodes, double alpha);

TEST(TransPhylo_deepstate_test,coalescent_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector leaves  = RcppDeepState_NumericVector();
  std::string leaves_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/TransPhylo/inst/testfiles/coalescent/libFuzzer_coalescent/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_leaves.qs";
  qs::c_qsave(leaves,leaves_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "leaves values: "<< leaves << std::endl;
  NumericVector nodes  = RcppDeepState_NumericVector();
  std::string nodes_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/TransPhylo/inst/testfiles/coalescent/libFuzzer_coalescent/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_nodes.qs";
  qs::c_qsave(nodes,nodes_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nodes values: "<< nodes << std::endl;
  NumericVector alpha(1);
  alpha[0]  = RcppDeepState_double();
  std::string alpha_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/TransPhylo/inst/testfiles/coalescent/libFuzzer_coalescent/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_alpha.qs";
  qs::c_qsave(alpha,alpha_t,
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
