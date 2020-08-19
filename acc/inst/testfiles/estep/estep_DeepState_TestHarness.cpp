#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 NumericMatrix estep(NumericMatrix A, NumericVector L);
TEST(acc_deepstate_test,estep_test){
std::ofstream  A_stream;
std::ofstream  L_stream;
 RInside();
 NumericMatrix A = RcppDeepState_NumericMatrix ();
  A_stream.open("/home/akhila/Documents/compileAttributescheck/acc/inst/testfiles/estep/inputs/ A");
 A_stream<< A;
std::cout <<"A values: "<< A << std::endl;
 A_stream.close();
 NumericVector L = RcppDeepState_NumericVector ();
  L_stream.open("/home/akhila/Documents/compileAttributescheck/acc/inst/testfiles/estep/inputs/ L");
 L_stream<< L;
std::cout <<"L values: "<< L << std::endl;
 L_stream.close();
 try{
estep( A, L);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
