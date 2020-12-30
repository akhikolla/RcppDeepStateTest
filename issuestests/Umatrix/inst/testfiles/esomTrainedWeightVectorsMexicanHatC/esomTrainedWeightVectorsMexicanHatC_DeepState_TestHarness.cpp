#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

void esomTrainedWeightVectorsMexicanHatC(NumericMatrix WeightVectors, NumericVector DataPoint, NumericVector indices, NumericVector DistancesToBm, double Radius, double LearningRate);

TEST(Umatrix_deepstate_test,esomTrainedWeightVectorsMexicanHatC_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix WeightVectors  = RcppDeepState_NumericMatrix();
  qs::c_qsave(WeightVectors,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Umatrix/inst/testfiles/esomTrainedWeightVectorsMexicanHatC/inputs/WeightVectors.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "WeightVectors values: "<< WeightVectors << std::endl;
  NumericVector DataPoint  = RcppDeepState_NumericVector();
  qs::c_qsave(DataPoint,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Umatrix/inst/testfiles/esomTrainedWeightVectorsMexicanHatC/inputs/DataPoint.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "DataPoint values: "<< DataPoint << std::endl;
  NumericVector indices  = RcppDeepState_NumericVector();
  qs::c_qsave(indices,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Umatrix/inst/testfiles/esomTrainedWeightVectorsMexicanHatC/inputs/indices.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "indices values: "<< indices << std::endl;
  NumericVector DistancesToBm  = RcppDeepState_NumericVector();
  qs::c_qsave(DistancesToBm,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Umatrix/inst/testfiles/esomTrainedWeightVectorsMexicanHatC/inputs/DistancesToBm.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "DistancesToBm values: "<< DistancesToBm << std::endl;
  NumericVector Radius(1);
  Radius[0]  = RcppDeepState_double();
  qs::c_qsave(Radius,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Umatrix/inst/testfiles/esomTrainedWeightVectorsMexicanHatC/inputs/Radius.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Radius values: "<< Radius << std::endl;
  NumericVector LearningRate(1);
  LearningRate[0]  = RcppDeepState_double();
  qs::c_qsave(LearningRate,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Umatrix/inst/testfiles/esomTrainedWeightVectorsMexicanHatC/inputs/LearningRate.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "LearningRate values: "<< LearningRate << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    esomTrainedWeightVectorsMexicanHatC(WeightVectors,DataPoint,indices,DistancesToBm,Radius[0],LearningRate[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
