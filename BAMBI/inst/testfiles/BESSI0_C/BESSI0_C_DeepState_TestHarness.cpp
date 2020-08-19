#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 double BESSI0_C(double x);
TEST(BAMBI_deepstate_test,BESSI0_C_test){
std::ofstream  x_stream;
 RInside();
 double x = RcppDeepState_double ();
  x_stream.open("/home/akhila/Documents/compileAttributescheck/BAMBI/inst/testfiles/BESSI0_C/inputs/ x");
 x_stream<< x;
std::cout <<"x values: "<< x << std::endl;
 x_stream.close();
 std::cout << "input ends" << std::endl;
 try{
BESSI0_C( x);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
