#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 int whichmax(NumericVector x, int start);
TEST(aphid_deepstate_test,whichmax_test){
std::ofstream  x_stream;
std::ofstream  start_stream;
 RInside();
 NumericVector x = RcppDeepState_NumericVector ();
  x_stream.open("/home/akhila/Documents/compileAttributescheck/aphid/inst/testfiles/whichmax/inputs/ x");
 x_stream<< x;
std::cout <<"x values: "<< x << std::endl;
 x_stream.close();
 int start = RcppDeepState_int ();
  start_stream.open("/home/akhila/Documents/compileAttributescheck/aphid/inst/testfiles/whichmax/inputs/ start");
 start_stream<< start;
std::cout <<"start values: "<< start << std::endl;
 start_stream.close();
 std::cout << "input ends" << std::endl;
 try{
whichmax( x, start);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
