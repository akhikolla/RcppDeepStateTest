#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 LogicalVector is_constant(NumericVector x);
TEST(adeba_deepstate_test,is_constant_test){
std::ofstream  x_stream;
 RInside();
 NumericVector x = RcppDeepState_NumericVector ();
  x_stream.open("/home/akhila/Documents/compileAttributescheck/adeba/inst/testfiles/is_constant/inputs/ x");
 x_stream<< x;
std::cout <<"x values: "<< x << std::endl;
 x_stream.close();
 try{
is_constant( x);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
