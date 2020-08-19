#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 NumericMatrix computeNeighboursWeights(NumericMatrix predTrainingID, NumericMatrix predTestingID, int ntrain, int ntest, int ntree);
TEST(abcrf_deepstate_test,computeNeighboursWeights_test){
std::ofstream  predTrainingID_stream;
std::ofstream  predTestingID_stream;
std::ofstream  ntrain_stream;
std::ofstream  ntest_stream;
std::ofstream  ntree_stream;
 RInside();
 NumericMatrix predTrainingID = RcppDeepState_NumericMatrix ();
  predTrainingID_stream.open("/home/akhila/Documents/compileAttributescheck/abcrf/inst/testfiles/computeNeighboursWeights/inputs/ predTrainingID");
 predTrainingID_stream<< predTrainingID;
std::cout <<"predTrainingID values: "<< predTrainingID << std::endl;
 predTrainingID_stream.close();
 NumericMatrix predTestingID = RcppDeepState_NumericMatrix ();
  predTestingID_stream.open("/home/akhila/Documents/compileAttributescheck/abcrf/inst/testfiles/computeNeighboursWeights/inputs/ predTestingID");
 predTestingID_stream<< predTestingID;
std::cout <<"predTestingID values: "<< predTestingID << std::endl;
 predTestingID_stream.close();
 int ntrain = RcppDeepState_int ();
  ntrain_stream.open("/home/akhila/Documents/compileAttributescheck/abcrf/inst/testfiles/computeNeighboursWeights/inputs/ ntrain");
 ntrain_stream<< ntrain;
std::cout <<"ntrain values: "<< ntrain << std::endl;
 ntrain_stream.close();
 int ntest = RcppDeepState_int ();
  ntest_stream.open("/home/akhila/Documents/compileAttributescheck/abcrf/inst/testfiles/computeNeighboursWeights/inputs/ ntest");
 ntest_stream<< ntest;
std::cout <<"ntest values: "<< ntest << std::endl;
 ntest_stream.close();
 int ntree = RcppDeepState_int ();
  ntree_stream.open("/home/akhila/Documents/compileAttributescheck/abcrf/inst/testfiles/computeNeighboursWeights/inputs/ ntree");
 ntree_stream<< ntree;
std::cout <<"ntree values: "<< ntree << std::endl;
 ntree_stream.close();
 try{
computeNeighboursWeights( predTrainingID, predTestingID, ntrain, ntest, ntree);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
