#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 double empirical_cmi(NumericVector x, NumericVector y, NumericVector z);
TEST(BNSL_deepstate_test,empirical_cmi_test){
std::ofstream  x_stream;
std::ofstream  y_stream;
std::ofstream  z_stream;
RInside();
std::cout << "input starts" << std::endl;
 NumericVector x = RcppDeepState_NumericVector ();
  x_stream.open("/home/akhila/Documents/compileAttributescheck/BNSL/inst/testfiles/empirical_cmi/inputs/ x");
 x_stream<< x;
std::cout <<"x values: "<< x << std::endl;
 x_stream.close();
 NumericVector y = RcppDeepState_NumericVector ();
  y_stream.open("/home/akhila/Documents/compileAttributescheck/BNSL/inst/testfiles/empirical_cmi/inputs/ y");
 y_stream<< y;
std::cout <<"y values: "<< y << std::endl;
 y_stream.close();
 NumericVector z = RcppDeepState_NumericVector ();
  z_stream.open("/home/akhila/Documents/compileAttributescheck/BNSL/inst/testfiles/empirical_cmi/inputs/ z");
 z_stream<< z;
std::cout <<"z values: "<< z << std::endl;
 z_stream.close();
 std::cout << "input ends" << std::endl;
 try{
empirical_cmi( x, y, z);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
