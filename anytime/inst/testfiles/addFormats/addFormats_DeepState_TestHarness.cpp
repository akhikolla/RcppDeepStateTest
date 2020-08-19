#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 void addFormats(Rcpp::CharacterVector fmt);
TEST(anytime_deepstate_test,addFormats_test){
std::ofstream  fmt_stream;
 RInside();
 CharacterVector fmt = RcppDeepState_CharacterVector ();
  fmt_stream.open("/home/akhila/Documents/compileAttributescheck/anytime/inst/testfiles/addFormats/inputs/ fmt");
 fmt_stream<< fmt;
std::cout <<"fmt values: "<< fmt << std::endl;
 fmt_stream.close();
 std::cout << "input ends" << std::endl;
 try{
addFormats( fmt);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
