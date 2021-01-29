#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector DijkstraSSSP(NumericMatrix Adj, NumericMatrix Costs, int source);

TEST(ProjectionBasedClustering_deepstate_test,DijkstraSSSP_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix Adj  = RcppDeepState_NumericMatrix();
  std::string Adj_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ProjectionBasedClustering/inst/testfiles/DijkstraSSSP/libFuzzer_DijkstraSSSP/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Adj.qs";
  qs::c_qsave(Adj,Adj_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Adj values: "<< Adj << std::endl;
  NumericMatrix Costs  = RcppDeepState_NumericMatrix();
  std::string Costs_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ProjectionBasedClustering/inst/testfiles/DijkstraSSSP/libFuzzer_DijkstraSSSP/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Costs.qs";
  qs::c_qsave(Costs,Costs_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Costs values: "<< Costs << std::endl;
  IntegerVector source(1);
  source[0]  = RcppDeepState_int();
  std::string source_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ProjectionBasedClustering/inst/testfiles/DijkstraSSSP/libFuzzer_DijkstraSSSP/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_source.qs";
  qs::c_qsave(source,source_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "source values: "<< source << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    DijkstraSSSP(Adj,Costs,source[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
