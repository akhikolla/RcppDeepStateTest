#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector bestmatchesC(NumericMatrix WeightVectors, NumericMatrix DataPoints, int Columns);

TEST(Umatrix_deepstate_test,bestmatchesC_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix WeightVectors  = RcppDeepState_NumericMatrix();
  qs::c_qsave(WeightVectors,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Umatrix/inst/testfiles/bestmatchesC/inputs/WeightVectors.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "WeightVectors values: "<< WeightVectors << std::endl;
  NumericMatrix DataPoints  = RcppDeepState_NumericMatrix();
  qs::c_qsave(DataPoints,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Umatrix/inst/testfiles/bestmatchesC/inputs/DataPoints.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "DataPoints values: "<< DataPoints << std::endl;
  IntegerVector Columns(1);
  Columns[0]  = RcppDeepState_int();
  qs::c_qsave(Columns,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Umatrix/inst/testfiles/bestmatchesC/inputs/Columns.qs",
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
