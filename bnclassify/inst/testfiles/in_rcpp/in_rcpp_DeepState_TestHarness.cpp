#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 bool in_rcpp(CharacterVector element, CharacterVector vector);
TEST(bnclassify_deepstate_test,in_rcpp_test){
std::ofstream  element_stream;
std::ofstream  vector_stream;
RInside();
std::cout << "input starts" << std::endl;
 CharacterVector element = RcppDeepState_CharacterVector ();
  element_stream.open("/home/akhila/Documents/compileAttributescheck/bnclassify/inst/testfiles/in_rcpp/inputs/ element");
 element_stream<< element;
std::cout <<"element values: "<< element << std::endl;
 element_stream.close();
 CharacterVector vector = RcppDeepState_CharacterVector ();
  vector_stream.open("/home/akhila/Documents/compileAttributescheck/bnclassify/inst/testfiles/in_rcpp/inputs/ vector");
 vector_stream<< vector;
std::cout <<"vector values: "<< vector << std::endl;
 vector_stream.close();
 std::cout << "input ends" << std::endl;
 try{
in_rcpp( element, vector);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
