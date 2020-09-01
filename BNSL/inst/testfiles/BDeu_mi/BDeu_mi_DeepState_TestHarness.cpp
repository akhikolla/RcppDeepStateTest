#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 double BDeu_mi(NumericVector x, NumericVector y, int m_x, int m_y, double d);
TEST(BNSL_deepstate_test,BDeu_mi_test){
std::ofstream  x_stream;
std::ofstream  y_stream;
std::ofstream  m_x_stream;
std::ofstream  m_y_stream;
std::ofstream  d_stream;
RInside();
std::cout << "input starts" << std::endl;
 NumericVector x = RcppDeepState_NumericVector ();
  x_stream.open("/home/akhila/Documents/compileAttributescheck/BNSL/inst/testfiles/BDeu_mi/inputs/ x");
 x_stream<< x;
std::cout <<"x values: "<< x << std::endl;
 x_stream.close();
 NumericVector y = RcppDeepState_NumericVector ();
  y_stream.open("/home/akhila/Documents/compileAttributescheck/BNSL/inst/testfiles/BDeu_mi/inputs/ y");
 y_stream<< y;
std::cout <<"y values: "<< y << std::endl;
 y_stream.close();
 int m_x = RcppDeepState_int ();
  m_x_stream.open("/home/akhila/Documents/compileAttributescheck/BNSL/inst/testfiles/BDeu_mi/inputs/ m_x");
 m_x_stream<< m_x;
std::cout <<"m_x values: "<< m_x << std::endl;
 m_x_stream.close();
 int m_y = RcppDeepState_int ();
  m_y_stream.open("/home/akhila/Documents/compileAttributescheck/BNSL/inst/testfiles/BDeu_mi/inputs/ m_y");
 m_y_stream<< m_y;
std::cout <<"m_y values: "<< m_y << std::endl;
 m_y_stream.close();
 double d = RcppDeepState_double ();
  d_stream.open("/home/akhila/Documents/compileAttributescheck/BNSL/inst/testfiles/BDeu_mi/inputs/ d");
 d_stream<< d;
std::cout <<"d values: "<< d << std::endl;
 d_stream.close();
 std::cout << "input ends" << std::endl;
 try{
BDeu_mi( x, y, m_x, m_y, d);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
