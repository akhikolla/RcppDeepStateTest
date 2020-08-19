#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 void removeFormats(Rcpp::CharacterVector fmt);
TEST(anytime_deepstate_test,removeFormats_test){
std::ofstream  fmt_stream;
 RInside();
 CharacterVector fmt = RcppDeepState_CharacterVector ();
  fmt_stream.open("/home/akhila/Documents/compileAttributescheck/anytime/inst/testfiles/removeFormats/inputs/ fmt");
 fmt_stream<< fmt;
std::cout <<"fmt values: "<< fmt << std::endl;
 fmt_stream.close();
 std::cout << "input ends" << std::endl;
 try{
removeFormats( fmt);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
