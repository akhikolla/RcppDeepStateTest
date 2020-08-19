#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 NumericVector d_mat32_cpp(NumericVector X, double x, double sigma);
TEST(activegp_deepstate_test,d_mat32_cpp_test){
std::ofstream  X_stream;
std::ofstream  x_stream;
std::ofstream  sigma_stream;
 RInside();
 NumericVector X = RcppDeepState_NumericVector ();
  X_stream.open("/home/akhila/Documents/compileAttributescheck/activegp/inst/testfiles/d_mat32_cpp/inputs/ X");
 X_stream<< X;
std::cout <<"X values: "<< X << std::endl;
 X_stream.close();
 double x = RcppDeepState_double ();
  x_stream.open("/home/akhila/Documents/compileAttributescheck/activegp/inst/testfiles/d_mat32_cpp/inputs/ x");
 x_stream<< x;
std::cout <<"x values: "<< x << std::endl;
 x_stream.close();
 double sigma = RcppDeepState_double ();
  sigma_stream.open("/home/akhila/Documents/compileAttributescheck/activegp/inst/testfiles/d_mat32_cpp/inputs/ sigma");
 sigma_stream<< sigma;
std::cout <<"sigma values: "<< sigma << std::endl;
 sigma_stream.close();
 try{
d_mat32_cpp( X, x, sigma);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
