#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector bestmatchesC(NumericMatrix WeightVectors, NumericMatrix DataPoints, int Columns);

TEST(Umatrix_deepstate_test,bestmatchesC_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix WeightVectors  = RcppDeepState_NumericMatrix();
  std::string WeightVectors_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Umatrix/inst/testfiles/bestmatchesC/libFuzzer_bestmatchesC/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_WeightVectors.qs";
  qs::c_qsave(WeightVectors,WeightVectors_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "WeightVectors values: "<< WeightVectors << std::endl;
  NumericMatrix DataPoints  = RcppDeepState_NumericMatrix();
  std::string DataPoints_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Umatrix/inst/testfiles/bestmatchesC/libFuzzer_bestmatchesC/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_DataPoints.qs";
  qs::c_qsave(DataPoints,DataPoints_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "DataPoints values: "<< DataPoints << std::endl;
  IntegerVector Columns(1);
  Columns[0]  = RcppDeepState_int();
  std::string Columns_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Umatrix/inst/testfiles/bestmatchesC/libFuzzer_bestmatchesC/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Columns.qs";
  qs::c_qsave(Columns,Columns_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Columns values: "<< Columns << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    bestmatchesC(WeightVectors,DataPoints,Columns[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
