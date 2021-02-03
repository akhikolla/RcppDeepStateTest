#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List c_klmeasure(NumericMatrix Data, NumericMatrix pData, int NeighborhoodSize);

TEST(ProjectionBasedClustering_deepstate_test,c_klmeasure_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix Data  = RcppDeepState_NumericMatrix();
  std::string Data_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ProjectionBasedClustering/inst/testfiles/c_klmeasure/AFL_c_klmeasure/afl_inputs/" + std::to_string(t) + "_Data.qs";
  qs::c_qsave(Data,Data_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Data values: "<< Data << std::endl;
  NumericMatrix pData  = RcppDeepState_NumericMatrix();
  std::string pData_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ProjectionBasedClustering/inst/testfiles/c_klmeasure/AFL_c_klmeasure/afl_inputs/" + std::to_string(t) + "_pData.qs";
  qs::c_qsave(pData,pData_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pData values: "<< pData << std::endl;
  IntegerVector NeighborhoodSize(1);
  NeighborhoodSize[0]  = RcppDeepState_int();
  std::string NeighborhoodSize_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ProjectionBasedClustering/inst/testfiles/c_klmeasure/AFL_c_klmeasure/afl_inputs/" + std::to_string(t) + "_NeighborhoodSize.qs";
  qs::c_qsave(NeighborhoodSize,NeighborhoodSize_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "NeighborhoodSize values: "<< NeighborhoodSize << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    c_klmeasure(Data,pData,NeighborhoodSize[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
