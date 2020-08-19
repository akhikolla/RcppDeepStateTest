#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 NumericMatrix estepAEE(NumericMatrix A, NumericVector L, double a);
TEST(acc_deepstate_test,estepAEE_test){
std::ofstream  A_stream;
std::ofstream  L_stream;
std::ofstream  a_stream;
 RInside();
 NumericMatrix A = RcppDeepState_NumericMatrix ();
  A_stream.open("/home/akhila/Documents/compileAttributescheck/acc/inst/testfiles/estepAEE/inputs/ A");
 A_stream<< A;
std::cout <<"A values: "<< A << std::endl;
 A_stream.close();
 NumericVector L = RcppDeepState_NumericVector ();
  L_stream.open("/home/akhila/Documents/compileAttributescheck/acc/inst/testfiles/estepAEE/inputs/ L");
 L_stream<< L;
std::cout <<"L values: "<< L << std::endl;
 L_stream.close();
 double a = RcppDeepState_double ();
  a_stream.open("/home/akhila/Documents/compileAttributescheck/acc/inst/testfiles/estepAEE/inputs/ a");
 a_stream<< a;
std::cout <<"a values: "<< a << std::endl;
 a_stream.close();
 try{
estepAEE( A, L, a);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
