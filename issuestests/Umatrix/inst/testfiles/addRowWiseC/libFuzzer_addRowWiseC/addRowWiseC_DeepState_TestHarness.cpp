#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix addRowWiseC(NumericMatrix WeightVectors, NumericVector DataPoint);

TEST(Umatrix_deepstate_test,addRowWiseC_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix WeightVectors  = RcppDeepState_NumericMatrix();
  std::string WeightVectors_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Umatrix/inst/testfiles/addRowWiseC/libFuzzer_addRowWiseC/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_WeightVectors.qs";
  qs::c_qsave(WeightVectors,WeightVectors_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "WeightVectors values: "<< WeightVectors << std::endl;
  NumericVector DataPoint  = RcppDeepState_NumericVector();
  std::string DataPoint_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Umatrix/inst/testfiles/addRowWiseC/libFuzzer_addRowWiseC/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_DataPoint.qs";
  qs::c_qsave(DataPoint,DataPoint_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "DataPoint values: "<< DataPoint << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    addRowWiseC(WeightVectors,DataPoint);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
