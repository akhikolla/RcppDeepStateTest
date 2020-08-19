#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 IntegerVector acount(IntegerVector x, int arity);
TEST(aphid_deepstate_test,acount_test){
std::ofstream  x_stream;
std::ofstream  arity_stream;
 RInside();
 IntegerVector x = RcppDeepState_IntegerVector ();
  x_stream.open("/home/akhila/Documents/compileAttributescheck/aphid/inst/testfiles/acount/inputs/ x");
 x_stream<< x;
std::cout <<"x values: "<< x << std::endl;
 x_stream.close();
 int arity = RcppDeepState_int ();
  arity_stream.open("/home/akhila/Documents/compileAttributescheck/aphid/inst/testfiles/acount/inputs/ arity");
 arity_stream<< arity;
std::cout <<"arity values: "<< arity << std::endl;
 arity_stream.close();
 std::cout << "input ends" << std::endl;
 try{
acount( x, arity);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
