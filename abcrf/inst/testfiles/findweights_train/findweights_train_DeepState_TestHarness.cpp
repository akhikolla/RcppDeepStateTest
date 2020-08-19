#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 NumericMatrix findweights_train(NumericMatrix trainingNodeID, NumericMatrix inbag, int ntrain, int trainIdx, int ntree);
TEST(abcrf_deepstate_test,findweights_train_test){
std::ofstream  trainingNodeID_stream;
std::ofstream  inbag_stream;
std::ofstream  ntrain_stream;
std::ofstream  trainIdx_stream;
std::ofstream  ntree_stream;
 RInside();
 NumericMatrix trainingNodeID = RcppDeepState_NumericMatrix ();
  trainingNodeID_stream.open("/home/akhila/Documents/compileAttributescheck/abcrf/inst/testfiles/findweights_train/inputs/ trainingNodeID");
 trainingNodeID_stream<< trainingNodeID;
std::cout <<"trainingNodeID values: "<< trainingNodeID << std::endl;
 trainingNodeID_stream.close();
 NumericMatrix inbag = RcppDeepState_NumericMatrix ();
  inbag_stream.open("/home/akhila/Documents/compileAttributescheck/abcrf/inst/testfiles/findweights_train/inputs/ inbag");
 inbag_stream<< inbag;
std::cout <<"inbag values: "<< inbag << std::endl;
 inbag_stream.close();
 int ntrain = RcppDeepState_int ();
  ntrain_stream.open("/home/akhila/Documents/compileAttributescheck/abcrf/inst/testfiles/findweights_train/inputs/ ntrain");
 ntrain_stream<< ntrain;
std::cout <<"ntrain values: "<< ntrain << std::endl;
 ntrain_stream.close();
 int trainIdx = RcppDeepState_int ();
  trainIdx_stream.open("/home/akhila/Documents/compileAttributescheck/abcrf/inst/testfiles/findweights_train/inputs/ trainIdx");
 trainIdx_stream<< trainIdx;
std::cout <<"trainIdx values: "<< trainIdx << std::endl;
 trainIdx_stream.close();
 int ntree = RcppDeepState_int ();
  ntree_stream.open("/home/akhila/Documents/compileAttributescheck/abcrf/inst/testfiles/findweights_train/inputs/ ntree");
 ntree_stream<< ntree;
std::cout <<"ntree values: "<< ntree << std::endl;
 ntree_stream.close();
 try{
findweights_train( trainingNodeID, inbag, ntrain, trainIdx, ntree);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
