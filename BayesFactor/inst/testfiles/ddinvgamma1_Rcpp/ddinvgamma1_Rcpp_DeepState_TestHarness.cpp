#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 double ddinvgamma1_Rcpp(const double x, const double a, const double b);
TEST(BayesFactor_deepstate_test,ddinvgamma1_Rcpp_test){
std::ofstream  x_stream;
std::ofstream  a_stream;
std::ofstream  b_stream;
RInside();
std::cout << "input starts" << std::endl;
  double x = RcppDeepState_double ();
  x_stream.open("/home/akhila/Documents/compileAttributescheck/BayesFactor/inst/testfiles/ddinvgamma1_Rcpp/inputs/ x");
 x_stream<< x;
std::cout <<"x values: "<< x << std::endl;
 x_stream.close();
  double a = RcppDeepState_double ();
  a_stream.open("/home/akhila/Documents/compileAttributescheck/BayesFactor/inst/testfiles/ddinvgamma1_Rcpp/inputs/ a");
 a_stream<< a;
std::cout <<"a values: "<< a << std::endl;
 a_stream.close();
  double b = RcppDeepState_double ();
  b_stream.open("/home/akhila/Documents/compileAttributescheck/BayesFactor/inst/testfiles/ddinvgamma1_Rcpp/inputs/ b");
 b_stream<< b;
std::cout <<"b values: "<< b << std::endl;
 b_stream.close();
 std::cout << "input ends" << std::endl;
 try{
ddinvgamma1_Rcpp( x, a, b);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
