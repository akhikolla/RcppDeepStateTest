#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 double Jeffreys_mi(NumericVector x, NumericVector y, int m_x, int m_y);
TEST(BNSL_deepstate_test,Jeffreys_mi_test){
std::ofstream  x_stream;
std::ofstream  y_stream;
std::ofstream  m_x_stream;
std::ofstream  m_y_stream;
RInside();
std::cout << "input starts" << std::endl;
 NumericVector x = RcppDeepState_NumericVector ();
  x_stream.open("/home/akhila/Documents/compileAttributescheck/BNSL/inst/testfiles/Jeffreys_mi/inputs/ x");
 x_stream<< x;
std::cout <<"x values: "<< x << std::endl;
 x_stream.close();
 NumericVector y = RcppDeepState_NumericVector ();
  y_stream.open("/home/akhila/Documents/compileAttributescheck/BNSL/inst/testfiles/Jeffreys_mi/inputs/ y");
 y_stream<< y;
std::cout <<"y values: "<< y << std::endl;
 y_stream.close();
 int m_x = RcppDeepState_int ();
  m_x_stream.open("/home/akhila/Documents/compileAttributescheck/BNSL/inst/testfiles/Jeffreys_mi/inputs/ m_x");
 m_x_stream<< m_x;
std::cout <<"m_x values: "<< m_x << std::endl;
 m_x_stream.close();
 int m_y = RcppDeepState_int ();
  m_y_stream.open("/home/akhila/Documents/compileAttributescheck/BNSL/inst/testfiles/Jeffreys_mi/inputs/ m_y");
 m_y_stream<< m_y;
std::cout <<"m_y values: "<< m_y << std::endl;
 m_y_stream.close();
 std::cout << "input ends" << std::endl;
 try{
Jeffreys_mi( x, y, m_x, m_y);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
