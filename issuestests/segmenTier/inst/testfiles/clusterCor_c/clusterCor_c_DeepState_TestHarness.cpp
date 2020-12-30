#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix clusterCor_c(NumericMatrix data, NumericMatrix clusters);

TEST(segmenTier_deepstate_test,clusterCor_c_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix data  = RcppDeepState_NumericMatrix();
  qs::c_qsave(data,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/segmenTier/inst/testfiles/clusterCor_c/inputs/data.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "data values: "<< data << std::endl;
  NumericMatrix clusters  = RcppDeepState_NumericMatrix();
  qs::c_qsave(clusters,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/segmenTier/inst/testfiles/clusterCor_c/inputs/clusters.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "clusters values: "<< clusters << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    clusterCor_c(data,clusters);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
