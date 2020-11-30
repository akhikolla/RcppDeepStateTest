#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector DijkstraSSSP(NumericMatrix Adj, NumericMatrix Costs, int source);

TEST(ProjectionBasedClustering_deepstate_test,DijkstraSSSP_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix Adj  = RcppDeepState_NumericMatrix();
  qs::c_qsave(Adj,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ProjectionBasedClustering/inst/testfiles/DijkstraSSSP/inputs/Adj.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Adj values: "<< Adj << std::endl;
  NumericMatrix Costs  = RcppDeepState_NumericMatrix();
  qs::c_qsave(Costs,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ProjectionBasedClustering/inst/testfiles/DijkstraSSSP/inputs/Costs.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Costs values: "<< Costs << std::endl;
  IntegerVector source(1);
  source[0]  = RcppDeepState_int();
  qs::c_qsave(source,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ProjectionBasedClustering/inst/testfiles/DijkstraSSSP/inputs/source.qs",
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
