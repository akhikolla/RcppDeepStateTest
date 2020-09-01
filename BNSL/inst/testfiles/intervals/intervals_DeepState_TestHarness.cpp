#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 NumericVector intervals(int level, NumericVector array);
TEST(BNSL_deepstate_test,intervals_test){
std::ofstream  level_stream;
std::ofstream  array_stream;
RInside();
std::cout << "input starts" << std::endl;
 int level = RcppDeepState_int ();
  level_stream.open("/home/akhila/Documents/compileAttributescheck/BNSL/inst/testfiles/intervals/inputs/ level");
 level_stream<< level;
std::cout <<"level values: "<< level << std::endl;
 level_stream.close();
 NumericVector array = RcppDeepState_NumericVector ();
  array_stream.open("/home/akhila/Documents/compileAttributescheck/BNSL/inst/testfiles/intervals/inputs/ array");
 array_stream<< array;
std::cout <<"array values: "<< array << std::endl;
 array_stream.close();
 std::cout << "input ends" << std::endl;
 try{
intervals( level, array);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
