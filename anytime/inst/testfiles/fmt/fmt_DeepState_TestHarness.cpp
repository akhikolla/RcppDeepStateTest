#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 std::vector<std::string> fmt(Rcpp::NumericVector x);
TEST(anytime_deepstate_test,fmt_test){
std::ofstream  x_stream;
 RInside();
 NumericVector x = RcppDeepState_NumericVector ();
  x_stream.open("/home/akhila/Documents/compileAttributescheck/anytime/inst/testfiles/fmt/inputs/ x");
 x_stream<< x;
std::cout <<"x values: "<< x << std::endl;
 x_stream.close();
 std::cout << "input ends" << std::endl;
 try{
fmt( x);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
