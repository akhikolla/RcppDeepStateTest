#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 double log1pExp(double x);
TEST(BayesFactor_deepstate_test,log1pExp_test){
std::ofstream  x_stream;
RInside();
std::cout << "input starts" << std::endl;
 double x = RcppDeepState_double ();
  x_stream.open("/home/akhila/Documents/compileAttributescheck/BayesFactor/inst/testfiles/log1pExp/inputs/ x");
 x_stream<< x;
std::cout <<"x values: "<< x << std::endl;
 x_stream.close();
 std::cout << "input ends" << std::endl;
 try{
log1pExp( x);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
