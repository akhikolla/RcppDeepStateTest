#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 int binary_search(NumericVector array, double pattern);
TEST(BNSL_deepstate_test,binary_search_test){
std::ofstream  array_stream;
std::ofstream  pattern_stream;
RInside();
std::cout << "input starts" << std::endl;
 NumericVector array = RcppDeepState_NumericVector ();
  array_stream.open("/home/akhila/Documents/compileAttributescheck/BNSL/inst/testfiles/binary_search/inputs/ array");
 array_stream<< array;
std::cout <<"array values: "<< array << std::endl;
 array_stream.close();
 double pattern = RcppDeepState_double ();
  pattern_stream.open("/home/akhila/Documents/compileAttributescheck/BNSL/inst/testfiles/binary_search/inputs/ pattern");
 pattern_stream<< pattern;
std::cout <<"pattern values: "<< pattern << std::endl;
 pattern_stream.close();
 std::cout << "input ends" << std::endl;
 try{
binary_search( array, pattern);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
