#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List klrank(NumericMatrix Data, NumericMatrix pData, int NeighborhoodSize);

TEST(ProjectionBasedClustering_deepstate_test,klrank_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix Data  = RcppDeepState_NumericMatrix();
  std::string Data_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ProjectionBasedClustering/inst/testfiles/klrank/libFuzzer_klrank/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Data.qs";
  qs::c_qsave(Data,Data_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Data values: "<< Data << std::endl;
  NumericMatrix pData  = RcppDeepState_NumericMatrix();
  std::string pData_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ProjectionBasedClustering/inst/testfiles/klrank/libFuzzer_klrank/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_pData.qs";
  qs::c_qsave(pData,pData_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pData values: "<< pData << std::endl;
  IntegerVector NeighborhoodSize(1);
  NeighborhoodSize[0]  = RcppDeepState_int();
  std::string NeighborhoodSize_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ProjectionBasedClustering/inst/testfiles/klrank/libFuzzer_klrank/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_NeighborhoodSize.qs";
  qs::c_qsave(NeighborhoodSize,NeighborhoodSize_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "NeighborhoodSize values: "<< NeighborhoodSize << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    klrank(Data,pData,NeighborhoodSize[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
