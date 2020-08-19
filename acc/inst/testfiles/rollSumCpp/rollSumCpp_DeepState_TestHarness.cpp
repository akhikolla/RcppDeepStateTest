#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 NumericVector rollSumCpp(NumericVector x, int n);
TEST(acc_deepstate_test,rollSumCpp_test){
std::ofstream  x_stream;
std::ofstream  n_stream;
 RInside();
 NumericVector x = RcppDeepState_NumericVector ();
  x_stream.open("/home/akhila/Documents/compileAttributescheck/acc/inst/testfiles/rollSumCpp/inputs/ x");
 x_stream<< x;
std::cout <<"x values: "<< x << std::endl;
 x_stream.close();
 int n = RcppDeepState_int ();
  n_stream.open("/home/akhila/Documents/compileAttributescheck/acc/inst/testfiles/rollSumCpp/inputs/ n");
 n_stream<< n;
std::cout <<"n values: "<< n << std::endl;
 n_stream.close();
 try{
rollSumCpp( x, n);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
