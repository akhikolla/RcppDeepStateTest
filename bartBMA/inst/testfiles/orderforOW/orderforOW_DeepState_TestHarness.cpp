#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 IntegerVector orderforOW(NumericVector x);
TEST(bartBMA_deepstate_test,orderforOW_test){
std::ofstream  x_stream;
 RInside();
 NumericVector x = RcppDeepState_NumericVector ();
  x_stream.open("/home/akhila/Documents/compileAttributescheck/bartBMA/inst/testfiles/orderforOW/inputs/ x");
 x_stream<< x;
std::cout <<"x values: "<< x << std::endl;
 x_stream.close();
 std::cout << "input ends" << std::endl;
 try{
orderforOW( x);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
