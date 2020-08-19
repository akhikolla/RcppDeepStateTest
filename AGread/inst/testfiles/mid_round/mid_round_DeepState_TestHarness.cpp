#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 double mid_round(double input, int digits);
TEST(AGread_deepstate_test,mid_round_test){
std::ofstream  input_stream;
std::ofstream  digits_stream;
 RInside();
 double input = RcppDeepState_double ();
  input_stream.open("/home/akhila/Documents/compileAttributescheck/AGread/inst/testfiles/mid_round/inputs/ input");
 input_stream<< input;
std::cout <<"input values: "<< input << std::endl;
 input_stream.close();
 int digits = RcppDeepState_int ();
  digits_stream.open("/home/akhila/Documents/compileAttributescheck/AGread/inst/testfiles/mid_round/inputs/ digits");
 digits_stream<< digits;
std::cout <<"digits values: "<< digits << std::endl;
 digits_stream.close();
 try{
mid_round( input, digits);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
