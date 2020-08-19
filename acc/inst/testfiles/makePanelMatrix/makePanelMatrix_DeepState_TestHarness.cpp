#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 NumericMatrix makePanelMatrix(NumericVector T, NumericVector M, NumericVector UID, NumericVector TGD, NumericVector C);
TEST(acc_deepstate_test,makePanelMatrix_test){
std::ofstream  T_stream;
std::ofstream  M_stream;
std::ofstream  UID_stream;
std::ofstream  TGD_stream;
std::ofstream  C_stream;
 RInside();
 NumericVector T = RcppDeepState_NumericVector ();
  T_stream.open("/home/akhila/Documents/compileAttributescheck/acc/inst/testfiles/makePanelMatrix/inputs/ T");
 T_stream<< T;
std::cout <<"T values: "<< T << std::endl;
 T_stream.close();
 NumericVector M = RcppDeepState_NumericVector ();
  M_stream.open("/home/akhila/Documents/compileAttributescheck/acc/inst/testfiles/makePanelMatrix/inputs/ M");
 M_stream<< M;
std::cout <<"M values: "<< M << std::endl;
 M_stream.close();
 NumericVector UID = RcppDeepState_NumericVector ();
  UID_stream.open("/home/akhila/Documents/compileAttributescheck/acc/inst/testfiles/makePanelMatrix/inputs/ UID");
 UID_stream<< UID;
std::cout <<"UID values: "<< UID << std::endl;
 UID_stream.close();
 NumericVector TGD = RcppDeepState_NumericVector ();
  TGD_stream.open("/home/akhila/Documents/compileAttributescheck/acc/inst/testfiles/makePanelMatrix/inputs/ TGD");
 TGD_stream<< TGD;
std::cout <<"TGD values: "<< TGD << std::endl;
 TGD_stream.close();
 NumericVector C = RcppDeepState_NumericVector ();
  C_stream.open("/home/akhila/Documents/compileAttributescheck/acc/inst/testfiles/makePanelMatrix/inputs/ C");
 C_stream<< C;
std::cout <<"C values: "<< C << std::endl;
 C_stream.close();
 try{
makePanelMatrix( T, M, UID, TGD, C);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
