#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 double logExpXplusExpY(const double x, const double y);
TEST(BayesFactor_deepstate_test,logExpXplusExpY_test){
std::ofstream  x_stream;
std::ofstream  y_stream;
RInside();
std::cout << "input starts" << std::endl;
  double x = RcppDeepState_double ();
  x_stream.open("/home/akhila/Documents/compileAttributescheck/BayesFactor/inst/testfiles/logExpXplusExpY/inputs/ x");
 x_stream<< x;
std::cout <<"x values: "<< x << std::endl;
 x_stream.close();
  double y = RcppDeepState_double ();
  y_stream.open("/home/akhila/Documents/compileAttributescheck/BayesFactor/inst/testfiles/logExpXplusExpY/inputs/ y");
 y_stream<< y;
std::cout <<"y values: "<< y << std::endl;
 y_stream.close();
 std::cout << "input ends" << std::endl;
 try{
logExpXplusExpY( x, y);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
