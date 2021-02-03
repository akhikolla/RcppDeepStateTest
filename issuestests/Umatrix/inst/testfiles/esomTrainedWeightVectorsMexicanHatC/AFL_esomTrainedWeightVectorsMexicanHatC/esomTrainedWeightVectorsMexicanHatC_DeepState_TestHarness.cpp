#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

void esomTrainedWeightVectorsMexicanHatC(NumericMatrix WeightVectors, NumericVector DataPoint, NumericVector indices, NumericVector DistancesToBm, double Radius, double LearningRate);

TEST(Umatrix_deepstate_test,esomTrainedWeightVectorsMexicanHatC_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix WeightVectors  = RcppDeepState_NumericMatrix();
  std::string WeightVectors_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Umatrix/inst/testfiles/esomTrainedWeightVectorsMexicanHatC/AFL_esomTrainedWeightVectorsMexicanHatC/afl_inputs/" + std::to_string(t) + "_WeightVectors.qs";
  qs::c_qsave(WeightVectors,WeightVectors_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "WeightVectors values: "<< WeightVectors << std::endl;
  NumericVector DataPoint  = RcppDeepState_NumericVector();
  std::string DataPoint_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Umatrix/inst/testfiles/esomTrainedWeightVectorsMexicanHatC/AFL_esomTrainedWeightVectorsMexicanHatC/afl_inputs/" + std::to_string(t) + "_DataPoint.qs";
  qs::c_qsave(DataPoint,DataPoint_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "DataPoint values: "<< DataPoint << std::endl;
  NumericVector indices  = RcppDeepState_NumericVector();
  std::string indices_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Umatrix/inst/testfiles/esomTrainedWeightVectorsMexicanHatC/AFL_esomTrainedWeightVectorsMexicanHatC/afl_inputs/" + std::to_string(t) + "_indices.qs";
  qs::c_qsave(indices,indices_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "indices values: "<< indices << std::endl;
  NumericVector DistancesToBm  = RcppDeepState_NumericVector();
  std::string DistancesToBm_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Umatrix/inst/testfiles/esomTrainedWeightVectorsMexicanHatC/AFL_esomTrainedWeightVectorsMexicanHatC/afl_inputs/" + std::to_string(t) + "_DistancesToBm.qs";
  qs::c_qsave(DistancesToBm,DistancesToBm_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "DistancesToBm values: "<< DistancesToBm << std::endl;
  NumericVector Radius(1);
  Radius[0]  = RcppDeepState_double();
  std::string Radius_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Umatrix/inst/testfiles/esomTrainedWeightVectorsMexicanHatC/AFL_esomTrainedWeightVectorsMexicanHatC/afl_inputs/" + std::to_string(t) + "_Radius.qs";
  qs::c_qsave(Radius,Radius_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Radius values: "<< Radius << std::endl;
  NumericVector LearningRate(1);
  LearningRate[0]  = RcppDeepState_double();
  std::string LearningRate_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Umatrix/inst/testfiles/esomTrainedWeightVectorsMexicanHatC/AFL_esomTrainedWeightVectorsMexicanHatC/afl_inputs/" + std::to_string(t) + "_LearningRate.qs";
  qs::c_qsave(LearningRate,LearningRate_t,
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
