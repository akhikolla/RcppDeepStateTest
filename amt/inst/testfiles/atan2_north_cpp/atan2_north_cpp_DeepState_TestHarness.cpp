#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 double atan2_north_cpp(double y, double x);
TEST(amt_deepstate_test,atan2_north_cpp_test){
std::ofstream  y_stream;
std::ofstream  x_stream;
 RInside();
 double y = RcppDeepState_double ();
  y_stream.open("/home/akhila/Documents/compileAttributescheck/amt/inst/testfiles/atan2_north_cpp/inputs/ y");
 y_stream<< y;
std::cout <<"y values: "<< y << std::endl;
 y_stream.close();
 double x = RcppDeepState_double ();
  x_stream.open("/home/akhila/Documents/compileAttributescheck/amt/inst/testfiles/atan2_north_cpp/inputs/ x");
 x_stream<< x;
std::cout <<"x values: "<< x << std::endl;
 x_stream.close();
 std::cout << "input ends" << std::endl;
 try{
atan2_north_cpp( y, x);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
