#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 std::vector<std::string> ordersetdiff(CharacterVector vector, CharacterVector remove);
TEST(bnclassify_deepstate_test,ordersetdiff_test){
std::ofstream  vector_stream;
std::ofstream  remove_stream;
RInside();
std::cout << "input starts" << std::endl;
 CharacterVector vector = RcppDeepState_CharacterVector ();
  vector_stream.open("/home/akhila/Documents/compileAttributescheck/bnclassify/inst/testfiles/ordersetdiff/inputs/ vector");
 vector_stream<< vector;
std::cout <<"vector values: "<< vector << std::endl;
 vector_stream.close();
 CharacterVector remove = RcppDeepState_CharacterVector ();
  remove_stream.open("/home/akhila/Documents/compileAttributescheck/bnclassify/inst/testfiles/ordersetdiff/inputs/ remove");
 remove_stream<< remove;
std::cout <<"remove values: "<< remove << std::endl;
 remove_stream.close();
 std::cout << "input ends" << std::endl;
 try{
ordersetdiff( vector, remove);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
