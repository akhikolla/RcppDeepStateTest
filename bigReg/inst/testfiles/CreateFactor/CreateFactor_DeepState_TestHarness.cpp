#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 SEXP CreateFactor(NumericVector x, CharacterVector levels);
TEST(bigReg_deepstate_test,CreateFactor_test){
std::ofstream  x_stream;
std::ofstream  levels_stream;
RInside();
std::cout << "input starts" << std::endl;
 NumericVector x = RcppDeepState_NumericVector ();
  x_stream.open("/home/akhila/Documents/compileAttributescheck/bigReg/inst/testfiles/CreateFactor/inputs/ x");
 x_stream<< x;
std::cout <<"x values: "<< x << std::endl;
 x_stream.close();
 CharacterVector levels = RcppDeepState_CharacterVector ();
  levels_stream.open("/home/akhila/Documents/compileAttributescheck/bigReg/inst/testfiles/CreateFactor/inputs/ levels");
 levels_stream<< levels;
std::cout <<"levels values: "<< levels << std::endl;
 levels_stream.close();
 std::cout << "input ends" << std::endl;
 try{
CreateFactor( x, levels);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
