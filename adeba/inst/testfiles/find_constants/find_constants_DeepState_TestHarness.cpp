#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 LogicalVector find_constants(NumericMatrix x);
TEST(adeba_deepstate_test,find_constants_test){
std::ofstream  x_stream;
 RInside();
 NumericMatrix x = RcppDeepState_NumericMatrix ();
  x_stream.open("/home/akhila/Documents/compileAttributescheck/adeba/inst/testfiles/find_constants/inputs/ x");
 x_stream<< x;
std::cout <<"x values: "<< x << std::endl;
 x_stream.close();
 try{
find_constants( x);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
