#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 double Jeffreys_cmi(NumericVector x, NumericVector y, NumericVector z, int m_x, int m_y, int m_z);
TEST(BNSL_deepstate_test,Jeffreys_cmi_test){
std::ofstream  x_stream;
std::ofstream  y_stream;
std::ofstream  z_stream;
std::ofstream  m_x_stream;
std::ofstream  m_y_stream;
std::ofstream  m_z_stream;
RInside();
std::cout << "input starts" << std::endl;
 NumericVector x = RcppDeepState_NumericVector ();
  x_stream.open("/home/akhila/Documents/compileAttributescheck/BNSL/inst/testfiles/Jeffreys_cmi/inputs/ x");
 x_stream<< x;
std::cout <<"x values: "<< x << std::endl;
 x_stream.close();
 NumericVector y = RcppDeepState_NumericVector ();
  y_stream.open("/home/akhila/Documents/compileAttributescheck/BNSL/inst/testfiles/Jeffreys_cmi/inputs/ y");
 y_stream<< y;
std::cout <<"y values: "<< y << std::endl;
 y_stream.close();
 NumericVector z = RcppDeepState_NumericVector ();
  z_stream.open("/home/akhila/Documents/compileAttributescheck/BNSL/inst/testfiles/Jeffreys_cmi/inputs/ z");
 z_stream<< z;
std::cout <<"z values: "<< z << std::endl;
 z_stream.close();
 int m_x = RcppDeepState_int ();
  m_x_stream.open("/home/akhila/Documents/compileAttributescheck/BNSL/inst/testfiles/Jeffreys_cmi/inputs/ m_x");
 m_x_stream<< m_x;
std::cout <<"m_x values: "<< m_x << std::endl;
 m_x_stream.close();
 int m_y = RcppDeepState_int ();
  m_y_stream.open("/home/akhila/Documents/compileAttributescheck/BNSL/inst/testfiles/Jeffreys_cmi/inputs/ m_y");
 m_y_stream<< m_y;
std::cout <<"m_y values: "<< m_y << std::endl;
 m_y_stream.close();
 int m_z = RcppDeepState_int ();
  m_z_stream.open("/home/akhila/Documents/compileAttributescheck/BNSL/inst/testfiles/Jeffreys_cmi/inputs/ m_z");
 m_z_stream<< m_z;
std::cout <<"m_z values: "<< m_z << std::endl;
 m_z_stream.close();
 std::cout << "input ends" << std::endl;
 try{
Jeffreys_cmi( x, y, z, m_x, m_y, m_z);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
