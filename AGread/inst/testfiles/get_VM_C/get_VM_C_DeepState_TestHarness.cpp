#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 NumericVector get_VM_C(NumericVector x, NumericVector y, NumericVector z);
TEST(AGread_deepstate_test,get_VM_C_test){
std::ofstream  x_stream;
std::ofstream  y_stream;
std::ofstream  z_stream;
 RInside();
 NumericVector x = RcppDeepState_NumericVector ();
  x_stream.open("/home/akhila/Documents/compileAttributescheck/AGread/inst/testfiles/get_VM_C/inputs/ x");
 x_stream<< x;
std::cout <<"x values: "<< x << std::endl;
 x_stream.close();
 NumericVector y = RcppDeepState_NumericVector ();
  y_stream.open("/home/akhila/Documents/compileAttributescheck/AGread/inst/testfiles/get_VM_C/inputs/ y");
 y_stream<< y;
std::cout <<"y values: "<< y << std::endl;
 y_stream.close();
 NumericVector z = RcppDeepState_NumericVector ();
  z_stream.open("/home/akhila/Documents/compileAttributescheck/AGread/inst/testfiles/get_VM_C/inputs/ z");
 z_stream<< z;
std::cout <<"z values: "<< z << std::endl;
 z_stream.close();
 try{
get_VM_C( x, y, z);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
