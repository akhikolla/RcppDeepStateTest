#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 LogicalVector within_rcpp(NumericVector x, int a, int b);
TEST(amt_deepstate_test,within_rcpp_test){
std::ofstream  x_stream;
std::ofstream  a_stream;
std::ofstream  b_stream;
 RInside();
 NumericVector x = RcppDeepState_NumericVector ();
  x_stream.open("/home/akhila/Documents/compileAttributescheck/amt/inst/testfiles/within_rcpp/inputs/ x");
 x_stream<< x;
std::cout <<"x values: "<< x << std::endl;
 x_stream.close();
 int a = RcppDeepState_int ();
  a_stream.open("/home/akhila/Documents/compileAttributescheck/amt/inst/testfiles/within_rcpp/inputs/ a");
 a_stream<< a;
std::cout <<"a values: "<< a << std::endl;
 a_stream.close();
 int b = RcppDeepState_int ();
  b_stream.open("/home/akhila/Documents/compileAttributescheck/amt/inst/testfiles/within_rcpp/inputs/ b");
 b_stream<< b;
std::cout <<"b values: "<< b << std::endl;
 b_stream.close();
 std::cout << "input ends" << std::endl;
 try{
within_rcpp( x, a, b);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
